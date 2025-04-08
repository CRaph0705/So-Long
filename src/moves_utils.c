/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcochran <rcochran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 17:05:08 by rcochran          #+#    #+#             */
/*   Updated: 2025/04/08 17:12:25 by rcochran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	update_player_pos(t_game *game, int new_x, int new_y);

void	update_player_pos(t_game *game, int new_x, int new_y)
{
	int	player_x;
	int	player_y;

	player_x = game->map->player_pos_x;
	player_y = game->map->player_pos_y;
	game->map->grid[player_y][player_x] = '0';
	game->map->grid[new_y][new_x] = 'P';
	restore_tile(game, game->map->player_pos_x, game->map->player_pos_y);
	game->map->player_pos_x = new_x;
	game->map->player_pos_y = new_y;
}
