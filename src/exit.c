/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcochran <rcochran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 18:58:43 by rcochran          #+#    #+#             */
/*   Updated: 2025/04/08 17:23:02 by rcochran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int		exit_game(t_game *game, int n);
void	destroy_game_textures(t_game *game);
void	destroy_game_mlx(t_game *game);
void	free_game(t_game *game);

void	free_game(t_game *game)
{
	int	j;

	j = 0;
	if (!game)
		return ;
	destroy_game_textures(game);
	destroy_game_mlx(game);
	while (j < game->map->height)
	{
		free(game->map->floor_start[j]);
		j++;
	}	
	free(game->map->floor_start);
	if (game->map)
		free_map(game->map);
	free(game);
	ft_printf("exit game OK ✅\n");
}

void	destroy_game_textures(t_game *game)
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
	if (game->player)
		mlx_destroy_image(game->mlx, game->player);
	if (game->collectible)
		mlx_destroy_image(game->mlx, game->collectible);
	if (game->exit_opened)
		mlx_destroy_image(game->mlx, game->exit_opened);
	if (game->exit_closed)
		mlx_destroy_image(game->mlx, game->exit_closed);
	if (game->obstacle)
		mlx_destroy_image(game->mlx, game->obstacle);
	if (game->hero_on_exit)
		mlx_destroy_image(game->mlx, game->hero_on_exit);
}

void	destroy_game_mlx(t_game *game)
{
	if (!game)
		return ;
	if (game->mlx_win)
		mlx_destroy_window(game->mlx, game->mlx_win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
}

int	exit_game(t_game *game, int n)
{
	if (game)
		free_game(game);
	exit(n);
	return (0);
}
