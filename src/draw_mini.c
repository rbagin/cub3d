/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_mini.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 20:31:35 by imutavdz          #+#    #+#             */
/*   Updated: 2026/02/10 23:02:08 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_valid_pxl(t_game *g, int x, int y)
{
	if (x < 0 || y < 0)
		return (0);
	if (x >= (int)g->img_mini->width || y >= (int)g->img_mini->height)
		return (0);
	return (1);
}

static void	draw_dir_line(t_game *g, int x, int y, int radius)
{
	int		dx;
	int		dy;
	int		dist_sq;

	dy = -radius;
	while (dy <= radius)
	{
		dx = -radius;
		while (dx <= radius)
		{
			dist_sq = (dx * dx) + (dy * dy);
			if (dist_sq <= (radius * radius))
			{
				if (is_valid_pxl(g, x + dx, y + dy))
					mlx_put_pixel(g->img_mini, x + dx, y + dy, DIR_RAY);
			}
			dx++;
		}
		dy++;
	}
}

void	calc_dir_line(t_game *g, int center_x, int center_y)
{
	t_mini	m;
	int		i;
	int		len;

	i = 0;
	len = g->mini_tile_sz;
	m.size = 3;
	while (i < len)
	{ //scale dir vector
		m.end_x = center_x + (int)(g->player.dir_x * i);
		m.end_y = center_y + (int)(g->player.dir_y * i);
		draw_dir_line(g, m.end_x, m.end_y, m.size);
		i++;
	}
}

static void	draw_sp_dot(t_game *g, t_spr *sp)
{
	int		dx;
	int		dy;
	int		x;
	int		y;

	dy = -1;
	while (dy <= 1)
	{
		dx = -1;
		while (dx <= 1)
		{
			x = sp->screen_x + dx;
			y = sp->screen_y + dy;
			if (is_inside(g, x, y))
				mlx_put_pixel(g->img_mini, x, y, SPR_DOT);
			dx++;
		}
		dy++;
	}
}

void	draw_mini_spr(t_game *g)
{
	t_spr	*sp;

	sp = g->sprite;
	sp->screen_x = (int)((sp->x - g->player.pos.x + g->mini_view_range)
			* g->mini_tile_sz);
	sp->screen_y = (int)((sp->y - g->player.pos.y + g->mini_view_range)
			*g->mini_tile_sz);
	if (sp->screen_x >= 0 && sp->screen_x < (int)g->img_mini->width
		&& sp->screen_y >= 0 && sp->screen_y < (int)g->img_mini->height)
		draw_sp_dot(g, sp);
}
