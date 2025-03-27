/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcochran <rcochran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 19:11:15 by rcochran          #+#    #+#             */
/*   Updated: 2025/03/27 22:49:08 by rcochran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_map		*parse_map(char *map_name);
void		fill_map(t_map *new_map, int fd);
int			check_map_validity(t_map *map);
void		free_map(t_map *map);

t_map	*parse_map(char *map_name)
{
	t_map	*new_map;
	int		fd;

	if (valid_filename(map_name) == 0)
		return (display_error(INVALID_FILE), NULL);
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

	i = 0;
	line = get_next_line(fd);
	if (!line)
	{
		(close(fd), display_error(EMPTY_MAP_FILE));
		return ;
	}
	while (line != NULL)
	{
		map->grid = ft_realloc(map->grid, sizeof(char *) * (map->height + 2));
		map->grid[i] = ft_strtrim(line, "\n");
		if (map->height == 0)
			map->width = (int)(ft_strlen(map->grid[i]));
		free(line);
		i++;
		map->height++;
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
