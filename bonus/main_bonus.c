/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcochran <rcochran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 13:48:05 by rcochran          #+#    #+#             */
/*   Updated: 2025/04/01 12:49:33 by rcochran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	main(int ac, char **av)
{
	t_map	*map;
	t_game	*game;

	game = NULL;
	if (ac < 2)
		return (ft_printf("Usage : ./so_long <path>\n"), 1);
	map = parse_map(av[1]);
	if (!map)
		return (ft_printf("main() : Error, no map\n"));
	if (!check_map_validity(map))
		return (free_map(map), 1);
	init_map_baddies(map);
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
	return (0);
}
