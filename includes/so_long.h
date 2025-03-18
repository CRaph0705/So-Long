/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcochran <rcochran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 17:51:20 by rcochran          #+#    #+#             */
/*   Updated: 2025/03/18 17:32:42 by rcochran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
// TODO # include <mlx.h>

# define PARSE_ERROR_1 "parse_map() : Error opening file.\n"
# define PARSE_ERROR_2 "parse_map() : Error on t_map malloc.\n"
# define PARSE_ERROR_3 "parse_map() : Invalid map.\n"

typedef struct s_map
{
	char	**grid;
	int		width;
	int		height;
	int		player_pos_x;
	int		player_pos_y;
}	t_map;

/* PARSING */

/* opens map file, return new struct or error */
t_map	*parse_map(char *map_name);

/* returns if map is valid */
int		check_map_validity(t_map *map);

/* free map */
void	free_map(t_map *map);

#endif