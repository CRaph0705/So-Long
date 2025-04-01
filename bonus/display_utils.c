/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcochran <rcochran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 09:10:02 by rcochran          #+#    #+#             */
/*   Updated: 2025/04/01 11:48:32 by rcochran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	display_moves_count(t_game *game);
void	display_collectible_count(t_game *game);
void	refresh_hud_background(t_game *game);

void	display_moves_count(t_game *game)
{
	char	*count_str;
	char	*str;

	count_str = ft_itoa(game->moves_count);
	if (!count_str)
		return ;
	str = ft_strjoin("Moves: ", count_str);
	mlx_string_put(game->mlx, game->mlx_win, 10, 10, 0xFFFFFF, str);
	free(count_str);
	free(str);
}

void	display_collectible_count(t_game *game)
{
	char	*collected;
	char	*total;
	char	*temp;
	char	*text;

	collected = ft_itoa(game->map->collected_count);
	total = ft_itoa(game->map->collectible_count);
	temp = ft_strjoin("Collectibles: ", collected);
	text = ft_strjoin(temp, "/");
	free(temp);
	temp = ft_strjoin(text, total);
	free(text);
	mlx_string_put(game->mlx, game->mlx_win, 10, 30, 0xFFFFFF, temp);
	free(collected);
	free(total);
	free(temp);
}

void	refresh_hud_background(t_game *game)
{
	int	x;

	x = 0;
	while (x < 5)
	{
		if (game->map->grid[0][x] == '1')
			mlx_put_image_to_window(game->mlx, game->mlx_win,
				game->wall, x * TILE_SIZE, 0);
		x++;
	}
}
