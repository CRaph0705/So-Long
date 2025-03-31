/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcochran <rcochran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 15:02:28 by rcochran          #+#    #+#             */
/*   Updated: 2025/03/31 10:20:37 by rcochran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render(t_game *game);
void	init_window(t_game *game);
void	load_textures(t_game *game);
void	*get_random_floor(t_game *game);
void	render_tile(t_game *game, int x, int y);
void	win_trigger(t_game *game);

void	load_textures(t_game *game)
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
	game->player = mlx_xpm_file_to_image(
			game->mlx, "assets/textures/player.xpm", &w, &h);
	game->exit_closed = mlx_xpm_file_to_image(
			game->mlx, "assets/textures/exit_closed.xpm", &w, &h);
	game->exit_opened = mlx_xpm_file_to_image(
			game->mlx, "assets/textures/exit_opened.xpm", &w, &h);
	game->collectible = mlx_xpm_file_to_image(
			game->mlx, "assets/textures/collectible.xpm", &w, &h);
	game->obstacle = mlx_xpm_file_to_image(
			game->mlx, "assets/textures/obstacle.xpm", &w, &h);
}

void	*get_random_floor(t_game *game)
{
	int	r;

	r = rand() % 100;
	if (r < 50)
		return (game->floor_00);
	else if (r < 80)
		return (game->floor_01);
	else if (r < 95)
		return (game->floor_02);
	else
		return (game->floor_03);
}

void	init_window(t_game *game)
{
	game->mlx = mlx_init();
	game->mlx_win = mlx_new_window(
			game->mlx,
			game->map->width * TILE_SIZE,
			game->map->height * TILE_SIZE,
			"THE GAME"
			);
	load_textures(game);
}

void	win_trigger(t_game *game)
{
	int		x;
	int		y;

	x = game->map->exit_x;
	y = game->map->exit_y;
	if (game->map->collected_count != game->map->collectible_count)
		return ;
	render_tile(game, x, y);
}
