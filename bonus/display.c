/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcochran <rcochran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 17:46:40 by rcochran          #+#    #+#             */
/*   Updated: 2025/03/31 09:57:46 by rcochran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	display_map_grid(t_map *map);
void	display_map(t_map *map);
void	display_bad_guy(t_bad_guy *bad_guy);
void	display_moves_count(t_game *game);
void	display_collectible_count(t_game *game);
void	refresh_hud_background(t_game *game);

void	display_map_grid(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->height)
	{
		ft_printf("%s\n", map->grid[i]);
		i++;
	}
	return ;
}

void	display_map(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->height)
	{
		ft_printf("%s\n", map->grid[i]);
		i++;
	}
	return ;
}

void	display_baddies(t_game *game)
{
	t_bad_guy	*baddy;

	if (!game)
		return ;
	if (!game->map->baddies || !(game->map->baddies))
		return ;
	baddy = game->map->baddies;
	ft_printf("display baddies\n");
	while (baddy != NULL)
	{
		display_bad_guy(baddy);
		baddy = baddy->next;
	}
	return ;
}

void	display_bad_guy(t_bad_guy *bad_guy)
{
	ft_printf("baddy->pos_x : %d\n", bad_guy->pos_x);
	ft_printf("baddy->pos_y : %d\n", bad_guy->pos_y);
	ft_printf("\n");
}

void	display_hud(t_game *game)
{
	if (!game || !game->mlx || !game->mlx_win)
		return ;
	refresh_hud_background(game);
	display_moves_count(game);
	display_collectible_count(game);
}

// à voir si display centré ? pour l'instant top 10 left 10
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
