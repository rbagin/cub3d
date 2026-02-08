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

int	init_mlx(t_game *game)
{
	game->mlx = mlx_init(game->screen_w, game->screen_h, "cub3D", false);
	if (!game->mlx)
		return (print_exit(ERR_MLX, game, true), 1);
	game->frame = mlx_new_image(game->mlx, game->screen_w, game->screen_h);
	if (!game->frame)
		return (print_exit(ERR_MLX, game, true), 1);
	return (0);
}

