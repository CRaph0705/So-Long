/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcochran <rcochran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 17:50:58 by rcochran          #+#    #+#             */
/*   Updated: 2025/03/27 11:46:17 by rcochran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
//convert image en xpm 
// <brew || apt> install imagemagick
// convert image.png image.xpm

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *) dst = color;
}

/* void	put_square(t_data *data, int x, int y, int color)
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
} */

int	main(int ac, char **av)
{
	char	*map_name;
	t_map	*map;
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	if (ac < 2)
		return (ft_printf("Usage : ./so_long assets/maps/<name>\n"), 1);
	map_name = av[1];
	map = parse_map(map_name);
	if (!map)
		return (ft_printf("main() : Error, no map\n"));
	if (!check_map_validity(map))
		return (free_map(map), 1);
	ft_printf("map OK ✅\n");
	ft_printf("free OK ✅\n");
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, map->width * 32, map->height * 32, "Hello world!");
	img.img = mlx_new_image(mlx, map->width * 32, map->height * 32);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
		&img.endian);
		// my_mlx_pixel_put(&img, 5, 5, 0x00FFFFFF);
		// my_mlx_pixel_put(&img, 15, 5, 0x00FFFFFF);
		// my_mlx_pixel_put(&img, 5, 15, 0x00FFFFFF);
		// my_mlx_pixel_put(&img, 15, 15, 0x00FFFFFF);
		put_square(&img, 16, 16, 0x00FFFFFF);
		mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
		mlx_loop(mlx);
	free_map(map);
	return (0);
}

//void	*mlx_xpm_file_to_image(t_xvar *xvar,char *file,int *width,int *height);
//void	*mlx_xpm_file_to_image(t_xvar *mlx,char * <path_to_img>,int *width,int *height)
// mlx_put_image_to_window