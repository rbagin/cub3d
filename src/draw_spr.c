/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_spr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 19:05:26 by imutavdz          #+#    #+#             */
/*   Updated: 2026/02/11 00:35:38 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	calc_tex_y(t_spr *s, int screen_y, int screen_h)
{
	int	d;
	int	tex_y;

	d = screen_y * 256 - screen_h * 128 + s->spr_h * 128;
	tex_y = ((d * s->spr_tex->height) / s->spr_h) / 256;
	if (tex_y < 0)
		return (0);
	return (tex_y);
}

static int	calc_tex_x(t_spr *s, int screen_x, int spr_screenx)
{
	return ((screen_x - (-s->spr_w / 2 + spr_screenx))
		* s->spr_tex->width / s->spr_w);
}

static uint32_t	get_spr_pxl(t_spr *s, int tex_x, int tex_y)
{
	uint32_t	*pixels;

	if (tex_x < 0 || tex_x >= (int)s->spr_tex->width
		|| tex_y < 0 || tex_y >= (int)s->spr_tex->height)
		return (0);
	pixels = (uint32_t *)s->spr_tex->pixels;
	return (pixels[tex_y * s->spr_tex->width + tex_x]);
}

static bool	check_zbuff(t_game *g, t_spr *s, int x)
{
	return (s->spr_y > 0 && x >= 0
		&& x < g->screen_w && s->spr_y < g->z_buff[x]);
}

void	draw_sprite(t_game *g, t_spr *s, int spr_screenx)
{
	int			x;
	int			y;
	int			tex_x;
	int			tex_y;
	uint32_t	color;

	x = s->drw_startx;
	while (x < s->drw_endx)
	{
		tex_x = calc_tex_x(s, x, spr_screenx);
		if (check_zbuff(g, s, x))
		{
			y = s->drw_starty;
			while (y < s->drw_endy)
			{
				tex_y = calc_tex_y(s, y, spr_screenx);
				color = get_spr_pxl(s, tex_x, tex_y);
				if ((color & 0x000000FF) != 0)
					mlx_put_pixel(g->frame, x, y, color);
				y++;
			}
		}
		x++;
	}
}
