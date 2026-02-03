/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   player_movement.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: ravi-bagin <ravi-bagin@student.codam.nl      +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/02/03 13:13:21 by ravi-bagin    #+#    #+#                 */
/*   Updated: 2026/02/03 14:32:53 by ravi-bagin    ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#define speed 0.5

/*
	TO-DO:
	Player rotation - You have no functions to rotate the player when using arrow
	keys or A/D keys (depending on your control scheme). You need to rotate both
	the direction vector (dir_x, dir_y) and the camera plane (plane_x, plane_y).

	Frame-rate independence - Your speed is a constant, which means movement speed
	will depend on your frame rate. You should multiply speed by delta_time to make
	movement consistent across different frame rates.

	Exit/close handling - No ESC key handler to close the window gracefully.

	Collision buffer - When checking valid positions, you might want a small
	buffer/margin from walls to prevent the player from getting too close or stuck.
*/

static bool	is_valid_position(t_game *game, double x, double y)
{
	
}

void	move_forward(t_game *game, t_player *player)
{
	double	new_pos_x;
	double	new_pos_y;

	new_pos_x = player->pos.x + player->dir_x * speed;
	new_pos_y = player->pos.y + player->dir_y * speed;
	if (is_valid_position(game, new_pos_x, player->pos.y))
		player->pos.x = new_pos_x;
	if (is_valid_position(game, player->pos.x, new_pos_y))
		player->pos.y = new_pos_y;
}

void	move_backward(t_game *game, t_player *player)
{
	double	new_pos_x;
	double	new_pos_y;

	new_pos_x = player->pos.x - player->dir_x * speed;
	new_pos_y = player->pos.y - player->dir_y * speed;
	if (is_valid_position(game, new_pos_x, player->pos.y))
		player->pos.x = new_pos_x;
	if (is_valid_position(game, player->pos.x, new_pos_y))
		player->pos.y = new_pos_y;
}

void	move_left(t_game *game, t_player *player)
{
	double	new_pos_x;
	double	new_pos_y;

	new_pos_x = player->pos.x - player->plane_x * speed;
	new_pos_y = player->pos.y - player->plane_y * speed;
	if (is_valid_position(game, new_pos_x, player->pos.y))
		player->pos.x = new_pos_x;
	if (is_valid_position(game, player->pos.x, new_pos_y))
		player->pos.y = new_pos_y;
}

void	move_right(t_game *game, t_player *player)
{
	double	new_pos_x;
	double	new_pos_y;

	new_pos_x = player->pos.x + player->plane_x * speed;
	new_pos_y = player->pos.y + player->plane_y * speed;
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
