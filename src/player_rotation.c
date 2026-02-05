/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   player_rotation.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbagin <rbagin@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/02/05 10:33:18 by rbagin        #+#    #+#                 */
/*   Updated: 2026/02/05 19:56:48 by rbagin        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#define ROTATION_SPEED 3.0

void	rotate_left(t_game *game, t_player *player)
{
	double	old_dir_x;
	double	old_plane_x;
	double	rot_speed;

	rot_speed = ROTATION_SPEED * game->mlx->delta_time;
	old_dir_x = player->dir_x;
	player->dir_x = player->dir_x * cos(-rot_speed)
		- player->dir_y * sin(-rot_speed);
	player->dir_y = old_dir_x * sin(-rot_speed)
		+ player->dir_y * cos(-rot_speed);
	old_plane_x = player->plane_x;
	player->plane_x = player->plane_x * cos(-rot_speed)
		- player->plane_y * sin(-rot_speed);
	player->plane_y = old_plane_x * sin(-rot_speed)
		+ player->plane_y * cos(-rot_speed);
}

void	rotate_right(t_game *game, t_player *player)
{
	double	old_dir_x;
	double	old_plane_x;
	double	rot_speed;

	rot_speed = ROTATION_SPEED * game->mlx->delta_time;
	old_dir_x = player->dir_x;
	player->dir_x = player->dir_x * cos(rot_speed)
		- player->dir_y * sin(rot_speed);
	player->dir_y = old_dir_x * sin(rot_speed)
		+ player->dir_y * cos(rot_speed);
	old_plane_x = player->plane_x;
	player->plane_x = player->plane_x * cos(rot_speed)
		- player->plane_y * sin(rot_speed);
	player->plane_y = old_plane_x * sin(rot_speed)
		+ player->plane_y * cos(rot_speed);
}

void	rotate_mouse(t_game *game, t_player *player)
{
	int32_t	mouse_x;
	int32_t	mouse_y;
	int32_t	delta_x;
	double	rotation_angle;
	double	old_dir_x;
	double	old_plane_x;

	mlx_get_mouse_pos(game->mlx, &mouse_x, &mouse_y);
	delta_x = mouse_x - player->last_mouse_x;
	if (delta_x == 0)
	{
		player->last_mouse_x = mouse_x;
		return ;
	}
	rotation_angle = delta_x * 0.002;
	old_dir_x = player->dir_x;
	player->dir_x = player->dir_x * cos(rotation_angle)
		- player->dir_y * sin(rotation_angle);
	player->dir_y = old_dir_x * sin(rotation_angle)
		+ player->dir_y * cos(rotation_angle);
	old_plane_x = player->plane_x;
	player->plane_x = player->plane_x * cos(rotation_angle)
		- player->plane_y * sin(rotation_angle);
	player->plane_y = old_plane_x * sin(rotation_angle)
		+ player->plane_y * cos(rotation_angle);
	player->last_mouse_x = mouse_x;
	mlx_set_mouse_pos(game->mlx, game->screen_w / 2, game->screen_h / 2);
	player->last_mouse_x = game->screen_w / 2;
}

void	handle_rotation(t_game *game)
{
	if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT))
		rotate_left(game, &game->player);
	if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT))
		rotate_right(game, &game->player);
	rotate_mouse(game, &game->player);
}
