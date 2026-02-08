/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3d.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbagin <rbagin@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/01/14 18:14:26 by rbagin        #+#    #+#                 */
/*   Updated: 2026/02/06 19:42:00 by rbagin        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

# include <MLX42/MLX42.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdbool.h>
# include <stdio.h>
# include <math.h>
# include "libft.h"
# include "gnl.h"
# include "macro.h"

typedef struct s_pos
{
	double	x;	// position on the map
	double	y;
}	t_pos;

/*input state (keys pressed) hooks set/unset
loop reads every frame to move
int key_press(int keycode, t_game *g)
int key_release(int keycode, t_game *g)
*/
// typedef struct s_input
// {
// 	bool	w;
// 	bool	a;
// 	bool	s;
// 	bool	d;
// 	bool	left;
// 	bool	right;
// }			t_input;

typedef struct s_player
{
	t_pos	pos;
	double	dir_x;	// direction on the map
	double	dir_y;
	double	plane_x;	// Camera plane(perpendicular(90 degrees) to dir)
	double	plane_y;
	int32_t	last_mouse_x;
}			t_player;

typedef	struct s_ray
{
	double	camera_x;	// x coordinate on camera plane (-1 to 1)
	double	ray_dir_x;	// ray direction vector x
	double	ray_dir_y;	// ray direction vector y

	int		map_x;		// current map square
	int		map_y;

	double	side_dist_x;	// distance from current position to next x gridline
	double	side_dist_y;	// distance from current position to next y gridline

	double	delta_dist_x;	// distance ray travels between x gridlines
	double	delta_dist_y;	// distance ray travels between y gridlines

	int		step_x;	//step direction in x (1 or -1)
	int		step_y;	//step direction in x (1 or -1)

	bool	hit;
	int		side;	// 0 = x side || 1 = y side

	double	perp_wall_dist;	// perpendicular(90 degrees) distance to wall
	int		line_height;		// height of wall line to draw
	int		draw_start;			// lowest pixel to draw
	int		draw_end;			// highest pixel to draw
	double	wall_x;
	int		tex_x;
}			t_ray;

typedef	struct	s_map
{
	char	**grid;		//2D array representing the map
	int		width;
	int		height;
} 	t_map;
//A simple 2D coordinate in map-space (floating point so you can be between tiles).
//x, y: player position in the grid coordinate system (tile units)
typedef	struct	s_img
{
	mlx_texture_t	*img;
	int				width;
	int				height;
}			t_img;

typedef enum e_side
{
	TEX_N = 0,
	TEX_S = 1,
	TEX_W = 2,
	TEX_E = 3
}	t_side;

typedef struct s_tex_path
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
}			t_texpath;

typedef struct s_color
{
	int		floor;
	int		ceiling;
	bool	f_set;
	bool	c_set;
}			t_color;

typedef struct s_texset
{
	mlx_texture_t	*texture;
	int				width;
	int				height;
}			t_texset;

typedef	struct	s_game
{
	mlx_t			*mlx;
	mlx_image_t		*frame;

	t_player		player;
	t_map			map;

	t_color			color;
	t_texpath		paths;
	t_texset		tex[4];
	int				screen_w;
	int				screen_h;
}	t_game;

static inline uint32_t	rgb_to_rgba(int rgb)
{
	return ((uint32_t)rgb << 8 | 0xFF);
}

//start
int				init_mlx(t_game *game);
void			game_loop(void *param);
bool			load_textures(t_game *g);
//rgb.c
bool			parse_rgb(const char *s, int *out_color);

//cleanup.c
void			print_exit(const char *errmsg, t_game *game, bool do_cleanup);
void			free_lines(char **lines);
void			free_grid(char **grid);
void			final_cleanup(t_game *g);
void			free_textures(t_game *g);

//parsing map
bool			load_map(t_game *g, const char *filename);
bool			is_blank_line(const char *line);
bool			is_map_line(const char *line);
int				parse_header(char **lines, t_game *g);
char			**split_lines(char *file_str, t_game *g);
void			parse_map_grid(char **lines, int map_start, t_game *game);
void			find_spawn(t_game *g);
void			valid_map(t_game *g);

//raycasting.c
void			cast_ray(t_player *player, t_map *map, t_ray *ray);
void			render_scene(t_game *game, t_player *player, t_ray *ray);

//render.c
uint32_t		get_wall_color(t_ray *ray);
void			draw_vertical_line(t_game *game, int x, t_ray *ray);
bool			load_one_t(t_game *g, int id, char *path);

//player_movement.c
void			setup_hooks(t_game *game);
void			handle_movement(t_game *game);
bool			is_valid_position(t_game *game, double x, double y);
void			try_move(t_game *game, t_player *player, double dx, double dy);

//player_rotation.c
void			handle_rotation(t_game *game);

#endif
