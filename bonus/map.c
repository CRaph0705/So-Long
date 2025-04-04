/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcochran <rcochran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 19:11:15 by rcochran          #+#    #+#             */
/*   Updated: 2025/04/04 21:02:47 by rcochran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

t_map		*parse_map(char *map_name);
void		fill_map(t_map *new_map, int fd);
int			check_map_validity(t_map *map);
void		free_map(t_map *map);
int			get_map_h(char *map_name);

t_map	*parse_map(char *map_name)
{
	t_map	*new_map;
	int		fd;

	new_map = NULL;
	if (valid_filename(map_name) == 0)
		return (display_error(INVALID_FILE), NULL);
	new_map = malloc(sizeof(t_map));
	if (!new_map)
		return (display_error(PARSE_ERROR_2), NULL);
	new_map->grid = NULL;
	// new_map->grid = ft_realloc(new_map->grid,
	// 		sizeof(char *) * (new_map->height + 1));
	// if (!new_map->grid)
		// return (display_error(PARSE_ERROR_4), NULL);
	new_map->height = get_map_h(map_name);
	if (new_map->height == -1)
		return (display_error(PARSE_ERROR_1), NULL);
	fd = open(map_name, O_RDONLY);
	if (fd == -1)
		return (display_error(PARSE_ERROR_1), NULL);
	new_map->baddies = NULL;
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
	if (!line || !map)
	{
		(close(fd), display_error(EMPTY_MAP_FILE));
		return ;
	}
	map->grid = ft_calloc(sizeof(char *), map->height + 1);
	if (!map->grid)
		return ;
	while (line != NULL)
	{
		map->grid[i] = ft_strtrim(line, "\n");
		if (i == 0)
			map->width = (int)(ft_strlen(map->grid[i]));
		free(line);
		i++;
		line = get_next_line(fd);
	}
	map->collected_count = 0;
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
	if (map->baddies)
		free_baddies(map);
	free(map);
}

int	get_map_h(char *map_name)
{
	int		fd;
	int		i;
	char	*line;

	i = 0;
	fd = open(map_name, O_RDONLY);
	if (fd == -1)
		return (-1);
	line = get_next_line(fd);
	if (!line)
		return (close(fd), -1);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		i++;
	}
	free(line);
	close(fd);
	return (i);
}