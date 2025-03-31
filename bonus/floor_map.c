/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcochran <rcochran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 10:17:55 by rcochran          #+#    #+#             */
/*   Updated: 2025/03/31 10:41:58 by rcochran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	free_l_floor_map(t_game *game, int limit);
int		alloc_floor_map(t_game *game);
void	fill_floor_map(t_game *game);
void	init_floor_map(t_game *game);

void	free_l_floor_map(t_game *game, int limit)
{
	int	i;

	i = 0;
	while (i < limit)
	{
		free(game->map->floor_start[i]);
		i++;
	}
	free(game->map->floor_start);
}

int	alloc_floor_map(t_game *game)
{
	int	y;

	game->map->floor_start = malloc(sizeof(void **) * game->map->height);
	if (!game->map->floor_start)
		return (0);
	y = 0;
	while (y < game->map->height)
	{
		game->map->floor_start[y] = malloc(sizeof(void *) * game->map->width);
		if (!game->map->floor_start[y])
			return (free_l_floor_map(game, y), 0);
		y++;
	}
	return (1);
}

void	fill_floor_map(t_game *game)
{
	int		y;
	int		x;
	char	tile;

	y = 0;
	while (y < game->map->height)
	{
		x = 0;
		while (x < game->map->width)
		{
			tile = game->map->grid[y][x];
			if (tile == '0' || tile == 'P' || tile == 'C' || tile == 'B')
				game->map->floor_start[y][x] = get_random_floor(game);
			else if (tile == 'E')
				game->map->floor_start[y][x] = game->exit_closed;
			else
				game->map->floor_start[y][x] = NULL;
			x++;
		}
		y++;
	}
}

void	init_floor_map(t_game *game)
{
	if (!alloc_floor_map(game))
		return ;
	fill_floor_map(game);
}
