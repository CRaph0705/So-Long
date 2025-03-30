/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bad_guy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcochran <rcochran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 15:02:16 by rcochran          #+#    #+#             */
/*   Updated: 2025/03/28 22:50:47 by rcochran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

t_bad_guy	*new_bad_guy(int y, int x);
void		add_bad_guy(t_map *map, int y, int x);
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

void	add_bad_guy(t_map *map, int y, int x)
{
	t_bad_guy	*new;
	t_bad_guy	*cursor;

	new = new_bad_guy(y, x);
	if (!new)
		return ;
	printf("Ajout d'un bad guy en (%d, %d)\n", x, y);
	if (!map->baddies)
	{
		map->baddies = new;
		return ;
	}
	cursor = map->baddies;
	while (cursor->next)
		cursor = cursor->next;
	cursor->next = new;
}

t_bad_guy	*new_bad_guy(int y, int x)
{
	t_bad_guy	*new_bad_guy;

	new_bad_guy = malloc(sizeof(t_bad_guy));
	if (!new_bad_guy)
		return (NULL);
	new_bad_guy->pos_x = x;
	new_bad_guy->pos_y = y;
	new_bad_guy->next = NULL;
	return (new_bad_guy);
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
	// ignorer les case E et C ? ou passer dessus puis restore tile ?
	if (next_pos == 'E' || next_pos == '1' || next_pos == 'B' || next_pos == 'C')
	{
		ft_printf("this bad guy won't move this turn.\n");
		return ;
	}
	if (next_pos == 'P')
		defeat_trigger(game);
	if (next_pos == '0')
	{
		restore_tile(game, bad_guy->pos_x, bad_guy->pos_y);
		bad_guy->pos_x = new_x;
		bad_guy->pos_y = new_y;
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
