/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   player_movement.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: ravi-bagin <ravi-bagin@student.codam.nl      +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/02/03 13:13:21 by ravi-bagin    #+#    #+#                 */
/*   Updated: 2026/02/05 16:18:37 by rbagin        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#define SPEED 1.5

/*
	TO-DO:
	Player rotation - You have no functions to rotate the player when using arrow
	keys or A/D keys (depending on your control scheme). You need to rotate both
	the direction vector (dir_x, dir_y) and the camera plane (plane_x, plane_y).

	Frame-rate independence - Your SPEED * game->mlx->delta_time is a constant, which means movement SPEED * game->mlx->delta_time
	will depend on your frame rate. You should multiply SPEED * game->mlx->delta_time by game->mlx->delta_time to make
	movement consistent across different frame rates.

	Exit/close handling - No ESC key handler to close the window gracefully.

	Collision buffer - When checking valid positions, you might want a small
	buffer/margin from walls to prevent the player from getting too close or stuck.
*/

void	move_forward(t_game *game, t_player *player)
{
	double	new_pos_x;
	double	new_pos_y;

	new_pos_x = player->pos.x + player->dir_x * SPEED * game->mlx->delta_time;
	new_pos_y = player->pos.y + player->dir_y * SPEED * game->mlx->delta_time;
	if (is_valid_position(game, new_pos_x, player->pos.y))
		player->pos.x = new_pos_x;
	if (is_valid_position(game, player->pos.x, new_pos_y))
		player->pos.y = new_pos_y;
}

void	move_backward(t_game *game, t_player *player)
{
	double	new_pos_x;
	double	new_pos_y;

	new_pos_x = player->pos.x - player->dir_x * SPEED * game->mlx->delta_time;
	new_pos_y = player->pos.y - player->dir_y * SPEED * game->mlx->delta_time;
	if (is_valid_position(game, new_pos_x, player->pos.y))
		player->pos.x = new_pos_x;
	if (is_valid_position(game, player->pos.x, new_pos_y))
		player->pos.y = new_pos_y;
}

void	move_left(t_game *game, t_player *player)
{
	double	new_pos_x;
	double	new_pos_y;

	new_pos_x = player->pos.x - player->plane_x * SPEED * game->mlx->delta_time;
	new_pos_y = player->pos.y - player->plane_y * SPEED * game->mlx->delta_time;
	if (is_valid_position(game, new_pos_x, player->pos.y))
		player->pos.x = new_pos_x;
	if (is_valid_position(game, player->pos.x, new_pos_y))
		player->pos.y = new_pos_y;
}

void	move_right(t_game *game, t_player *player)
{
	double	new_pos_x;
	double	new_pos_y;

	new_pos_x = player->pos.x + player->plane_x * SPEED * game->mlx->delta_time;
	new_pos_y = player->pos.y + player->plane_y * SPEED * game->mlx->delta_time;
	if (is_valid_position(game, new_pos_x, player->pos.y))
		player->pos.x = new_pos_x;
	if (is_valid_position(game, player->pos.x, new_pos_y))
		player->pos.y = new_pos_y;
}

void	handle_movement(t_game *game)
{
	if (mlx_is_key_down(game->mlx, MLX_KEY_W))
		move_forward(game, &game->player);
	if (mlx_is_key_down(game->mlx, MLX_KEY_S))
		move_backward(game, &game->player);
	if (mlx_is_key_down(game->mlx, MLX_KEY_A))
		move_left(game, &game->player);
	if (mlx_is_key_down(game->mlx, MLX_KEY_D))
		move_right(game, &game->player);
}
