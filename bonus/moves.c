/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcochran <rcochran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 18:08:10 by rcochran          #+#    #+#             */
/*   Updated: 2025/04/01 12:35:49 by rcochran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	move_player(t_game *game, int x_input, int y_input);
int		handle_keypress(int keycode, t_game *game);

void	move_player(t_game *game, int x_input, int y_input)
{
	int			new_x;
	int			new_y;
	char		next_tile;

	new_x = game->map->player_pos_x + x_input;
	new_y = game->map->player_pos_y + y_input;
	next_tile = game->map->grid[new_y][new_x];
	if (!is_valid_move(next_tile))
		return ;
	game->moves_count++;
	handle_next_tile(game, new_x, new_y, next_tile);
	update_player_pos(game, new_x, new_y);
	refresh_game(game, new_x, new_y);
}

int	handle_keypress(int keycode, t_game *game)
{
	if (keycode == ESC_KEY)
		exit_game(game, 0);
	else if (keycode == KEY_W || keycode == KEY_Z || keycode == KEY_UP)
		move_player(game, 0, -1);
	else if (keycode == KEY_S || keycode == KEY_DOWN)
		move_player(game, 0, 1);
	else if (keycode == KEY_A || keycode == KEY_Q || keycode == KEY_LEFT)
		move_player(game, -1, 0);
	else if (keycode == KEY_D || keycode == KEY_RIGHT)
		move_player(game, 1, 0);
	return (0);
}
