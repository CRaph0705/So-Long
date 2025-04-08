/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validity_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcochran <rcochran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 17:12:40 by rcochran          #+#    #+#             */
/*   Updated: 2025/04/07 18:45:40 by rcochran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void		count_other_elements(t_map *map, int *other_count);
int			is_valid_char(char c);

int	is_valid_char(char c)
{
	return (c == 'P' || c == 'E' || c == 'C' || c == '0' || c == '1'
		|| c == 'B');
}

void	count_other_elements(t_map *map, int *other_count)
{
	int	y;
	int	x;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (!is_valid_char(map->grid[y][x]))
			{
				(*other_count)++;
				return ;
			}
			x++;
		}
		y++;
	}
}

int	valid_filename(char *file_name)
{
	file_name = file_name + (ft_strlen(file_name) - 4);
	return (ft_strncmp(file_name, ".ber", 4) == 0);
}

int	is_map_too_big(int map_width, int map_height)
{
	if (map_width > MAX_MAP_WIDTH || map_height > MAX_MAP_HEIGHT)
	{
		ft_printf(INVALID_MAP_5, MAX_MAP_WIDTH, MAX_MAP_HEIGHT);
		return (1);
	}
	return (0);
}
