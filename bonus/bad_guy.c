/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bad_guy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcochran <rcochran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 15:02:16 by rcochran          #+#    #+#             */
/*   Updated: 2025/04/01 11:29:58 by rcochran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void		init_map_baddies(t_map *map);
int			move_baddies(t_game *game);
void		move_baddy(t_bad_guy *bad_guy, t_game *game);

void	init_map_baddies(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (map->grid[y][x] == 'B')
				add_bad_guy(map, y, x);
			x++;
		}
		y++;
	}
}

void	move_baddy(t_bad_guy *bad_guy, t_game *game)
{
	int		new_y;
	int		new_x;
	char	next_pos;

	if (!bad_guy)
		return ;
	new_x = bad_guy->pos_x;
	new_y = bad_guy->pos_y;
	if (rand() % 2 == 0)
		new_x += (rand() % 3 - 1);
	else
		new_y += (rand() % 3 - 1);
	next_pos = game->map->grid[new_y][new_x];
	if (next_pos == 'E' || next_pos == '1'
		|| next_pos == 'B' || next_pos == 'C')
		ft_printf("This bad guy won't move this turn.\n");
	if (next_pos == 'P')
		defeat_trigger(game);
	if (next_pos == '0')
	{
		restore_tile(game, bad_guy->pos_x, bad_guy->pos_y);
		set_bad_buy_pos(bad_guy, new_x, new_y);
		game->map->grid[new_y][new_x] = 'B';
		render_tile(game, bad_guy->pos_x, bad_guy->pos_y);
	}
}

int	move_baddies(t_game *game)
{
	t_bad_guy	*bad_guy;

	if (!game)
		return (0);
	if (!game->map->baddies)
		return (0);
	bad_guy = game->map->baddies;
	ft_printf("move_baddies()\n");
	while (bad_guy != NULL)
	{
		move_baddy(bad_guy, game);
		bad_guy = bad_guy->next;
	}
	return (1);
}
