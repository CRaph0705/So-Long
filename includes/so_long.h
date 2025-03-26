/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcochran <rcochran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 17:51:20 by rcochran          #+#    #+#             */
/*   Updated: 2025/03/26 15:46:41 by rcochran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"

# ifdef __APPLE__
#  include "../mlx_macos/mlx.h"
# else
#  include "../mlx_linux/mlx.h"
# endif

# define PARSE_ERROR_1 "parse_map() : Error opening file.\n"
# define PARSE_ERROR_2 "parse_map() : Error on t_map malloc.\n"
# define PARSE_ERROR_3 "parse_map() : Invalid map.\n"
# define INVALID_BORDERS "Error: Map must be surrounded by walls.\n"
# define INVALID_ELEM_1 "Error: Invalid number of P, E, or C.\n"
# define INVALID_ELEM_2 "Error: Invalid char found.\n"
# define EMPTY_MAP_FILE "Error: Empty map file.\n"
# define INVALID_MAP_1 "check_map_validity() : Invalid map : not rectangle.\n"
# define INVALID_MAP_2 "Error: No valid path to exit or collectibles.\n"
# define INVALID_MAP_3 "valid_path() : Error on t_map malloc.\n"
# define INVALID_MAP_4 "valid_path() : No src map given.\n"
# define INVALID_FILE "Error : Invalid file extension.\n"

/* 	
{	
	char	**grid;
	int		width;
	int		height;
	int		player_pos_x;
	int		player_pos_y; 
} t_map
*/
typedef struct s_map
{
	char	**grid;
	int		width;
	int		height;
	int		player_pos_x;
	int		player_pos_y;
}	t_map;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

/* PARSING */

/* opens map file, return new struct or error */
t_map	*parse_map(char *map_name);

/* returns if map is valid */
int		check_map_validity(t_map *map);
int		valid_path(t_map *map);

/* free map */
void	free_map(t_map *map);

/* ERROR HANDLING */

void	display_error(char *msg);

/* DISPLAY */

void	display_map_grid(t_map *map);
void	display_map(t_map *map);

void	count_other_elements(t_map *map, int *other_count);
int		is_valid_char(char c);
int		valid_filename(char *file_name);

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	put_square(t_data *data, int x, int y, int color);
void	put_circle(t_data *data, int x, int y, int color);

#endif