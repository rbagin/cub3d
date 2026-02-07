/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_game.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbagin <rbagin@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/01/29 14:20:53 by rbagin        #+#    #+#                 */
/*   Updated: 2026/02/06 19:25:29 by rbagin        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	init_mlx(t_game *game)
{
	game->mlx = mlx_init(SCREEN_WIDTH, SCREEN_HEIGHT, "cub3D", false);
	if (!game->mlx)
		return (print_exit(ERR_MLX, game, true), 1);
	game->frame = mlx_new_image(game->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	if (!game->frame)
		return (print_exit(ERR_MLX, game, true), 1);
	return (0);
}

static void	game_loop(void *param)
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
		SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(uint32_t));
	render_scene(game, &game->player, &ray);
}