/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   textures.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbagin <rbagin@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/02/05 19:09:52 by rbagin        #+#    #+#                 */
/*   Updated: 2026/02/05 19:23:00 by rbagin        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
//Texture loading (load .png files into memory)
bool	load_textures(t_game *game)
{
	game->tex[TEX_N].texture = mlx_load_png(game->paths.no);
	game->tex[TEX_S].texture = mlx_load_png(game->paths.so);
	game->tex[TEX_W].texture = mlx_load_png(game->paths.we);
	game->tex[TEX_E].texture = mlx_load_png(game->paths.ea);
	if (!game->tex[TEX_N].texture || !game->tex[TEX_S].texture
		|| !game->tex[TEX_W].texture || !game->tex[TEX_E].texture)
		return(false);
	game->tex[TEX_N].width = game->tex[TEX_N].texture->width;
	game->tex[TEX_N].height = game->tex[TEX_N].texture->height;
	game->tex[TEX_S].width = game->tex[TEX_S].texture->width;
	game->tex[TEX_S].height = game->tex[TEX_S].texture->height;
	game->tex[TEX_W].width = game->tex[TEX_W].texture->width;
	game->tex[TEX_W].height = game->tex[TEX_W].texture->height;
	game->tex[TEX_E].width = game->tex[TEX_E].texture->width;
	game->tex[TEX_E].height = game->tex[TEX_E].texture->height;
	return (true);
}

void	free_textures(t_game *game)
{
	if (game->tex[TEX_N].texture)
		mlx_delete_texture(game->tex[TEX_N].texture);
	if (game->tex[TEX_S].texture)
		mlx_delete_texture(game->tex[TEX_S].texture);
	if (game->tex[TEX_W].texture)
		mlx_delete_texture(game->tex[TEX_W].texture);
	if (game->tex[TEX_E].texture)
		mlx_delete_texture(game->tex[TEX_E].texture);
}
