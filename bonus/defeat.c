/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defeat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcochran <rcochran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 15:46:28 by rcochran          #+#    #+#             */
/*   Updated: 2025/04/01 12:57:19 by rcochran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	defeat_trigger(t_game *game)
{
	ft_printf("❌❌❌\nT'as perdu le jeu !  ☠️\n❌❌❌\n");
	exit_game(game, 0);
}
