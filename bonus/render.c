/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcochran <rcochran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 09:31:05 by rcochran          #+#    #+#             */
/*   Updated: 2025/03/31 10:05:34 by rcochran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	render(t_game *game);
void	render_tile(t_game *game, int x, int y);
void	restore_tile(t_game *game, int x, int y);


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
			if(game->map->floor_start[y][x])
				mlx_put_image_to_window(game->mlx, game->mlx_win, game->map->floor_start[y][x], x * TILE_SIZE, y * TILE_SIZE);
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
			else if (game->map->grid[y][x] == 'B')
				img = game->bad_guy;
			if (img)
				mlx_put_image_to_window(game->mlx, game->mlx_win, img, x * TILE_SIZE, y * TILE_SIZE);
			x++;
		}
		y++;
	}
	display_moves_count(game);
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
	else if (game->map->grid[y][x] == 'B')
		img = game->bad_guy;
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
	else
		game->map->grid[y][x] = '0';
	mlx_put_image_to_window(game->mlx,
		game->mlx_win, img, x * TILE_SIZE, y * TILE_SIZE);
}
