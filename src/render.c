/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbagin <rbagin@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/02/02 20:54:03 by rbagin        #+#    #+#                 */
/*   Updated: 2026/02/02 21:13:06 by rbagin        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

uint32_t	get_wall_color(t_ray *ray)
{
	if (ray->side == 0)
	{
		if (ray->step_x == 1)
			return (W_COLOR);
		else
			return (E_COLOR);
	}
	else
	{
		if (ray->step_y == 1)
			return (N_COLOR);
		else
			return (S_COLOR);
	}
}

static void	draw_ceiling_floor(t_game *game, int x, t_ray *ray)
{
	int	y;

	y = 0;
	while (y < ray->draw_start)
	{
		mlx_put_pixel(game->frame.img, x, y, CEILING_COLOR);
		y++;
	}
	y = ray->draw_end;
	while (y < SCREEN_HEIGHT)
	{
		mlx_put_pixel(game->frame.img, x, y, FLOOR_COLOR);
		y++;
	}
}

void	draw_vertical_line(t_game *game, int x, t_ray *ray)
{
	uint32_t	color;
	int			y;

	draw_ceiling_floor(game, x, ray);
	color = get_wall_color(ray);
	y = ray->draw_start;
	while (y < ray->draw_end)
	{
		mlx_put_pixel(game->frame.img, x, y, color);
		y++;
	}
}

static void	calc_line_height(t_ray *ray)
{
	ray->line_height = (int)(SCREEN_HEIGHT / ray->perp_wall_dist);
	ray->draw_start = -ray->line_height / 2 + SCREEN_HEIGHT / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->line_height / 2 + SCREEN_HEIGHT / 2;
	if (ray->draw_end >= SCREEN_HEIGHT)
		ray->draw_end = SCREEN_HEIGHT -1;
}

static void	init_ray_dir(t_player *player, t_ray *ray, int x)
{
	ray->camera_x = 2 * x / (double)SCREEN_WIDTH - 1;
	ray->ray_dir_x = player->dir_x + (player->plane_x * ray->camera_x);
	ray->ray_dir_y = player->dir_y + (player->plane_y * ray->camera_x);
}

void	render_scene(t_game *game, t_player *player, t_ray *ray)
{
	int	x;

	x = 0;
	while (x < SCREEN_WIDTH)
	{
		init_ray_dir(player, ray, x);
		cast_ray(&game->player, &game->map, ray);
		calc_line_height(ray);
		draw_vertical_line(game, x, ray);
		x++;
	}
}
