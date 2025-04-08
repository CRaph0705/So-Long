/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcochran <rcochran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 14:52:52 by rcochran          #+#    #+#             */
/*   Updated: 2025/04/08 15:05:09 by rcochran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_props_textures(t_game *game);
void	load_ground_textures(t_game *game);

void	load_props_textures(t_game *game)
{
	int		w;
	int		h;

	game->player = mlx_xpm_file_to_image(
			game->mlx, "assets/textures/player.xpm", &w, &h);
	game->collectible = mlx_xpm_file_to_image(
			game->mlx, "assets/textures/collectible.xpm", &w, &h);
	game->hero_on_exit = mlx_xpm_file_to_image(
			game->mlx, "assets/textures/hero_on_exit.xpm", &w, &h);
}

void	load_ground_textures(t_game *game)
{
	int		w;
	int		h;

	game->wall = mlx_xpm_file_to_image(
			game->mlx, "assets/textures/wall.xpm", &w, &h);
	game->floor_00 = mlx_xpm_file_to_image(
			game->mlx, "assets/textures/floor_00.xpm", &w, &h);
	game->floor_01 = mlx_xpm_file_to_image(
			game->mlx, "assets/textures/floor_01.xpm", &w, &h);
	game->floor_02 = mlx_xpm_file_to_image(
			game->mlx, "assets/textures/floor_02.xpm", &w, &h);
	game->floor_03 = mlx_xpm_file_to_image(
			game->mlx, "assets/textures/floor_03.xpm", &w, &h);
	game->exit_closed = mlx_xpm_file_to_image(
			game->mlx, "assets/textures/exit_closed.xpm", &w, &h);
	game->exit_opened = mlx_xpm_file_to_image(
			game->mlx, "assets/textures/exit_opened.xpm", &w, &h);
	game->obstacle = mlx_xpm_file_to_image(
			game->mlx, "assets/textures/obstacle.xpm", &w, &h);
}
