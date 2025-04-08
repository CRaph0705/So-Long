/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcochran <rcochran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 14:23:56 by rcochran          #+#    #+#             */
/*   Updated: 2025/04/08 14:38:27 by rcochran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	destroy_props_textures(t_game *game);
void	destroy_ground_textures(t_game *game);

void	destroy_props_textures(t_game *game)
{
	if (!game)
		return ;
	if (game->player)
		mlx_destroy_image(game->mlx, game->player);
	if (game->collectible)
		mlx_destroy_image(game->mlx, game->collectible);
	if (game->bad_guy)
		mlx_destroy_image(game->mlx, game->bad_guy);
	if (game->hero_on_exit)
		mlx_destroy_image(game->mlx, game->hero_on_exit);
}

void	destroy_ground_textures(t_game *game)
{
	if (!game)
		return ;
	if (game->wall)
		mlx_destroy_image(game->mlx, game->wall);
	if (game->floor_00)
		mlx_destroy_image(game->mlx, game->floor_00);
	if (game->floor_01)
		mlx_destroy_image(game->mlx, game->floor_01);
	if (game->floor_02)
		mlx_destroy_image(game->mlx, game->floor_02);
	if (game->floor_03)
		mlx_destroy_image(game->mlx, game->floor_03);
	if (game->exit_opened)
		mlx_destroy_image(game->mlx, game->exit_opened);
	if (game->exit_closed)
		mlx_destroy_image(game->mlx, game->exit_closed);
	if (game->obstacle)
		mlx_destroy_image(game->mlx, game->obstacle);
}
