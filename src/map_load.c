/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_load.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 17:43:12 by imutavdz          #+#    #+#             */
/*   Updated: 2026/02/05 13:46:25 by imutavdz         ###   ########.fr       */
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
		y++;
	}
	grid[h] = NULL;
	g->map.grid = grid;
	g->map.height = h;
	g->map.width = w;
}

static char	*read_file(int fd, t_game *g)
{
	char	*line;
	char	*full_str;
	char	*store;

	full_str = ft_strdup("");
	if (!full_str)
		print_exit(ERR_MEMORY, g, false);
	line = get_next_line(fd);
	while (line)
	{
		store = ft_strjoin(full_str, line);
		free(full_str);
		free(line);
		if (!store)
			print_exit(ERR_MEMORY, g, false);
		full_str = store;
		line = get_next_line(fd);
	}
	if (ft_strlen(full_str) == 0)
	{
		free(full_str);
		print_exit(ERR_MAP_EMPTY, g, false);
	}
	return (full_str);
}

static bool	*valid_filname(const char *filename) //different input
{
	char	*dot;

	if (!filename)
		return (false);
	dot = ft_strrchr(filename, '.');
	if (!dot)
		return (false);
	return (ft_strncmp(dotm ".cub", 5) == 0);
}

static int	open_map(const char *name, t_game *g)
{
	int	fd;

	if (!valid_filname(name))
		print_exit(ERR_MAP_EXT);
	fd = open(name, O_RDONLY);
	if (fd < 0)
		print_exit(ERR_MAP_OPEN, g, false);
	return (fd);
}

bool	load_map(t_game *g, const char *filename)
{
	int		fd;
	char	*content;
	char	**lines;
	int		m_start;

	path = find_map(filename);
	if (!path)
		print_exit(ERR_MAP_EXT, g, false);
	fd = open_map(filename, g);
	content = read_file(fd, g);
	close(fd);
	lines = split_lines(content, game);
	free(content);
	m_start = parse_header(lines, g);
	check_identif(g);
	parse_grid(lines, m_start, g);
	find_spawn(g);
	free_lines(lines);
	return (true);
}
