/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_raycasting.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbagin <rbagin@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/01/28 15:13:41 by rbagin        #+#    #+#                 */
/*   Updated: 2026/01/28 15:19:13 by rbagin        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>
#include <math.h>


// cc -o test_ray src/testing/test_raycasting.c src/raycasting.c -I includes -I libft -I MLX42/MLX42/include -L libft -lft -lm && ./test_ray
int	main(void)
{
	t_player	player;
	t_map		map;
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
	map.grid = test_grid;
	map.width = 9;
	map.height = 7;

	// Initialize player in the center, facing right
	player.pos.x = 4.5;
	player.pos.y = 3.5;
	player.dir_x = 1.0;
	player.dir_y = 0.0;
	player.plane_x = 0.0;
	player.plane_y = 0.66;

	// Initialize ray
	ray.camera_x = 0.0;  // Center of screen
	ray.ray_dir_x = player.dir_x + player.plane_x * ray.camera_x;
	ray.ray_dir_y = player.dir_y + player.plane_y * ray.camera_x;

	printf("Testing cast_ray function:\n");
	printf("Player position: (%.1f, %.1f)\n", player.pos.x, player.pos.y);
	printf("Player direction: (%.1f, %.1f)\n", player.dir_x, player.dir_y);
	printf("Ray direction: (%.1f, %.1f)\n\n", ray.ray_dir_x, ray.ray_dir_y);

	// Call cast_ray
	cast_ray(&player, &map, &ray);

	// Print results
	printf("Results:\n");
	printf("Hit: %s\n", ray.hit ? "true" : "false");
	printf("Side: %d (0=x-side, 1=y-side)\n", ray.side);
	printf("Wall grid position: (%d, %d)\n", ray.map_x, ray.map_y);
	printf("Perpendicular wall distance: %.2f\n", ray.perp_wall_dist);
	printf("Wall character: '%c'\n", map.grid[ray.map_y][ray.map_x]);

	return (0);
}
