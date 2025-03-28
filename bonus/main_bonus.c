/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcochran <rcochran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 13:48:05 by rcochran          #+#    #+#             */
/*   Updated: 2025/03/28 17:40:43 by rcochran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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
	// mlx_loop_hook(game->mlx, move_baddies, game);
	mlx_hook(game->mlx_win, 17, 0, exit_game, game);
	mlx_loop(game->mlx);
	return (0);
}


// si l'ennemi peut se déplacer il se déplace de 1 de façon aléatoire
// cas avec plusieurs ennemis ?