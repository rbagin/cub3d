/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_spr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 19:05:26 by imutavdz          #+#    #+#             */
/*   Updated: 2026/02/11 06:47:16 by imutavdz         ###   ########.fr       */
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
//multiply by 4, each pxl takse 4 bytes RGBA

static uint32_t	get_spr_pxl(t_spr *s, int tex_x, int tex_y)
{
	uint8_t		*pixels;
	int			indx;
	uint32_t	color;

	if (tex_x < 0 || tex_x >= (int)s->spr_tex->width
		|| tex_y < 0 || tex_y >= (int)s->spr_tex->height)
		return (0); //calc byte idx in 1d array
	indx = (tex_y * s->spr_tex->width + tex_x) * 4;
	pixels = &s->spr_tex->pixels[indx];
	color = (pixels[0] << 24) | (pixels[1] << 16)
		| (pixels[2] << 8) | pixels[3];
	return (color);
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
