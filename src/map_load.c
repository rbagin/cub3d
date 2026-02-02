/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_load.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 17:43:12 by imutavdz          #+#    #+#             */
/*   Updated: 2026/02/02 13:37:27 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	*read_map_lines(int fd, t_game *g)
{
	char	*line;
	char	*full_str;
	char	*store;

	full_str = ft_strdup("");
	if (!full_str)
		print_exit(ERR_MEMORY, g, false);
	line = get_next_line(fd);
	if (!line && ft_strlen(full_str) == 0)
	{
		free(full_str);
		print_exit(ERR_MAP_EMPTY, g, false);
	}
	scene_check(game);
	while (line != NULL)
	{
		store = ft_strjoin(full_str, line);
		free(full_str);
		free(line);
		if (!store)
			print_exit(ERR_MEMORY, g, false);
		full_str = store;
		line = get_next_line(fd);
	}
	return (full_str);
}

static void	calc_dim_map(char **lines, int m_start, int h, int w, t_game *g)
{
	int	a;
	int	b;
	int	len;

	a = 0;
	b = 0;
	while (lines[m_start])
	{
		if (is_blank_line(line[m_start]))
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

char	**str_to_grid(int fd, int *height, t_game *g)
{
	int		h;
	int		w;
	int		y;
	int		x;
	char	**grid;

	calc_dim_map(lines, m_start, &h, &w, g);
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
		while (lines[m_start + y][x])
		{
			grid[y][x] = lines[m_start + y][x];
			x++;
		}
	}
	grid[h] = NULL;
	g->map.grid = grid;
	g->map.height = h;
	g->map.width = w;
}

static bool	*find_map(const char *map_name) //different input
{
	char	*dot;
	char	*holder;

	dot = ft_strrchr(map_name, '.');
	if (!dot || ft_strncmp(dot, ".cub", 5))
		return (NULL);
	holder = ft_strjoin("maps/path/", map_name);
	if (!holder)
		return (NULL);
	return (holder);
}

static int	open_map(const char *name, t_game *g)
{
	int	fd;

	fd = open(name, O_RDONLY);
	if (fd < 0)
		print_exit(ERR_MAP_OPEN, g, false);
	return (fd);
}

bool	load_map(t_game *g, const char *filename)
{
	int		fd;
	char	*path;
	char	**lines;
	int		m_start;

	path = find_map(filename);
	if (!path)
		print_exit(ERR_MAP_EXT, g, false);
	fd = open_map(path, g);
	free(path);
	m_start = parse_header(lines, g);
	check_identif(g);
	g->map.grid = str_to_grid(fd, &g->map.height, g);
	close(fd);
	if (!g->map.grid)
		return (false);
	find_spawn(g);
	return (true);
}
