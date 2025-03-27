/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcochran <rcochran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 15:02:28 by rcochran          #+#    #+#             */
/*   Updated: 2025/03/27 23:53:15 by rcochran         ###   ########.fr       */
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
			if(game->map->floor_init_state[y][x])
				mlx_put_image_to_window(game->mlx, game->mlx_win, game->map->floor_init_state[y][x], x * TILE_SIZE, y * TILE_SIZE);
			img = NULL;
			if (game->map->grid[y][x] == '1')
			{
				if (y == 0 || y == game->map->height - 1 || x == 0 || x == game->map->width - 1)
					img = game->wall;
				else
					img = game->obstacle;
			}
			else if (game->map->grid[y][x] == 'E')
				img = game->exit_closed;
			else if (game->map->grid[y][x] == 'P')
				img = game->player;
			else if (game->map->grid[y][x] == 'C')
				img = game->collectible;
			if (img)
				mlx_put_image_to_window(game->mlx, game->mlx_win, img, x * TILE_SIZE, y * TILE_SIZE);
			x++;
		}
		y++;
	}
}


void	restore_tile(t_game *game, int x, int y)
{
	void *img;

	img = game->map->floor_init_state[y][x];
	// if (game->map->grid[y][x] == 'E')
		// img = game->exit_closed;
	if (img == game->exit_closed)
		game->map->grid[y][x] = 'E';
	mlx_put_image_to_window(game->mlx, game->mlx_win, img, x * TILE_SIZE, y * TILE_SIZE);
}

void	render_tile(t_game *game, int x, int y)
{
	void	*img;

	if (game->map->grid[y][x] == '1')
		img = game->wall;
	else if (game->map->grid[y][x] == 'E')
	{
		if (game->map->collected_count == game->map->collectible_count)
			img = game->exit_opened;
		else
			img = game->exit_closed;
	}
	else if (game->map->grid[y][x] == 'C')
		img = game->collectible;
	else if (game->map->grid[y][x] == 'P')
		img = game->player;
	else
		return ;
	mlx_put_image_to_window(game->mlx,
		game->mlx_win, img, x * TILE_SIZE, y * TILE_SIZE);
}


/* void	render_tile(t_game *game, int x, int y)
{
	void	*img;

	if (!game->map->floor_init_state[y][x])
		img = game->floor_00;
	else
		img = game->map->floor_init_state[y][x];
	mlx_put_image_to_window(
		game->mlx, game->mlx_win, img, x * TILE_SIZE, y * TILE_SIZE);
	img = NULL;
	if (game->map->grid[y][x] == '1')
		img = game->wall;
	else if (game->map->floor_init_state[y][x] == game->exit_closed)
	{
		img = game->exit_closed;
		if (game->map->collected_count == game->map->collectible_count)
			img = game->exit_opened;
	}
	else if (game->map->grid[y][x] == 'C')
		img = game->collectible;
	else if (game->map->floor_init_state[y][x] == game->player)
		img = game->player;
	if (img)
		mlx_put_image_to_window(
			game->mlx, game->mlx_win, img, x * TILE_SIZE, y * TILE_SIZE);
} */

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

void	init_floor_map(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	game->map->floor_init_state = malloc(sizeof(void **) * game->map->height);
	if (!game->map->floor_init_state)
		return ;
	while (y < game->map->height)
	{
		x = 0;
		game->map->floor_init_state[y] = malloc(sizeof(void *) * game->map->width);
		if (!game->map->floor_init_state[y])
			return ;
		while (x < game->map->width)
		{
			if (game->map->grid[y][x] == '0' || game->map->grid[y][x] == 'P' || game->map->grid[y][x] == 'C')
				game->map->floor_init_state[y][x] = get_random_floor(game);
			else if (game->map->grid[y][x] == 'E')
				game->map->floor_init_state[y][x] = game->exit_closed;
			else
				game->map->floor_init_state[y][x] = NULL;
			x++;
		}
		y++;
	}
}
