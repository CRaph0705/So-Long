/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcochran <rcochran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 18:08:10 by rcochran          #+#    #+#             */
/*   Updated: 2025/03/27 18:26:58 by rcochran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_player(t_game *game, int x, int y);

void	move_player(t_game *game, int x, int y)
{
	//TODO
	// check if next tile is not a wall
	// recup l'img next tile, superposer player dessus, reconstruire img sans player après son passage
	// si collectible, alors augmenter un compteur de 1
	// verif si exit_condition est remplie
	// game->map -> collected_count
	// game->map -> collectible_count
	//si la next case est sortie : verif condition de sortie si remplie, alors ecran de fin / exit
	return ;
}

void	handle_keypress(int keycode, t_game *game)
{
	if (keycode == ESC_KEY)
		exit_game(game);//TODO : add mlx destroy etc??
	else if (keycode == KEY_W || keycode == KEY_Z || keycode == KEY_UP)
		move_player(game, 0, -1);
	else if (keycode == KEY_S || keycode == KEY_DOWN)
		move_player(game, 0, 1);
	else if (keycode == KEY_A || keycode == KEY_Q || keycode == KEY_LEFT)
		move_player(game, -1, 0);
	else if (keycode == KEY_D || keycode == KEY_RIGHT)
		move_player(game, 1, 0);
}
