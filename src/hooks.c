/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 18:51:43 by imutavdz          #+#    #+#             */
/*   Updated: 2026/02/09 19:47:07 by imutavdz         ###   ########.fr       */
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
	t_game			*g;
	t_ray			ray;

	g = (t_game *)param;
	if (mlx_is_key_down(g->mlx, MLX_KEY_ESCAPE))
	{
		mlx_close_window(g->mlx);
		return ;
	}
	if (mlx_is_key_down(g->mlx, MLX_KEY_M))
	{
		if (!g->m_key_pressed)
		{
			g->show_minimap = !g->show_minimap;
			g->m_key_pressed = true;
		}
	}
	else
		g->m_key_pressed = false;
	handle_movement(g);
	handle_rotation(g);
	ft_bzero(g->frame->pixels, g->screen_w * g->screen_h * sizeof(uint32_t));
	render_scene(g, &g->player, &ray);
	if (g->show_minimap)
		draw_minimap(g);
}

static void	key_press(mlx_key_data_t keydata, void *param)
{
	t_game	*g;

	g = (t_game *)param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.key == MLX_PRESS)
		mlx_close_window(g->mlx);
		//toggle minimap with M
	if (keydata.key == MLX_KEY_M && keydata.key == MLX_PRESS)
		g->show_minimap = !g->show_minimap;
}
//register all hooks
//init mouse position for rotation
void	setup_hooks(t_game *g)
{
	mlx_key_hook(g->mlx, &key_press, g);
	mlx_loop_hook(g->mlx, &game_loop, g);
	g->player.last_mouse_x = g->screen_w / 2;
	mlx_set_cursor_mode(g->mlx, MLX_MOUSE_HIDDEN);
	mlx_set_mouse_pos(g->mlx, g->screen_w / 2, g->screen_h / 2);
}
