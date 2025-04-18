/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcochran <rcochran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 18:58:43 by rcochran          #+#    #+#             */
/*   Updated: 2025/04/08 14:29:58 by rcochran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int		exit_game(t_game *game, int n);
void	destroy_game_textures(t_game *game);
void	destroy_game_mlx(t_game *game);
void	free_game(t_game *game);
void	free_baddies(t_map *map);

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
	ft_printf("free map OK ✅\n");
	free(game);
	ft_printf("free game OK ✅\n");
}

void	destroy_game_textures(t_game *game)
{
	if (!game)
		return ;
	destroy_props_textures(game);
	destroy_ground_textures(game);
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

void	free_baddies(t_map *map)
{
	t_bad_guy	*current;
	t_bad_guy	*next;

	if (!map || !map->baddies)
		return ;
	current = map->baddies;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	map->baddies = NULL;
	ft_printf("free baddies OK ✅\n");
}
