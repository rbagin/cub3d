/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbagin <rbagin@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/02/02 20:54:03 by rbagin        #+#    #+#                 */
/*   Updated: 2026/02/06 19:43:02 by rbagin        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
//can't use this because hardcoded colors, not paresd from file

// static int	get_texture_index(t_ray *ray)
// {
// 	if (ray->side == 0)
// 	{
// 		if (ray->step_x == 1)
// 			return (TEX_W);
// 		else
// 			return (TEX_E);
// 	}
// 	else
// 	{
// 		if (ray->step_y == 1)
// 			return (TEX_N);
// 		else
// 			return (TEX_S);
// 	}
// }
//changed bc must used parsed colors
//conver parsed rgb to rgba

static void	draw_ceiling_floor(t_game *game, int x, t_ray *ray)
{
	int			y;
	uint32_t	floor_rgba;
	uint32_t	ceiling_rgba;

	floor_rgba = ((uint32_t)game->color.floor << 8) | 0xFF;
	ceiling_rgba = ((uint32_t)game->color.ceiling << 8) | 0xFF;
	y = 0;
	while (y < ray->draw_start)
	{
		mlx_put_pixel(game->frame, x, y, ceiling_rgba);
		y++;
	}
	y = ray->draw_end;
	while (y < game->screen_h)
	{
		mlx_put_pixel(game->frame, x, y, floor_rgba);
		y++;
	}
}
//this one should be modified for textures
void	draw_vertical_line(t_game *game, int x, t_ray *ray)
{
	uint32_t	color;
	int			y;
	// int			tex_inx;
	// double		step;
	// double		tex_pos;
	// double		wall_x;

	draw_ceiling_floor(game, x, ray);
	// tex_inx = get_texture_index(ray);
	//replace with texture mapping
	if (ray->side == 0)
		color = rgb_to_rgba(N_COLOR);
	else
		color = rgb_to_rgba(S_COLOR);
	y = ray->draw_start;
	while (y < ray->draw_end)
	{
		// color = get_tex_pxl(&game->tex[tex_inx], tex_x, tex_y);
		mlx_put_pixel(game->frame, x, y, color);
		y++;
	}
}

static void	calc_line_height(t_game *g, t_ray *ray)
{
	ray->line_height = (int)(g->screen_h / ray->perp_wall_dist);
	ray->draw_start = -ray->line_height / 2 + g->screen_h / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->line_height / 2 + g->screen_h / 2;
	if (ray->draw_end >= g->screen_h)
		ray->draw_end = g->screen_h -1;
}

static void	init_ray_dir(t_game *g, t_player *player, t_ray *ray, int x)
{
	ray->camera_x = 2 * x / (double)g->screen_w - 1;
	ray->ray_dir_x = player->dir_x + (player->plane_x * ray->camera_x);
	ray->ray_dir_y = player->dir_y + (player->plane_y * ray->camera_x);
}

void	render_scene(t_game *game, t_player *player, t_ray *ray)
{
	int	x;

	x = 0;
	while (x < game->screen_w)
	{
		init_ray_dir(game, player, ray, x);
		cast_ray(player, &game->map, ray);
		calc_line_height(game, ray);
		draw_vertical_line(game, x, ray);
		x++;
	}
}
