/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_doors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 13:58:40 by imutavdz          #+#    #+#             */
/*   Updated: 2026/02/18 02:01:24 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	find_doors(t_game *g)
{
	int	x;
	int	y;
	int	count;

	count = 0;
	y = 0;
	while (y < g->map.height)
	{
		x = 0;
		while (x < g->map.width)
		{
			if (g->map.grid[y][x] == 'D')
				count++;
			x++;
		}
		y++;
	}
	if (count == 0)
		return ;
	init_door(g, count);
}

static bool	open_door(t_game *g, int x, int y)
{
	int	i;

	i = pos_door(g, x, y);
	if (i == -1)
		return (false);
	return (g->door[i].open);
}

bool	hit_door(t_game *g, int x, int y)
{
	if (is_out_of_bonds(map, x, y))
		return (false);
	if (map->grid[y][x] != 'D')
		return (false);
	return (!open_door(g, x, y));
}
