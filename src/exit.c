/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcochran <rcochran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 18:58:43 by rcochran          #+#    #+#             */
/*   Updated: 2025/03/27 22:51:18 by rcochran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	exit_game(t_game *game, int n);

//destroy mlx window

void	exit_game(t_game *game, int n)
{
	if (game)
	{
		ft_printf("(exit.c) game->moves_count : %d\n", game->moves_count);
		if (game->map)
			free_map(game->map);
		free(game);
	}
	exit(n);
}
