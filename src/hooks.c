/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 18:51:43 by imutavdz          #+#    #+#             */
/*   Updated: 2026/02/07 11:46:12 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// t_input flags key press - update every move/rotate
/* Input hooks (WASD movement)
hooks + loop

key press: set flags in g->inp

key release: unset flags

loop hook:

compute dt

update_player(g, dt) (movement+rotation+collision)

render(g) (ceiling/floor + rays + textures)

put image to window*/

static void	key_press(mlx_key_data_t keydata, void *param)
{
	t_game	*g;

	g = (t_game *)param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(g->mlx);
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		g->inp.w = true;
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_RELEASE)
		g->inp.w = false;
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		g->inp.s = true;
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_RELEASE)
		g->inp.s = false;
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		g->inp.a = true;
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_RELEASE)
		g->inp.a = false;
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		g->inp.d = true;
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_RELEASE)
		g->inp.d = false;
	if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS)
		g->inp.right = true;
	if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_RELEASE)
		g->inp.right = false;
	if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
		g->inp.left = true;
	if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_RELEASE)
		g->inp.left = false;
}
