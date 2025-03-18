/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcochran <rcochran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 17:46:40 by rcochran          #+#    #+#             */
/*   Updated: 2025/03/18 23:22:15 by rcochran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	display_map(t_map *map);

/* TODO */
void	display_map(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->height)
	{
		printf("%s", map->grid[i]);
		i++;
	}
	return ;
}
