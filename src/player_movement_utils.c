/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   player_movement_utils.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbagin <rbagin@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/02/05 10:25:28 by rbagin        #+#    #+#                 */
/*   Updated: 2026/02/06 20:33:56 by rbagin        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#define COLISION_MAR 0.05

static bool	is_wall(t_map *map, int x, int y)
{
	if (y < 0 || y >= map->height || x < 0 || x >= map->width)
		return (true);
	return (map->grid[y][x] == '1' || map->grid[y][x] == ' ');
}

bool	is_valid_position(t_game *game, double x, double y)
{
	t_map	*map;

	map = &game->map;
	if (is_wall(map, (int)(x - COLISION_MAR), (int)(y - COLISION_MAR)))
		return (false);
	if (is_wall(map, (int)(x + COLISION_MAR), (int)(y - COLISION_MAR)))
		return (false);
	if (is_wall(map, (int)(x - COLISION_MAR), (int)(y + COLISION_MAR)))
		return (false);
	if (is_wall(map, (int)(x + COLISION_MAR), (int)(y + COLISION_MAR)))
		return (false);
	return (true);
}
