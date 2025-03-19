/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinding.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcochran <rcochran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 23:40:48 by rcochran          #+#    #+#             */
/*   Updated: 2025/03/19 17:27:30 by rcochran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// vérifier que chemin possible de player à exit
// vérifier que chemin possible de player à collectible

//• You have to check if there’s a valid path in the map.
//• You must be able to parse any kind of map,
// as long as it respects the above rules.

// display_error(INVALID_MAP_2);

int	valid_path(t_map *map);

int	valid_path(t_map *map)
{
	(void)map;
	// return (display_error(INVALID_MAP_2), 0);
	return (1);
}
