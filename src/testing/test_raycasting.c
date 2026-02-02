/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_raycasting.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbagin <rbagin@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/01/28 15:13:41 by rbagin        #+#    #+#                 */
/*   Updated: 2026/02/02 12:38:20 by ravi-bagin    ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>
#include <math.h>


// cc -o test_ray src/testing/test_raycasting.c src/raycasting.c -I includes -I libft -I MLX42/MLX42/include -L libft -lft -lm && ./test_ray
int	main(void)
{
	t_game		game;
	t_ray		ray;
	char		*test_grid[] = {
		"111111111",
		"100000001",
		"100000001",
		"100010001",
		"100000001",
		"100000001",
		"111111111",
		NULL
	};

	// Initialize map
	game.map.grid = test_grid;
	game.map.width = 9;
	game.map.height = 7;

	// Initialize player in the center, facing right
	game.player.pos.x = 4.5;
	game.player.pos.y = 3.5;
	game.player.dir_x = 1.0;
	game.player.dir_y = 0.0;
	game.player.plane_x = 0.0;
	game.player.plane_y = 0.66;

	mlx_init(SCREEN_WIDTH, SCREEN_HEIGHT, "Cub3d", false);
	mlx_new_window();
	mlx_new_image(game.mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	mlx_init_image();
	render_scene(&game, &game.player, &ray);
	mlx_put_image_to_window();
	mlx_loop(game.mlx);

	return (0);
}
