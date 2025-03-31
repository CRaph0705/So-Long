/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcochran <rcochran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 09:31:05 by rcochran          #+#    #+#             */
/*   Updated: 2025/03/31 10:11:47 by rcochran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render(t_game *game);
void	render_tile(t_game *game, int x, int y);
void	restore_tile(t_game *game, int x, int y);
void	*get_tile_image(t_game *game, int y, int x);

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
			if (game->map->floor_start[y][x])
				mlx_put_image_to_window(game->mlx, game->mlx_win,
					game->map->floor_start[y][x], x * TILE_SIZE, y * TILE_SIZE);
			img = get_tile_image(game, y, x);
			if (img)
				mlx_put_image_to_window(game->mlx, game->mlx_win,
					img, x * TILE_SIZE, y * TILE_SIZE);
			x++;
		}
		y++;
	}
}

void	*get_tile_image(t_game *game, int y, int x)
{
	if (game->map->grid[y][x] == '1')
	{
		if (y == 0 || y == game->map->height - 1
			|| x == 0 || x == game->map->width - 1)
			return (game->wall);
		return (game->obstacle);
	}
	if (game->map->grid[y][x] == 'E')
		return (game->exit_closed);
	if (game->map->grid[y][x] == 'P')
		return (game->player);
	if (game->map->grid[y][x] == 'C')
		return (game->collectible);
	return (NULL);
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

void	restore_tile(t_game *game, int x, int y)
{
	void	*img;

	img = game->map->floor_start[y][x];
	if (img == game->exit_closed)
		game->map->grid[y][x] = 'E';
	mlx_put_image_to_window(game->mlx, game->mlx_win, img,
		x * TILE_SIZE, y * TILE_SIZE);
}
