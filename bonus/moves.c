/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcochran <rcochran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 18:08:10 by rcochran          #+#    #+#             */
/*   Updated: 2025/03/31 00:15:35 by rcochran         ###   ########.fr       */
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
	if (next_tile == '1')
		return ;
	game->moves_count++;
	ft_printf("(moves.c) game->moves_count : %d\n", game->moves_count);
	if (next_tile == 'C')
	{
		game->map->collected_count++;
		game->map->grid[new_y][new_x] = '0';
		win_trigger(game);
	}
	if (next_tile == 'B')
	{
		defeat_trigger(game);
	}
	if (next_tile == 'E'
		&& game->map->collected_count == game->map->collectible_count)
	{
		ft_printf("GG ! ✅\n");
		exit_game(game, 0);
	}
	game->map->grid[new_y][new_x] = 'P';
	restore_tile(game, game->map->player_pos_x, game->map->player_pos_y);
	game->map->player_pos_x = new_x;
	game->map->player_pos_y = new_y;
	render_tile(game, new_x, new_y);
	move_baddies(game);
}
// TODO : Ici ^ refresh la vue pour actualiser le display count

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
