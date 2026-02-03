/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3d.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbagin <rbagin@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/01/14 18:14:26 by rbagin        #+#    #+#                 */
/*   Updated: 2026/02/03 14:29:13 by ravi-bagin    ########   odam.nl         */
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

/*	|pos_x, pos_y|
		-The player's exact position in the 2D map (floating point for smooth movement)
	|dir_x, dir_y|
		-Direction vector - where the player is looking(normalized vector)
	|plane_x, plane_y|
		-Camera plane - perpendicular(90) to direction vector
		-this defines the field of view (FOV)
		-the length of this vector determines the FOV angle
		-typically around 66 degrees for classic raycasting*/
typedef struct s_player
{
	t_pos	pos;
	double	dir_x;	// direction on the map
	double	dir_y;
	double	plane_x;	// Camera plane(perpendicular(90 degrees) to dir)
	double	plane_y;
}			t_player;

/*	|RAY SETUP|
		-camera_x: Maps screen x position to camera plane coordinates (-1 = left edge, 0 = center, 1 = right edge)
		-ray_dir_x, ray_dir_y: The actual direction the ray is traveling (dir + plane * camera_x)
	|DDA ALGORITHM|
		-map_x, map_y: Which grid square we're currently checking (integer coordinates)
		-side_dist_x, side_dist_y: Distance the ray must travel from its current position to the next x or y gridline
		-delta_dist_x, delta_dist_y: How far the ray travels to cross exactly one map square (constant per ray)
		-step_x, step_y: Which direction to step in the grid (1 or -1)
	|HIT DETECTION|
		-hit: Boolean flag indicating if we've hit a wall
		-side: Which face of the wall was hit (NS walls vs EW walls) - needed for different wall textures/shading
	|RENDERING|
		-perp_wall_dist: The perpendicular distance to avoid fisheye effect
		-line_height: How tall to draw the wall slice
		-draw_start, draw_end: Y coordinates for where to start/stop drawing this wall slice*/
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
}			t_ray;

typedef	struct	s_map
{
	char	**grid;		//2D array representing the map
	int		width;
	int		height;
	t_pos	player_p;
} 	t_map;

typedef	struct	s_img
{
	mlx_image_t	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
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
}			t_color;

typedef struct s_texset
{
	mlx_texture_t	*texture;
	int				width;
	int				height;
}			t_texset;

/*input state (keys pressed) hooks set/unset
loop reads every frame to move
int key_press(int keycode, t_game *g)
int key_release(int keycode, t_game *g)
*/
typedef struct s_input
{
	bool	w;
	bool	a;
	bool	s;
	bool	d;
	bool	left;
	bool	right;
}			t_input;

typedef	struct	s_game
{
	mlx_t		*mlx;
	void		*win;
	t_img		frame;
	t_player	player;
	t_map		map;
	t_color		color;
	t_texpath	paths;
	t_texset	tex[4];
	t_input		inp; //global game state
	int			screen_w;
	int			screen_h;
}				t_game;

//parsing map
bool	lead_map(t_game *g, const char *filename);

//raycasting.c
void	cast_ray(t_player *player, t_map *map, t_ray *ray);
void	render_scene(t_game *game, t_player *player, t_ray *ray);

//render.c
uint32_t	get_wall_color(t_ray *ray);
void	draw_vertical_line(t_game *game, int x, t_ray *ray);

//player_movement.c
void	handle_movement(t_game *game);

#endif
