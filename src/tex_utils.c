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
// 	g->tex[id].xpm = mlx_load_xpm42(path);
// 	if (!g->tex[id].xpm)
// 		print_exit(ERR_TEX_LOAD, g, true);
// 	g->tex[id].width = g->tex[id].xpm->texture.width;
// 	g->tex[id].height = g->tex[id].xpm->texture.height;
// 	return (true);
// }

bool	load_one_t(t_game *g, int id, char *path)
{
	int	fd;
	
	//  DEBUG 1: Print the path
	printf("\n=== LOADING TEXTURE %d ===\n", id);
	printf("Path: '%s'\n", path);
	printf("Path length: %zu\n", ft_strlen(path));
	
	//  DEBUG 2: Check if file exists
	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		printf(" ERROR: File does not exist or cannot be opened!\n");
		printf("   Check:\n");
		printf("   1. Does file exist? Run: ls -la %s\n", path);
		printf("   2. Is path correct?\n");
		printf("   3. Are you in the right directory?\n");
		print_exit(ERR_TEX_LOAD, g, true);
	}
	close(fd);
	printf("File exists and can be opened\n");
	
	//  DEBUG 3: Try to load XPM42
	printf("Calling mlx_load_xpm42()...\n");
	g->tex[id].xpm = mlx_load_xpm42(path);
	
	if (!g->tex[id].xpm)
	{
		printf("ERROR: mlx_load_xpm42() returned NULL\n");
		printf("   This means the XPM42 file format is INVALID\n");
		printf("   Run: cat %s\n", path);
		printf("   And check the format matches XPM42 spec\n");
		print_exit(ERR_TEX_LOAD, g, true);
	}
	
	printf(" Texture loaded successfully!\n");
	printf("   Width: %d\n", g->tex[id].xpm->texture.width);
	printf("   Height: %d\n", g->tex[id].xpm->texture.height);
	
	g->tex[id].width = g->tex[id].xpm->texture.width;
	g->tex[id].height = g->tex[id].xpm->texture.height;
	
	return (true);
}

void	free_textures(t_game *g)
{
	if (g->tex[TEX_N].xpm)
	{
		mlx_delete_xpm42(g->tex[TEX_N].xpm);
		g->tex[TEX_N].xpm = NULL;
	}
	if (g->tex[TEX_S].xpm)
	{
		mlx_delete_xpm42(g->tex[TEX_S].xpm);
		g->tex[TEX_S].xpm = NULL;
	}
	if (g->tex[TEX_W].xpm)
	{
		mlx_delete_xpm42(g->tex[TEX_W].xpm);
		g->tex[TEX_W].xpm = NULL;
	}
	if (g->tex[TEX_E].xpm)
	{
		mlx_delete_xpm42(g->tex[TEX_E].xpm);
		g->tex[TEX_E].xpm = NULL;
	}
}
