/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   raycasting.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbagin <rbagin@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/01/28 12:43:35 by rbagin        #+#    #+#                 */
/*   Updated: 2026/02/01 22:22:35 by ravi-bagin    ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	cast_ray(t_player *player, t_map *map, t_ray *ray)
{
	ray->map_x = floor(player->pos.x);
	ray->map_y = floor(player->pos.y);

	ray->delta_dist_x = fabs(1 / ray->ray_dir_x);
	ray->delta_dist_y = fabs(1 / ray->ray_dir_y);

	if (ray->ray_dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (player->pos.x - ray->map_x) * ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (ray->map_x + 1 - player->pos.x) * ray->delta_dist_x;
	}
	if (ray->ray_dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (player->pos.y - ray->map_y) * ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (ray->map_y + 1 - player->pos.y) * ray->delta_dist_y;
	}
	ray->hit = false;

	while(ray->hit == false)
	{
		if(ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		if (map->grid[ray->map_y][ray->map_x] == '1')
			ray->hit = true;
	}
	if (ray->side == 0)
	{
		ray->perp_wall_dist = (ray->map_x - player->pos.x + (1 - ray->step_x) / 2) / ray->ray_dir_x;
	}
	else
	{
		ray->perp_wall_dist = (ray->map_y - player->pos.y + (1 - ray->step_y) / 2) / ray->ray_dir_y;
	}
}

int	get_wall_color(t_ray *ray)
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

void	draw_vertical_line(t_game *game, int x, t_ray *ray)
{
	int	color;
	int	y;
	int	pixel_index;

	color = get_wall_color(ray);
	y = ray->draw_start;
	while (y < ray->draw_end)
	{
		pixel_index = (y * game->frame.line_length) + (x * game->frame.bits_per_pixel / 8);
		*(int *)(game->frame.addr + pixel_index) = color;
		y++;
	}
}

void	render_scene(t_game *game, t_player *player, t_ray *ray)
{
	int	x;

	x = 0;
	while(x < SCREEN_WIDTH)
	{
		ray->camera_x = 2 * x / (double)SCREEN_WIDTH - 1;
		ray->ray_dir_x = player->dir_x + (player->plane_x * ray->camera_x);
		ray->ray_dir_y = player->dir_y + (player->plane_y * ray->camera_x);
		cast_ray(&game->player, &game->map, ray);
		ray->line_height = (int)(SCREEN_HEIGHT / ray->perp_wall_dist);
		ray->draw_start = -ray->line_height / 2 + SCREEN_HEIGHT / 2;
		if (ray->draw_start < 0)
			ray->draw_start = 0;
		ray->draw_end = ray->line_height / 2 + SCREEN_HEIGHT / 2;
		if (ray->draw_end >= SCREEN_HEIGHT)
			ray->draw_end = SCREEN_HEIGHT -1;
		draw_vertical_line(game, x, ray);
		x++;
	}
	mlx_put_image_to_window(game->mlx, game->win, game->frame.img, 0, 0);
}
