/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinding.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcochran <rcochran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 23:40:48 by rcochran          #+#    #+#             */
/*   Updated: 2025/03/19 18:44:06 by rcochran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// vérifier que chemin possible de player à exit
// vérifier que chemin possible de player à chaque collectible

//• You have to check if there’s a valid path in the map.
//• You must be able to parse any kind of map,
// as long as it respects the above rules.

// display_error(INVALID_MAP_2);

// https://fr.wikipedia.org/wiki/Algorithme_de_remplissage_par_diffusion

/* remplissage4(pixel, colcible, colrep) 
début
  si couleur(pixel) = colcible 
  alors
	 couleur(pixel) ← colrep
	 remplissage4(pixel au nord, colcible, colrep)
	 remplissage4(pixel au sud, colcible, colrep)
	 remplissage4(pixel à l'est, colcible, colrep)
	 remplissage4(pixel à l'ouest, colcible, colrep)
  finsi
fin
 */

// dup map ?
// remplir map depuis P
// chaque C et E est atteint ? else return specific error
int			valid_path(t_map *map);
static	t_map	*dup_map(t_map *map);
static	void	flood_fill(t_map *map, int x, int y);
static int	is_filled(t_map *map);

/* int	valid_path(t_map *map)
{
	(void)map;
	// return (display_error(INVALID_MAP_2), 0);
	return (1);
} */

static void	flood_fill(t_map *map, int x, int y)
{
	if (x < 0 || x >= map->width || y < 0 || y >= map->height)
		return ;
	if (map->grid[y][x] == '1' || map->grid[y][x] == 'F')
		return ;
	map->grid[y][x] = 'F';
	flood_fill(map, x + 1, y);
	flood_fill(map, x - 1, y);
	flood_fill(map, x, y + 1);
	flood_fill(map, x, y - 1);
}

// TODO debug segfault
static t_map	*dup_map(t_map *map)
{
	t_map	*new_map;
	int		i;
	int		map_h;

	map_h = map->height;
	new_map = malloc(sizeof(t_map));
	if (!new_map)
		return (NULL);
	i = 0;
	while (i < map_h)
	{
		new_map->grid = ft_realloc(new_map->grid, sizeof(char *) * map_h);
		new_map->grid[i] = strdup(map->grid[i]);
		i++;
	}
	new_map->grid[i] = NULL;
	new_map->height = map_h;
	new_map->width = map->width;
	return (new_map);
}

int	valid_path(t_map *map)
{
	t_map	*tmp_map;
	int		valid;

	valid = 1;
	tmp_map = dup_map(map);
	if (!tmp_map)
		return (display_error(INVALID_MAP_3), 0);
	flood_fill(tmp_map, map->player_pos_x, map->player_pos_y);
	valid = is_filled(tmp_map);
	free_map(tmp_map);
	if (!valid)
		return (display_error(INVALID_MAP_2), 0);
	return (1);
}

static int	is_filled(t_map *map)
{
	int		y;
	int		x;
	int		valid;

	valid = 1;
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (map->grid[y][x] == 'E' || map->grid[y][x] == 'C')
			{
				valid = 0;
				break ;
			}
			x++;
		}
		y++;
	}
	return (valid);
}
