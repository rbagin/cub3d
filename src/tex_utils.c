/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tex_utils.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: imutavdz <imutavdz@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/02/05 13:31:50 by imutavdz      #+#    #+#                 */
/*   Updated: 2026/02/07 20:05:14 by imutavdz        ########   odam.nl       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// bool	load_one_t(t_game *g, int id, char *path)
// {
// 	g->tex[id].texture = mlx_load_png(path);
// 	if (!g->tex[id].texture)
// 		print_exit(ERR_TEX_LOAD, g, true);
// 	g->tex[id].width = g->tex[id].texture->width;
// 	g->tex[id].height = g->tex[id].texture->height;
// 	return (true);
// }

// void	free_textures(t_game *g)
// {
// 	if (g->tex[TEX_N].texture)
// 	{
// 		mlx_delete_texture(g->tex[TEX_N].texture);
// 		g->tex[TEX_N].texture = NULL;
// 	}
// 	if (g->tex[TEX_S].texture)
// 	{
// 		mlx_delete_texture(g->tex[TEX_S].texture);
// 		g->tex[TEX_S].texture = NULL;
// 	}
// 	if (g->tex[TEX_W].texture)
// 	{
// 		mlx_delete_texture(g->tex[TEX_W].texture);
// 		g->tex[TEX_W].texture = NULL;
// 	}
// 	if (g->tex[TEX_E].texture)
// 	{
// 		mlx_delete_texture(g->tex[TEX_E].texture);
// 		g->tex[TEX_E].texture = NULL;
// 	}
// }
