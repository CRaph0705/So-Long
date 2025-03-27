/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcochran <rcochran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 17:51:20 by rcochran          #+#    #+#             */
/*   Updated: 2025/03/27 19:17:05 by rcochran         ###   ########.fr       */
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
# define TILE_SIZE 32
# define GAME_ERROR_1 "Malloc error \n"

# define ESC_KEY 53
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_UP 126
# define KEY_LEFT 123
# define KEY_DOWN 125
# define KEY_RIGHT 124
# define KEY_Z 6
# define KEY_Q 12
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
	int		collectible_count;
	int		collected_count;
}	t_map;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_game
{
	void	*mlx;
	void	*mlx_win;
	void	*wall;
	void	*obstacle;
	void	*floor_00;
	void	*floor_01;
	void	*floor_02;
	void	*floor_03;
	void	*player;
	void	*exit_opened;
	void	*exit_closed;
	void	*collectible;
	t_map	*map;
}	t_game;

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

void	render(t_game *game);
void	init_window(t_game *game);
void	load_textures(t_game *game);

void	move_player(t_game *game, int x_input, int y_input);
int		handle_keypress(int keycode, t_game *game);

void	exit_game(t_game *game, int n);

#endif