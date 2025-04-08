/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcochran <rcochran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 17:51:20 by rcochran          #+#    #+#             */
/*   Updated: 2025/04/08 17:06:47 by rcochran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"

# ifdef __APPLE__
#  include "../mlx_macos/mlx.h"
#  define ESC_KEY 53
#  define KEY_W 13
#  define KEY_A 0
#  define KEY_S 1
#  define KEY_D 2
#  define KEY_UP 126
#  define KEY_LEFT 123
#  define KEY_DOWN 125
#  define KEY_RIGHT 124
#  define KEY_Z 6
#  define KEY_Q 12

# else
#  include "../mlx_linux/mlx.h"
#  define ESC_KEY 65307
#  define KEY_W 119
#  define KEY_A 97
#  define KEY_S 115
#  define KEY_D 100
#  define KEY_UP 65362
#  define KEY_LEFT 65361
#  define KEY_DOWN 65364
#  define KEY_RIGHT 65363
#  define KEY_Z 122
#  define KEY_Q 113
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
# define INVALID_MAP_5 "Error: map too large."
# define MAX_MAP_WIDTH 40
# define MAX_MAP_HEIGHT 25
/* 	
{
	char	**grid;
	void	***floor_start;
	int		width;
	int		height;
	int		player_pos_x;
	int		player_pos_y;
	int		collectible_count;
	int		collected_count;
	int		exit_x;
	int		exit_y;
}	t_map;
*/
typedef struct s_map
{
	char	**grid;
	void	***floor_start;
	int		width;
	int		height;
	int		player_pos_x;
	int		player_pos_y;
	int		collectible_count;
	int		collected_count;
	int		exit_x;
	int		exit_y;
}	t_map;

/* {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data; */
typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

/* {
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
	int		moves_count;
	t_map	*map; 
}	t_game;*/
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
	void	*hero_on_exit;
	void	*exit_opened;
	void	*exit_closed;
	void	*collectible;
	int		moves_count;
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

void	render(t_game *game);
void	init_window(t_game *game);
void	load_textures(t_game *game);
void	render_tile(t_game *game, int x, int y);

void	move_player(t_game *game, int x_input, int y_input);
int		handle_keypress(int keycode, t_game *game);
void	win_trigger(t_game *game);
void	init_floor_map(t_game *game);
void	free_l_floor_map(t_game *game, int limit);
int		alloc_floor_map(t_game *game);
void	fill_floor_map(t_game *game);
void	*get_random_floor(t_game *game);

void	restore_tile(t_game *game, int x, int y);

int		exit_game(t_game *game, int n);

void	free_game(t_game *game);
int		is_map_too_big(int map_width, int map_height);
void	load_props_textures(t_game *game);
void	load_ground_textures(t_game *game);
void	*get_tile_image(t_game *game, int x, int y);
void	*get_wall_or_obstacle_img(t_game *game, int x, int y);
void	*get_player_img(t_game *game);
void	update_player_pos(t_game *game, int new_x, int new_y);
void	handle_next_tile(t_game *game, int new_x,
			int new_y, char next_tile);

#endif