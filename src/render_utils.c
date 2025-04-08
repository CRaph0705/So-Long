/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcochran <rcochran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 14:59:05 by rcochran          #+#    #+#             */
/*   Updated: 2025/04/08 15:07:10 by rcochran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*get_wall_or_obstacle_img(t_game *game, int x, int y);
void	*get_player_img(t_game *game);

void	*get_wall_or_obstacle_img(t_game *game, int x, int y)
{
	if (!game || !game->map || !game->map->grid)
		return (NULL);
	if (game->map->grid[y][x] != '1')
		return (NULL);
	if (y == 0 || y == game->map->height - 1
		|| x == 0 || x == game->map->width - 1)
		return (game->wall);
	return (game->obstacle);
}

void	*get_player_img(t_game *game)
{
	if (!game || !game->map || !game->map->grid)
		return (NULL);
	if (game->map->player_pos_x == game->map->exit_x
		&& game->map->player_pos_y == game->map->exit_y)
		return (game->hero_on_exit);
	return (game->player);
}
