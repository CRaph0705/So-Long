/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validity_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcochran <rcochran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 17:12:40 by rcochran          #+#    #+#             */
/*   Updated: 2025/03/19 17:55:24 by rcochran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void		count_other_elements(t_map *map, int *other_count);
int			is_valid_char(char c);

/* TODO : ADD BONUS CHAR IN VALID CHAR LIST BELOW */
int	is_valid_char(char c)
{
	return (c == 'P' || c == 'E' || c == 'C' || c == '0' || c == '1');
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
