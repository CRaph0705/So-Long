/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcochran <rcochran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 15:02:28 by rcochran          #+#    #+#             */
/*   Updated: 2025/04/08 14:21:43 by rcochran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	render(t_game *game);
void	init_window(t_game *game);
void	load_textures(t_game *game);
void	*get_random_floor(t_game *game);
void	render_tile(t_game *game, int x, int y);
void	win_trigger(t_game *game);

void	load_textures(t_game *game)
{
	load_ground_textures(game);
	load_props_textures(game);
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

/* agrandir la window pour display le compteur ? 

game->map->height * TILE_SIZE + 40 ?
display move counts
TODO : à modifier ensuite dans moves.c ?
ft_printf("(moves.c) game->moves_count : %d\n", game->moves_count);

*/

// pareil avec nb collected/nb collectible ?

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
