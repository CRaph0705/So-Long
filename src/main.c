/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcochran <rcochran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 17:50:58 by rcochran          #+#    #+#             */
/*   Updated: 2025/03/19 16:15:45 by rcochran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	char	*map_name;
	t_map	*map;

	if (ac < 2)
		return (ft_printf("Usage : ./so_long assets/maps/<name>\n"), 1);
	map_name = av[1];
	map = parse_map(map_name);
	if (!map)
		return (ft_printf("main() : Error, no map\n"));
	if (!check_map_validity(map))
		return (free_map(map), 1);
	ft_printf("map OK ✅\n");
	free_map(map);
	ft_printf("free OK ✅\n");
	return (0);
}
