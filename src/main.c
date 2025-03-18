/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcochran <rcochran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 17:50:58 by rcochran          #+#    #+#             */
/*   Updated: 2025/03/19 00:13:31 by rcochran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	char	*map_name;
	t_map	*map;
	// int		fd;
	// char	*tmp;

	if (ac < 2)
		return (ft_printf("Usage : ./so_long assets/maps/<name>\n"), 1);
	map_name = av[1];
/* 	fd = open(map_name, O_RDONLY);
	tmp = get_next_line(fd);
	printf("line : [%s]\n", tmp);
	while (tmp)
	{
		free(tmp);
		tmp = get_next_line(fd);
		printf("line : [%s]\n", tmp);
	}
	close(fd); */
	map = parse_map(map_name);
	if (!map)
		return (ft_printf("main() : Error, no map\n"));
	if (!check_map_validity(map))
		return (free_map(map), 1);
	ft_printf("OK ✅\n");
	free_map(map);
	return (0);
}
