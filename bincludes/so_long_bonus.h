/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcochran <rcochran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 15:15:21 by rcochran          #+#    #+#             */
/*   Updated: 2025/04/08 14:48:30 by rcochran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

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
# define PARSE_ERROR_4 "parse_map() : Error on map->grid malloc.\n"
# define INVALID_BORDERS "Error: Map must be surrounded by walls.\n"
# define INVALID_ELEM_1 "Error: Invalid number of P, E, or C.\n"
# define INVALID_ELEM_2 "Error: Invalid char found.\n"
# define EMPTY_MAP_FILE "Error: Empty map file.\n"
# define INVALID_MAP_1 "check_map_validity() : Invalid map : not rectangle.\n"
# define INVALID_MAP_2 "Error: No valid path to exit or collectibles.\n"
# define INVALID_MAP_3 "valid_path() : Error on t_map malloc.\n"
# define INVALID_MAP_4 "valid_path() : No src map given.\n"
# define INVALID_FILE "Error : Invalid file extension.\n"
# define GAME_ERROR_1 "game malloc error \n"

# define TILE_SIZE 32
# define INVALID_MAP_5 "Error: map too large."
# define MAX_MAP_WIDTH 40
# define MAX_MAP_HEIGHT 25

/* {
	int	pos_x;
	int	pos_y;
}	t_bad_guy; */
typedef struct s_bad_guy
{
	int					pos_x;
	int					pos_y;
	struct s_bad_guy	*next;
}	t_bad_guy;

/* 	
{
	char	**grid;
	void	***floor_floor_start;
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
	char		**grid;
	void		***floor_start;
	int			width;
	int			height;
	int			player_pos_x;
	int			player_pos_y;
	int			collectible_count;
	int			collected_count;
	int			exit_x;
	int			exit_y;
	t_bad_guy	*baddies;
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
	void	*bad_guy;
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
	void	*exit_opened;
	void	*exit_closed;
	void	*collectible;
	void	*bad_guy;
	void	*hero_on_exit;
	int		moves_count;
	t_map	*map;
}	t_game;

/* PARSING */

/* opens map file, return new struct or error */
t_map		*parse_map(char *map_name);

/* returns if map is valid */
int			check_map_validity(t_map *map);
int			valid_path(t_map *map);

/* free map */
void		free_map(t_map *map);

/* ERROR HANDLING */

void		display_error(char *msg);

/* DISPLAY */

void		display_map_grid(t_map *map);
void		display_map(t_map *map);

void		count_other_elements(t_map *map, int *other_count);
int			is_valid_char(char c);
int			valid_filename(char *file_name);

void		render(t_game *game);
void		init_window(t_game *game);
void		load_textures(t_game *game);
void		render_tile(t_game *game, int x, int y);

void		move_player(t_game *game, int x_input, int y_input);
int			handle_keypress(int keycode, t_game *game);
void		win_trigger(t_game *game);
void		init_floor_map(t_game *game);
void		free_l_floor_map(t_game *game, int limit);
int			alloc_floor_map(t_game *game);
void		fill_floor_map(t_game *game);
void		*get_random_floor(t_game *game);

void		restore_tile(t_game *game, int x, int y);

int			exit_game(t_game *game, int n);

void		free_game(t_game *game);

void		add_bad_guy(t_map *map, int y, int x);
void		defeat_trigger(t_game *game);
int			move_baddies(t_game *game);
void		init_map_baddies(t_map *map);
t_bad_guy	*new_bad_guy(int y, int x);
void		add_bad_guy(t_map *map, int y, int x);
void		set_bad_buy_pos(t_bad_guy *bad_guy, int x, int y);

/* HUD */
/* refresh and display HUD */
void		display_hud(t_game *game);
/* display move count in the HUD area. */
void		display_moves_count(t_game *game);
/* display collectible count in the HUD area. */
void		display_collectible_count(t_game *game);
/* reprint tiles under HUD area. */
void		refresh_hud_background(t_game *game);

int			is_valid_move(char next_tile);
void		handle_next_tile(t_game *game, int new_x,
				int new_y, char next_tile);

int			is_valid_move(char next_tile);
void		handle_next_tile(t_game *game, int new_x,
				int new_y, char next_tile);
void		update_player_pos(t_game *game, int new_x, int new_y);
void		refresh_game(t_game *game, int new_x, int new_y);
void		free_baddies(t_map *map);
int			is_map_too_big(int map_width, int map_height);
void		load_props_textures(t_game *game);
void		load_ground_textures(t_game *game);
void		destroy_props_textures(t_game *game);
void		destroy_ground_textures(t_game *game);
void		*get_wall_or_obstacle_img(t_game *game, int x, int y);
void		*get_player_img(t_game *game);

#endif