/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcochran <rcochran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 12:04:21 by rcochran          #+#    #+#             */
/*   Updated: 2025/04/01 13:01:50 by rcochran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int		is_valid_move(char next_tile);
void	handle_next_tile(t_game *game, int new_x,
			int new_y, char next_tile);
void	update_player_pos(t_game *game, int new_x, int new_y);
void	refresh_game(t_game *game, int new_x, int new_y);

int	is_valid_move(char next_tile)
{
	if (next_tile == '1')
		return (0);
	return (1);
}

void	handle_next_tile(t_game *game, int new_x,
	int new_y, char next_tile)
{
	if (next_tile == 'C')
	{
		game->map->collected_count++;
		game->map->grid[new_y][new_x] = '0';
		win_trigger(game);
	}
	else if (next_tile == 'B')
	{
		defeat_trigger(game);
	}
	else if (next_tile == 'E'
		&& game->map->collected_count == game->map->collectible_count)
	{
		ft_printf("GG ! ✅\n");
		exit_game(game, 0);
	}
}

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

void	refresh_game(t_game *game, int new_x, int new_y)
{
	render_tile(game, new_x, new_y);
	move_baddies(game);
	display_hud(game);
}
