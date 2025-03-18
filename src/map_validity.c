/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validity.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcochran <rcochran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 20:14:59 by rcochran          #+#    #+#             */
/*   Updated: 2025/03/18 23:38:37 by rcochran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#define INVALID_BORDERS "Error: Map must be surrounded by walls\n"
#define INVALID_ELEM "Error: Invalid number of P, E, or C\n"

int			check_map_validity(t_map *map);
static int	valid_borders(t_map *map);
static int	valid_elements(t_map *map);
static int	map_is_rectangular(t_map *map);

int	check_map_validity(t_map *map)
{
	if (!map_is_rectangular(map) || !valid_borders(map) || valid_elements(map))
		return (0);
	return (1);
}

static int	valid_borders(t_map *map)
{
	int		y;
	int		x;
	char	c;

	y = 0;
	x = 0;
	while (y < map->height)
	{
		while (x < map->width)
		{
			c = map->grid[y][x];
			if (y == 0 || y == map->height - 1 || x == 0 || x == map->width - 1)
				if (c != '1')
					return (display_error(INVALID_BORDERS), 0);
			x++;
		}
		y++;
	}
	return (1);
}

static int	map_is_rectangular(t_map *map)
{
	int	y;

	y = 0;
	while (y < map->height)
	{
		if (ft_strlen(map->grid[y]) != map->width)
			return (display_error(INVALID_MAP_1), 0);
		y++;
	}
	return (1);
}

static void	count_elements(t_map *map, int *player_count,
	int *exit_count, int *collectible_count)
{
	int	y;
	int	x;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (map->grid[y][x] == 'P')
			{
				(*player_count)++;
				map->player_pos_x = x;
				map->player_pos_y = y;
			}
			else if (map->grid[y][x] == 'E')
				(*exit_count)++;
			else if (map->grid[y][x] == 'C')
				(*collectible_count)++;
			x++;
		}
		y++;
	}
}

static int	valid_elements(t_map *map)
{
	int		player_count;
	int		exit_count;
	int		collectible_count;

	player_count = 0;
	exit_count = 0;
	collectible_count = 0;
	count_elements(map, &player_count, &exit_count, &collectible_count);
	if (player_count != 1 || exit_count == 0 || collectible_count == 0)
		return (display_error(INVALID_ELEM), 0);
	return (1);
}
