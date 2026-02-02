/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   raycasting.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbagin <rbagin@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/01/28 12:43:35 by rbagin        #+#    #+#                 */
/*   Updated: 2026/01/28 15:01:39 by rbagin        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */
// (y, x);
// x = vertical; collumns
// y = horisontal; rows
//raycasting logic
// #include "cub3d.h"

// t_player	*init_player(t_player *player, t_map *map, t_ray *ray)
// {
	
// }

// void	cast_ray(t_player *player, t_map *map, t_ray *ray)
// {
// 	ray->map_x = floor(player->pos.x);
// 	ray->map_y = floor(player->pos.y);

// 	ray->delta_dist_x = absolute(1 / player->dir_x);
// 	ray->delta_dist_y = absolute(1 / player->dir_y);

// 	if (player->dir_x < 0)
// 	{
// 		ray->step_x = -1;
// 		ray->side_dist_x = (player->pos.x - ray->map_x) * ray->delta_dist_x;
// 	}
// 	else
// 	{
// 		ray->step_x = 1;
// 		ray->side_dist_x = (ray->map_x + 1 - player->pos.x) * ray->delta_dist_x;
// 	}
// 	if (player->dir_y < 0)
// 	{
// 		ray->step_y = -1;
// 		ray->side_dist_y = (player->pos.y - ray->map_y) * ray->delta_dist_y;
// 	}
// 	else
// 	{
// 		ray->step_y = 1;
// 		ray->side_dist_y = (ray->map_y + 1 - player->pos.y) * ray->delta_dist_y;
// 	}
// 	ray->hit = false;
// 	while(ray->hit == false)
// 	{
// 		if(ray->side_dist_x < ray->side_dist_y)
// 		{
// 			ray->side_dist_x += ray->delta_dist_x;
// 			ray->map_x += ray->step_x;
// 			ray->side = 0;
// 		}
// 		else
// 		{
// 			ray->side_dist_y += ray->delta_dist_y;
// 			ray->map_y += ray->step_y;
// 			ray->side = 1;
// 		}
// 		if (map->grid[ray->map_x][ray->map_y] == '1')
// 			ray->hit = true;
// 	}
// 	if (ray->side == 0)
// 	{
// 		ray->perp_wall_dist = (ray->map_x - player->pos.x + (1 - ray->step_x) / 2) / player->dir_x;
// 	}
// 	else
// 	{
// 		ray->perp_wall_dist = (ray->map_y - player->pos.y + (1 - ray->step_y) / 2) / player->dir_y;
// 	}
// }
