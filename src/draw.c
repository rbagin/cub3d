/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 20:31:35 by imutavdz          #+#    #+#             */
/*   Updated: 2026/02/10 09:55:03 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_dir_line(t_game *g, int center_x, int center_y)
{
	t_mini	m;
	int		i;
	int		len;
	int		offset;

	i = 0;
	len = g->mini_tile_sz * 2;
	while (i < len)
	{ //scale dir vector
		m.end_x = center_x + (int)(g->player.dir_x * i);
		m.end_y = center_y + (int)(g->player.dir_y * i);
		offset = -1;
		while (offset <= 1)
		{
			x = m.end_x + offset;
			y = m.end_y + offset;
			if (x >= 0 && x < (int)g->img_mini->width
				&& y >= 0 && y < (int)g->img_mini->height)
				mlx_put_pixel(g->img_mini, x, y, DIR_RAY);
			offset++;
		}
		i++;
	}
}
