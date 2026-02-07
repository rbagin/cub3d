/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: imutavdz <imutavdz@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/01/23 16:29:24 by imutavdz      #+#    #+#                 */
/*   Updated: 2026/02/06 20:26:06 by rbagin        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_g_struct(t_game *g)
{
	ft_bzero(g, sizeof(*g));
	g->screen_w = SCREEN_WIDTH;
	g->screen_h = SCREEN_HEIGHT;
}

int	main(int argc, char const *argv[])
{
	t_game	game;

	if (argc != 2)
		return (print_exit(ERR_ARGS, NULL, false), 1);
	init_g_struct(&game);
	load_map(&game, argv[1]); //exit inside func
	//validation (map closed/ 1spawn / all ids present / rgb valid)
	// if (!valid_cub(&game))
	// 	return (cleanup(&game), 1);
	//initialisation
	if (init_mlx(&game))
		return (1);
	if (mlx_image_to_window(game.mlx, game.frame, 0, 0) < 0)
		return (print_exit(ERR_MLX, &game, true), 1);
	mlx_loop_hook(game.mlx, game_loop, &game);
	mlx_loop(game.mlx);
	mlx_terminate(game.mlx); //kills wind and img
	final_cleanup(&game); //kills grid and paths
	return (0);
}
