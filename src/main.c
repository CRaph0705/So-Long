/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcochran <rcochran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 17:50:58 by rcochran          #+#    #+#             */
/*   Updated: 2025/03/18 16:57:02 by rcochran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
/* 
int	main(int ac, char **av)
{
	char	*map_name;
	t_map	*map;

	if (ac > 1)
	{
		map_name = av[1];
		map = parse_map(map_name);
	}
	return (0);
} */
int	main(int ac, char **av)
{
	char	*map_name;
	int		fd;
	char	*tmp;

	if (ac > 1)
	{
		map_name = av[1];
		fd = open(map_name, O_RDONLY);
		tmp = get_next_line(fd);
		printf("line : [%s]\n", tmp);
		while (tmp)
		{
			free(tmp);
			tmp = get_next_line(fd);
			printf("line : [%s]\n", tmp);
		}
		close(fd);
	}
	return (0);
}
