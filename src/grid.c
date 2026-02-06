/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 17:31:24 by imutavdz          #+#    #+#             */
/*   Updated: 2026/02/06 17:36:57 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	calc_dim_map(char **lines, int m_start, int h, int w, t_game *g)
{
	int	a;
	int	b;
	int	len;

	a = 0;
	b = 0;
	while (lines[m_start])
	{
		if (is_blank_line(lines[m_start]))
			print_exit(ERR_MAP_EMPTY_LN, g, true);
		if (!is_map_line(lines[m_start]))
			print_exit(ERR_MAP_LN, g, true);
		len = (int)ft_strlen(lines[m_start]);
		if (len > w)
			b = len;
		a++;
		m_start++;
	}
	if (a == 0 || b == 0)
		print_exit(ERR_MAP_EMPTY, g, true);
	*h = a;
	*w = b;
}

char	**create_map_grid(int **lines, int m_start, int *height, int *width,  t_game *g)
{
	int		y;
	int		x;
	char	**grid;

	grid = malloc(sizeof(char *) * (h + 1));
	if (!grid)
		print_exit(ERR_MEMORY, g, true);
	y = 0;
	while (y < height)
	{
		grid[y] = malloc(width + 1);
		if (!grid[y])
			print_exit(ERR_MEMORY, g, true);
		x = 0;
		while (x < width)
		{
			grid[y][x] = ' ';
			x++;
		}
		grid[y][x] = '\0';
		x = 0;
		while (lines[m_start + y][x] && x < width)
		{
			grid[y][x] = lines[m_start + y][x];
			x++;
		}
		y++;
	}
	grid[height] = NULL;
	return (grid);
}

void	parse_map_grid(char **lines, int map_start, t_game *g)
{
	int	h;
	int	w;

	calc_dim_map(lines, map_start, &h, &w, g);
	game->map.grid = create_map_grid(lines, map_start, h, w, g);
	game->map.height = h;
	game->map.width = w;
}