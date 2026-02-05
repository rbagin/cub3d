/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   player_rotation.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbagin <rbagin@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/02/05 10:33:18 by rbagin        #+#    #+#                 */
/*   Updated: 2026/02/05 16:18:31 by rbagin        ########   odam.nl         */
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
	player->dir_x = player->dir_x * cos(-rot_speed) - player->dir_y * sin(-rot_speed);
	player->dir_y = old_dir_x * sin(-rot_speed) + player->dir_y * cos(-rot_speed);
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
	player->dir_y = old_dir_x * sin(rot_speed) + player->dir_y * cos(rot_speed);
	old_plane_x = player->plane_x;
	player->plane_x = player->plane_x * cos(rot_speed)
		- player->plane_y * sin(rot_speed);
	player->plane_y = old_plane_x * sin(rot_speed)
		+ player->plane_y * cos(rot_speed);
}

void	rotate_mouse(t_game *game, t_player *player)
{
	(void)game;
	(void)player;
}

void	handle_rotation(t_game *game)
{
	if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT))
		rotate_left(game, &game->player);
	if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT))
		rotate_right(game, &game->player);
}
