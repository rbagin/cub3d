/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 16:22:59 by imutavdz          #+#    #+#             */
/*   Updated: 2026/01/24 16:26:15 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include <MLX42/MLX42.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdbool.h>
# include <stdio.h>
# include "libft.h"

# define TILE_SIZE 128
# define WINDOW_TITLE "SO_TWIX" 

# define WALL '1'
# define VOID '0'
# define COLLECTIBLE 'C'
# define PLAYER 'P'
# define EXIT_POINT 'E'
# define DEATH 'D'
# define ENEMY 'Y'

# define WALL_PATH "./assets/wall.png"
# define VOID_PATH "./assets/void.png"
# define COLLECT_PATH "./assets/collect.png"
# define PLAYER_PATH_R "./assets/player.png"
# define PLAYER_PATH_L "./assets/player_left.pngs"
# define EXIT_GAME "./assets/exit.png"
# define ENEMY_PATH "./assets/enemy.png"

//error messages
# define ERR_ARGS "Error\nIncorrect number of arguments"
# define ERR_MAP_CHARS "Error\nInvalid characters in map"
# define ERR_MAP_RECT "Error\nMap is not rectangular"
# define ERR_MAP_WALLS "Error\nMap is not surrounded by walls"
# define ERR_MAP_PLAYER "Error\nMap must have exactly one player"
# define ERR_MAP_EXIT "Error\nMap must have at least one exit"
# define ERR_MAP_COLLECT "Error\nMap must have at least one collectible"
# define ERR_MAP_PATH "Error\nNo valid path to collect all items and reach exit"
# define ERR_MAP_EXTENTION "Error\nMap file must have .ber extension"
# define ERR_MAP_OPEN "Error\nCould not open map file"
# define ERR_MEMORY "Error\nMemory allocation failed"
# define ERR_MLX "Error\nMLX initialization failed"
# define ERR_MAP_EMPTY "Error\nMAP file is invalid"
# define ERR_ASSET_LOAD "Error\nFail to load game assets"

typedef struct s_floodfill
{
	int		width;
	int		height;
	int		*exit_flag;
	int		*collectibles;
	int		*enemies;
	char	**map_copy;
}	t_path;

typedef struct s_position
{
	int	x;
	int	y;
}	t_pos;

typedef struct s_player
{
	t_pos		pos;
	int			moves;
	int			collected_count;
	mlx_image_t	*curr_plsyrt_img;
	mlx_image_t	*player_insta;
}	t_player;

typedef struct s_map
{
	char	**grid; //2D ARRAY
	int		width;
	int		height;
	int		collectibles; //TOT COLLECTIBLES
	int		num_exit;
	int		player;
	// int 	enemies;
	// t_pos 	enemy_pos;
	t_pos	exit_pos; //EXIT POSITION
	t_pos	player_pos;
}	t_map;

typedef struct s_assets
{
	mlx_image_t		*wall_img;
	mlx_image_t		*void_img;
	mlx_image_t		*collect_img;
	mlx_image_t		*player_img;
	mlx_image_t		*player_img_l;
	mlx_image_t		*exit_img;
	// mlx_image_t		*enemies_img;
	mlx_image_t		***collect_single_img;
}	t_assets;

typedef struct s_ui_elements
{
	mlx_image_t	*moves_txt_img;
}	t_ui_elem;

typedef struct s_game
{
	mlx_t			*mlx;
	t_map			map; //map data struct
	t_player		player; //player data
	t_assets		assets; //game assets
	t_ui_elem		ui;
	bool			game_over;
	mlx_instance_t	*player_insta;
}	t_game;

void		final_cleanup(t_game *game);
void		print_exit(const char *errmsg, t_game *game, bool do_cleanup);

bool		init_mlx_window(t_game *game);

bool		load_map(t_game *game, const char *filename);
void		free_grid(char **grid, int height);

bool		parse_valid_map(t_game *game);
bool		is_rect(t_map *map);
bool		is_closed(t_map *map);
bool		chars_valid(t_map *map);
bool		check_counts(t_map *map);
char		**copy_map(t_map *map);
void		flood_fill_rec(int x, int y, t_path *data);
bool		check_path(t_map *map);

bool		load_graphics(t_game *game);
mlx_image_t	*load_image(mlx_t *mlx, const char *path);

void		render_first_map(t_game *game);
void		render_player(t_game *game);
void		handle_player(mlx_key_data_t keydata, t_game *game);
void		moves_display(t_game *game);

void		setup_event_hooks(t_game *game);
void		try_move(t_game *game, int dx, int dy);
void		hide_collected(t_game *game, int coll_tile_x, int coll_tile_y);
void		check_exit(t_game *game);


#endif