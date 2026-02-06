/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   grid.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: imutavdz <imutavdz@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/02/06 17:31:24 by imutavdz      #+#    #+#                 */
/*   Updated: 2026/02/06 20:06:19 by rbagin        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	calc_dim_map(char **lines, int m_start, int *height, int *w, t_game *g)
{
	int	h;
	int	len;
	int	max_width;

	h = 0;
	max_width = 0;
	while (lines[m_start + h])
	{
		if (is_blank_line(lines[m_start + h]))
			print_exit(ERR_MAP_EMPTY_LN, g, true);
		if (!is_map_line(lines[m_start + h]))
			print_exit(ERR_MAP_LN, g, true);
		len = (int)ft_strlen(lines[m_start + h]);
		if (len > max_width)
			max_width = len;
		h++;
	}
	if (h == 0 || max_width == 0)
		print_exit(ERR_MAP_EMPTY, g, true);
	*height = h;
	*w = max_width;
}

char	**create_map_grid(char **lines, int m_start, int h, int w,  t_game *g)
{
	int		y;
	int		x;
	char	**grid;

	grid = malloc(sizeof(char *) * (h + 1));
	if (!grid)
		print_exit(ERR_MEMORY, g, true);
	y = 0;
	while (y < h)
	{
		grid[y] = malloc(w + 1);
		if (!grid[y])
			print_exit(ERR_MEMORY, g, true);
		x = 0;
		while (x < w)
		{
			grid[y][x] = ' ';
			x++;
		}
		grid[y][x] = '\0';
		x = 0;
		while (lines[m_start + y][x] && x < w)
		{
			grid[y][x] = lines[m_start + y][x];
			x++;
		}
		y++;
	}
	grid[h] = NULL;
	return (grid);
}

void	parse_map_grid(char **lines, int map_start, t_game *game)
{
	int	h;
	int	w;

	calc_dim_map(lines, map_start, &h, &w, game);
	game->map.grid = create_map_grid(lines, map_start, h, w, game);
	game->map.height = h;
	game->map.width = w;
}
