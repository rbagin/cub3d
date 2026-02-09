/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 20:31:35 by imutavdz          #+#    #+#             */
/*   Updated: 2026/02/09 21:26:01 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_dir_line(t_game *g, int center_x, int center_y)
{
	t_mini	m;
	int		i;
	int		len;

	i = 0;
	len = g->mini_tile_sz * 2;
	while (i < len)
	{ //scale dir vector
		m.end_x = center_x + (int)(g->player.dir_x * i);
		m.end_y = center_y + (int)(g->player.dir_y * i);
		if (m.end_x >= 0 && m.end_x < (int)g->img_mini->width
			&& m.end_y >= 0 && m.end_y < (int)g->img_mini->height)
			mlx_put_pixel(g->img_mini, m.end_x, m.end_y, DIR_RAY);
		i++;
	}
}
