/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcochran <rcochran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 15:02:28 by rcochran          #+#    #+#             */
/*   Updated: 2025/03/27 16:05:10 by rcochran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render(t_game *game);
void	init_window(t_game *game);
void	load_textures(t_game *game);

void	load_textures(t_game *game)
{
	int	w;
	int	h;

	game->wall = mlx_xpm_file_to_image(
			game->mlx, "assets/textures/wall.xpm", &w, &h);
	game->floor = mlx_xpm_file_to_image(
			game->mlx, "assets/textures/floor_00.xpm", &w, &h);
	game->player = mlx_xpm_file_to_image(
			game->mlx, "assets/textures/player.xpm", &w, &h);
	game->exit = mlx_xpm_file_to_image(
			game->mlx, "assets/textures/exit_closed.xpm", &w, &h);
	game->collectible = mlx_xpm_file_to_image(
			game->mlx, "assets/textures/collectible.xpm", &w, &h);
	game->obstacle = mlx_xpm_file_to_image(
			game->mlx, "assets/textures/obstacle.xpm", &w, &h);
}

void	init_window(t_game *game)
{
	game->mlx = mlx_init();
	game->mlx_win = mlx_new_window(
			game->mlx,
			game->map->width * TILE_SIZE,
			game->map->height * TILE_SIZE,
			"test"
			);
	load_textures(game);
}

void	render(t_game *game)
{
	int		y;
	int		x;
	void	*img;

	y = 0;
	while (y < game->map->height)
	{
		x = 0;
		while (x < game->map->width)
		{
			img = game->floor;
			if (game->map->grid[y][x] == '1') //TODO plus tard : randomize avec floor 0, 1, 2, 3
			{
				if (y == 0 || y == game->map->height - 1 || x == 0 || x == game->map->width - 1)
					img = game->wall;
				else
					img = game->obstacle;
			}
			else if (game->map->grid[y][x] == 'P')
				img = game->player; //TODO voir pour transparence avec player et floor_X
			else if (game->map->grid[y][x] == 'E')
				img = game->exit; // TODO là set exit img à closed par défaut et ajouter logique de chgt affichage
			else if (game->map->grid[y][x] == 'C') //TODO voir pour transparence avec collectible et floor_X
				img = game->collectible;
			mlx_put_image_to_window(game->mlx, game->mlx_win, img, x * TILE_SIZE, y * TILE_SIZE);
			x++;
		}
		y++;
	}
}

