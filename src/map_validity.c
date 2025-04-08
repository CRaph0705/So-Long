/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validity.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcochran <rcochran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 20:14:59 by rcochran          #+#    #+#             */
/*   Updated: 2025/04/07 18:46:25 by rcochran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int			check_map_validity(t_map *map);
static int	valid_borders(t_map *map);
static int	valid_elements(t_map *map);
static int	map_is_rectangular(t_map *map);
static void	count_elements(t_map *map, int *player_count,
				int *exit_count, int *collectible_count);

int	check_map_validity(t_map *map)
{
	if (!map)
		return (0);
	if (!map_is_rectangular(map) || !valid_borders(map) || !valid_elements(map))
		return (0);
	if (is_map_too_big(map->width, map->height))
		return (0);
	if (!valid_path(map))
		return (0);
	return (1);
}

static int	valid_borders(t_map *map)
{
	int		y;
	int		x;
	char	c;

	y = 0;
	while (y < map->height)
	{
		x = 0;
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
	int	length;

	y = 0;
	length = ft_strlen(map->grid[y]);
	while (map->grid[y] != NULL)
	{
		if ((int)ft_strlen(map->grid[y]) != length)
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
	int		other_count;

	player_count = 0;
	exit_count = 0;
	collectible_count = 0;
	other_count = 0;
	count_elements(map, &player_count, &exit_count, &collectible_count);
	count_other_elements(map, &other_count);
	if (player_count != 1 || exit_count != 1 || collectible_count == 0)
		return (display_error(INVALID_ELEM_1), 0);
	if (other_count != 0)
		return (display_error(INVALID_ELEM_2), 0);
	map->collectible_count = collectible_count;
	return (1);
}
