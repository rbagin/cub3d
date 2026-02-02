/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_raycasting.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbagin <rbagin@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/01/28 15:13:41 by rbagin        #+#    #+#                 */
/*   Updated: 2026/02/02 19:38:09 by rbagin        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>
#include <math.h>


void	key_hook(mlx_key_data_t keydata, void *param)
{
    t_game	*game;

    game = (t_game *)param;
    if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
        mlx_close_window(game->mlx);
}

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
	game.player.dir_x = 0.0;
	game.player.dir_y = -1.0;
	game.player.plane_x = 0.0;
	game.player.plane_y = 0.66;

    // Initialize MLX42
    game.mlx = mlx_init(SCREEN_WIDTH, SCREEN_HEIGHT, "Cub3d Test", true);
    if (!game.mlx)
    {
        printf("Error: MLX42 init failed\n");
        return (1);
    }

    // Create image
    game.frame.img = mlx_new_image(game.mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
    if (!game.frame.img)
    {
        printf("Error: Image creation failed\n");
        mlx_terminate(game.mlx);
        return (1);
    }

    // Put image to window
    if (mlx_image_to_window(game.mlx, game.frame.img, 0, 0) < 0)
    {
        printf("Error: Image to window failed\n");
        mlx_terminate(game.mlx);
        return (1);
    }

    // Render the scene
    render_scene(&game, &game.player, &ray);

    // Set up key hook for ESC
    mlx_key_hook(game.mlx, key_hook, &game);

    // Start the loop
    mlx_loop(game.mlx);

    // Cleanup
    mlx_terminate(game.mlx);
	return (0);
}
