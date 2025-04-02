/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinding.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcochran <rcochran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 23:40:48 by rcochran          #+#    #+#             */
/*   Updated: 2025/04/02 13:35:06 by rcochran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int			valid_path(t_map *map);
static	t_map	*dup_map(t_map *map);
static	void	flood_fill(t_map *map, int x, int y);
static int	is_filled(t_map *map);

static t_map	*dup_map(t_map *map)
{
	t_map	*new_map;
	int		i;
	int		map_h;

	map_h = map->height;
	new_map = malloc(sizeof(t_map));
	if (!new_map)
		return (display_error(INVALID_MAP_3), NULL);
	i = 0;
	new_map->grid = ft_calloc(map_h, sizeof(char *) + 1);
	while (map->grid[i])
	{
		new_map->grid[i] = strdup(map->grid[i]);
		i++;
	}
	new_map->collectible_count = 0;
	new_map->grid[i] = NULL;
	new_map->height = map_h;
	new_map->width = map->width;
	new_map->baddies = map->baddies;
	return (new_map);
}

int	valid_path(t_map *src_map)
{
	t_map	*tmp_map;
	int		valid;

	valid = 1;
	if (!src_map)
		return (display_error(INVALID_MAP_4), 0);
	tmp_map = dup_map(src_map);
	if (!tmp_map)
		return (display_error(INVALID_MAP_3), 0);
	flood_fill(tmp_map, src_map->player_pos_x, src_map->player_pos_y);
	valid = is_filled(tmp_map);
	if (!valid)
		return (free_map(tmp_map), display_error(INVALID_MAP_2), 0);
	src_map->exit_x = tmp_map->exit_x;
	src_map->exit_y = tmp_map->exit_y;
	return (free_map(tmp_map), 1);
}

static int	is_filled(t_map *map)
{
	int		y;
	int		x;
	int		valid;

	valid = 1;
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (map->grid[y][x] == 'E' || map->grid[y][x] == 'C')
			{
				valid = 0;
				break ;
			}
			x++;
		}
		y++;
	}
	return (valid);
}

static void	flood_fill(t_map *map, int x, int y)
{
	if (x < 0 || x >= map->width || y < 0 || y >= map->height)
		return ;
	if (map->grid[y][x] == '1' || map->grid[y][x] == 'F')
		return ;
	if (map->grid[y][x] == 'C')
		map->collectible_count++;
	if (map->grid[y][x] == 'E')
	{
		map->exit_x = x;
		map->exit_y = y;
	}
	map->grid[y][x] = 'F';
	flood_fill(map, x + 1, y);
	flood_fill(map, x - 1, y);
	flood_fill(map, x, y + 1);
	flood_fill(map, x, y - 1);
}
