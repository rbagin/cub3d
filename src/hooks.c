/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 18:51:43 by imutavdz          #+#    #+#             */
/*   Updated: 2026/02/08 11:37:28 by imutavdz         ###   ########.fr       */
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

void	game_loop(void *param)
{
	t_game	*game;
	t_ray	ray;

	game = (t_game *)param;
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
	{
		mlx_close_window(game->mlx);
		return ;
	}
	handle_movement(game);
	handle_rotation(game);
	ft_bzero(game->frame->pixels,
		game->screen_w * game->screen_h * sizeof(uint32_t));
	render_scene(game, &game->player, &ray);
}
//register all hooks
//init mouse position for rotation
void	setup_hooks(t_game *g)
{
	mlx_loop_hook(g->mlx, &game_loop, g);
	g->player.last_mouse_x = g->screen_w / 2;
	mlx_set_cursor_mode(g->mlx, MLX_MOUSE_HIDDEN);
	mlx_set_mouse_pos(g->mlx, g->screen_w / 2, g->screen_h / 2);
}
