/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_load.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 17:43:12 by imutavdz          #+#    #+#             */
/*   Updated: 2026/01/25 18:17:22 by imutavdz         ###   ########.fr       */
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

char	**str_to_grid(int fd, int *height, t_game *g)
{
	char	*found_s;
	char	**grid;

	found_s = read_map_lines(fd, g);
	if (ft_strnstr(found_s, "\n\n", ft_strlen(found_s)))
	{
		free(found_s);
		print_exit(ERR_MAP_CHARS, g, false);
	}
	grid = ft_split(found_s, '\n');
	free(found_s);
	if (!grid)
		print_exit(ERR_MEMORY, g, false);
	*height = 0;
	while (grid[*height])
		(*holder)++;
	if (*height == 0)
	{
		free_grid(grid, 0);
		print_exit(ERR_MAP_EMPTY, g, false);
	}
	return (grid);
}

char	*find_map(const char *map_name)
{
	char	*dot;
	char	*holder;

	dot = ft_strrchr(map_name, '.');
	if (!dot || ft_strncmp(dot, ".cub", 5))
		return (NULL);
	holder = ft_strjoin("maps/", map_name);
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

bool	lead_map(t_game *g, const char *filename)
{
	int		fd;
	char	*path;

	path = find_map(filename);
	if (!path)
		print_exit(ERR_MAP_EXT, g, false);
	fd = open_map(path, g);
	free(path);
	g->map.grid = str_to_grid(fd, &g->map.height, g);
	close(fd);
	if (!g->map.grid)
		return (false);
	g->player.pos = g->map.player_p;
	return (true);
}
