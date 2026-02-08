/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   player_rotation.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbagin <rbagin@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/02/05 10:33:18 by rbagin        #+#    #+#                 */
/*   Updated: 2026/02/06 20:36:01 by rbagin        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#define ROTATION_SPEED 3.0

void	rotate_left(t_game *game, t_player *p)
{
	double	old_dir_x;
	double	old_plane_x;
	double	speed;

	speed = ROTATION_SPEED * game->mlx->delta_time;
	old_dir_x = p->dir_x;
	p->dir_x = p->dir_x * cos(-speed) - p->dir_y * sin(-speed);
	p->dir_y = old_dir_x * sin(-speed) + p->dir_y * cos(-speed);
	old_plane_x = p->plane_x;
	p->plane_x = p->plane_x * cos(-speed) - p->plane_y * sin(-speed);
	p->plane_y = old_plane_x * sin(-speed) + p->plane_y * cos(-speed);
}

void	rotate_right(t_game *game, t_player *p)
{
	double	old_dir_x;
	double	old_plane_x;
	double	speed;

	speed = ROTATION_SPEED * game->mlx->delta_time;
	old_dir_x = p->dir_x;
	p->dir_x = p->dir_x * cos(speed)
		- p->dir_y * sin(speed);
	p->dir_y = old_dir_x * sin(speed)
		+ p->dir_y * cos(speed);
	old_plane_x = p->plane_x;
	p->plane_x = p->plane_x * cos(speed)
		- p->plane_y * sin(speed);
	p->plane_y = old_plane_x * sin(speed)
		+ p->plane_y * cos(speed);
}

void	handle_rotation(t_game *game)
{
	if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT))
		rotate_left(game, &game->player);
	if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT))
		rotate_right(game, &game->player);
}
