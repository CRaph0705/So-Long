/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcochran <rcochran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 17:46:40 by rcochran          #+#    #+#             */
/*   Updated: 2025/03/27 15:02:23 by rcochran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	display_map_grid(t_map *map);
void	display_map(t_map *map);


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

