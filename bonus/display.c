/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcochran <rcochran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 17:46:40 by rcochran          #+#    #+#             */
/*   Updated: 2025/03/28 17:46:19 by rcochran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	display_map_grid(t_map *map);
void	display_map(t_map *map);
void	display_bad_guy(t_bad_guy *bad_guy);

void	display_map_grid(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->height)
	{
		ft_printf("%s\n", map->grid[i]);
		i++;
	}
	return ;
}

void	display_map(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->height)
	{
		ft_printf("%s\n", map->grid[i]);
		i++;
	}
	return ;
}

void	display_baddies(t_game *game)
{
	t_bad_guy	*baddy;

	if (!game)
		return ;
	if (!game->map->baddies || !(game->map->baddies))
		return ;
	baddy = game->map->baddies;
	ft_printf("display baddies\n");
	while (baddy != NULL)
	{
		display_bad_guy(baddy);
		baddy = baddy->next;
	}
	return ;
}

void	display_bad_guy(t_bad_guy *bad_guy)
{
	ft_printf("baddy->pos_x : %d\n", bad_guy->pos_x);
	ft_printf("baddy->pos_y : %d\n", bad_guy->pos_y);
	ft_printf("\n");
}
