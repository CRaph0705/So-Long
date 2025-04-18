/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcochran <rcochran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 09:31:05 by rcochran          #+#    #+#             */
/*   Updated: 2025/04/08 16:40:58 by rcochran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	render(t_game *game);
void	render_tile(t_game *game, int x, int y);
void	restore_tile(t_game *game, int x, int y);
void	*get_tile_img(t_game *game, int x, int y);

void	render(t_game *game)
{
	int		y;
	int		x;
	void	*img;

	y = 0;
	img = NULL;
	if (!game)
		exit_game(game, 1);
	while (y < game->map->height)
	{
		x = 0;
		while (x < game->map->width)
		{
			if (game->map->floor_start[y][x])
				mlx_put_image_to_window(game->mlx, game->mlx_win,
					game->map->floor_start[y][x], x * TILE_SIZE, y * TILE_SIZE);
			img = get_tile_img(game, x, y);
			if (img)
				mlx_put_image_to_window(game->mlx,
					game->mlx_win, img, x * TILE_SIZE, y * TILE_SIZE);
			x++;
		}
		y++;
	}
	display_moves_count(game);
}

void	*get_tile_img(t_game *game, int x, int y)
{
	if (!game || !game->map || !game->map->grid)
		return (NULL);
	if (game->map->grid[y][x] == '1')
		return (get_wall_or_obstacle_img(game, x, y));
	else if (game->map->grid[y][x] == 'E')
	{
		if (game->map->collected_count && game->map->collectible_count
			&& game->map->collected_count == game->map->collectible_count)
			return (game->exit_opened);
		return (game->exit_closed);
	}
	else if (game->map->grid[y][x] == 'P')
		return (get_player_img(game));
	else if (game->map->grid[y][x] == 'C')
		return (game->collectible);
	else if (game->map->grid[y][x] == 'B')
		return (game->bad_guy);
	return (NULL);
}

void	render_tile(t_game *game, int x, int y)
{
	void	*img;

	if (game->map->floor_start[y][x])
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->map->floor_start[y][x], x * TILE_SIZE, y * TILE_SIZE);
	img = get_tile_img(game, x, y);
	if (img)
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
