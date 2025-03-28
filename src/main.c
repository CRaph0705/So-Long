/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcochran <rcochran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 17:50:58 by rcochran          #+#    #+#             */
/*   Updated: 2025/03/28 11:08:17 by rcochran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
//convert image en xpm 
// <brew || apt> install imagemagick
// Usage : magick <name.png> <name.xpm>

int	main(int ac, char **av)
{
	char	*map_name;
	t_map	*map;
	t_game	*game;

	game = NULL;
	if (ac < 2)
		return (ft_printf("Usage : ./so_long <path>\n"), 1);
	map_name = av[1];
	map = parse_map(map_name);
	if (!map)
		return (ft_printf("main() : Error, no map\n"));
	if (!check_map_validity(map))
		return (free_map(map), 1);
	ft_printf("map OK ✅\n");
	game = malloc(sizeof(t_game));
	if (!game)
		return (ft_printf(GAME_ERROR_1), free_map(map), 1);
	game->map = map;
	game->moves_count = 0;
	init_window(game);
	init_floor_map(game);
	render(game);
	mlx_key_hook(game->mlx_win, handle_keypress, game);
	mlx_hook(game->mlx_win, 17, 0, exit_game, game);
	mlx_loop(game->mlx);
	free_map(map);
	ft_printf("free map OK ✅\n");
	free(game);
	ft_printf("free game OK ✅\n");
	return (0);
}
