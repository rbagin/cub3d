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

static void	init_g_struct(t_game *game)
{
	ft_bzero(game, sizeof(*game));
	game->screen_w = SCREEN_WIDTH;
	game->screen_h = SCREEN_HEIGHT;
}

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
	if(mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
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

int	main(int argc, char const *argv[])
{
	t_game	game;

	//parsing (reads file + fills paths/color/map/player)
	if (argc != 2)
		return (print_exit(ERR_ARGS, NULL, false), 1);
	init_g_struct(&game);
	if (!load_map(&game, argv[1]))
		// return (cleanup(game), 1);
		return (1);
	//validation (map closed/ 1spawn / all ids present / rgb valid)
	// if (!valid_cub(&game))
	// 	return (cleanup(&game), 1);
	//initialisation
	if (init_mlx(&game))
		// return (cleanup(&game), 1);
		return (1);
	if (mlx_image_to_window(game.mlx, game.frame, 0, 0) < 0)
		return (print_exit(ERR_MLX, &game, true), 1);
	mlx_loop_hook(game.mlx, game_loop, &game);
	mlx_loop(game.mlx);
	mlx_terminate(game.mlx);
	// celanup(&game);
	return (0);
}
