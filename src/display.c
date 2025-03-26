/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcochran <rcochran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 17:46:40 by rcochran          #+#    #+#             */
/*   Updated: 2025/03/26 15:44:21 by rcochran         ###   ########.fr       */
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
void	put_square(t_data *data, int x, int y, int color)
{
	int	i;
	int size;
	
	size = 16;
	i = 0;
	while(i <= size)
	{
		my_mlx_pixel_put(data, x + i, y, color);
		my_mlx_pixel_put(data, x, y + i, color);
		my_mlx_pixel_put(data, x + i, y + size, color);
		my_mlx_pixel_put(data, x + size, y + i, color);
		i++;
	}
}

void	put_circle(t_data *data, int x, int y, int color)
{
	int	i;
	int size;
	(void) x;
	size = 16;
	i = 0;
	while(i <= size / 8)
	{
		my_mlx_pixel_put(data, size / 2 - i - 1, y, color);
		my_mlx_pixel_put(data, size / 2 + i, y, color);

		my_mlx_pixel_put(data, size / 2 - i - 1, y + size, color);
		my_mlx_pixel_put(data, size / 2 + i, y + size, color);

		// my_mlx_pixel_put(data, x, size / 2 - i - 1, color);
		// my_mlx_pixel_put(data, x, size / 2 + i, color);

		// my_mlx_pixel_put(data, x + size, size / 2 - i - 1, color);
		// my_mlx_pixel_put(data, x + size , size / 2 + i, color);
		i++;
	}
}