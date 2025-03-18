/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcochran <rcochran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 19:11:15 by rcochran          #+#    #+#             */
/*   Updated: 2025/03/19 00:24:58 by rcochran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
// parse map

/* The map has to be constructed with 3 components: 
walls, collectibles, and free space. */

/* TODO The map can be composed of only these 5 characters:
0 for an empty space,
1 for a wall,
C for a collectible,
E for a map exit,
P for the player’s starting position */

/* TODO The map must contain 1 exit, at least 1 collectible,
and 1 starting position to be valid. */

/* TODO The map must be rectangular. */

/* TODO The map must be closed/surrounded by walls.
If it’s not, the program must return an error. */

/* TODO You have to check if there’s a valid path in the map. */

/* • You must be able to parse any kind of map,
as long as it respects the above rules. */

/* If any misconfiguration of any kind is encountered in the file,
the program must exit in a clean way,
and return "Error\n" followed by an
TODO explicit error message
of your choice. */

t_map		*parse_map(char *map_name);
void		fill_map(t_map *new_map, int fd);

int			check_map_validity(t_map *map);

void		free_map(t_map *map);

t_map	*parse_map(char *map_name)
{
	t_map	*new_map;
	int		fd;

	fd = open(map_name, O_RDONLY);
	if (fd == -1)
	{
		return (display_error(PARSE_ERROR_1), NULL);
	}
	new_map = malloc(sizeof(t_map));
	if (!new_map)
		return (display_error(PARSE_ERROR_2), NULL);
	new_map->grid = NULL;
	new_map->height = 0;
	fill_map(new_map, fd);
	if (check_map_validity(new_map) == 0)
		return (display_error(PARSE_ERROR_3), NULL);
	return (new_map);
}

void	fill_map(t_map *map, int fd)
{
	int		i;
	char	*line;
//TODO
//DEBUG
	i = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (map->width == 0)
			map->width = (int)ft_strlen(line);
		map->height++;
		map->grid = ft_realloc(map->grid, sizeof(char *) * (map->height + 1));
		map->grid[i] = line;
		i++;
		free(line);
		line = get_next_line(fd);
	}
	map->grid[i] = NULL;
	close(fd);
}

void	free_map(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->height)
	{
		free(map->grid[i]);
		i++;
	}
	free(map->grid);
	free(map);
}
