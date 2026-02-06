/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 17:42:59 by imutavdz          #+#    #+#             */
/*   Updated: 2026/02/06 17:38:44 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	is_blank_line(const char *line)
{
	while (*line)
	{
		if (*line != ' ' && *line != '\t' && *line != '\n')
			return (false);
		line++;
	}
	return (true);
}

bool	is_map_line(const char *line)
{
	while (*line == ' ' || *line == '\t')
		line++;
	return (*line == '1' || *line == '0' || *line == ' ');
}

// bool	parse_valid_map(t_game *game)
// {
// 	if (!game->map.grid[0] || game->map.height <= 0)
// 		print_exit(ERR_MAP_EMPTY, game, true);
// }
static int	count_lines(const char *str)
{
	int	count;

	count = 0;
	if (!str || !*str)
		return (0);
	while (*str)
	{
		if (*str == '\n')
			count++;
		str++;
	}
	if (*(str- 1) != '\n')
		count++;
	return (count);
}

static char	*extract_line(const char *start, const char *end)
{
	size_t	len;
	char	*line;
	size_t	i;

	len = end - start;
	line = malloc(len + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (i < len)
	{
		line[i] = start[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	**split_lines(char *file_str, t_game *g)
{
	char		**lines;
	int			line_count;
	int			i;
	const char	*start;
	const char	*curr;

	if (!file_str)
		print_exit(ERR_MEMORY, g, false);
	line_count = count_lines(file_str);
	if (line_count == 0)
		print_exit(ERR_MAP_EMPTY, g, false);
	lines = malloc(sizeof(char *) * (line_count + 1));
	if (!lines)
		print_exit(ERR_MEMORY, g, false);
	i = 0;
	start = file_str;
	curr = file_str;
	while (*curr)
	{
		if (*curr == '\n')
		{
			lines[i] = extract_line(start, curr);
			if (!lines[i])
				print_exit(ERR_MEMORY, g, true);
			i++;
			start = curr + 1;
		}
		curr++;
	}
	if (start < curr && *(curr -1) != '\n')
	{
		lines[i] = extract_line(start, curr);
		if (!lines[i])
			print_exit(ERR_MEMORY, g, true);
		i++;
	}
	lines[i] = NULL;
	return (lines);
}

bool	set_tex_path(char **dst, const char *path_pt)
{
	char	**trim;

	if (*dst != NULL)
		return (false);
	trim = ft_strtrim(path_pt, " \t");
	if (!trim)
		return (false);
	if (trim[0] == '\0')
	{
		free(trim);
		return (false);
	}
	*dst = trim;
	return (true);
}

bool	parse_tex_line(const char *line, t_game *g)
{
	if (ft_strncmp(line, "NO ", 3) == 0)
		return (set_tex_path(&g->paths.no, line + 3));
	if (ft_strncmp(line, "SO ", 3) == 0)
		return (set_tex_path(&g->paths.so, line + 3));
	if (ft_strncmp(line, "WE ", 3) == 0)
		return (set_tex_path(&g->paths.we, line + 3));
	if (ft_strncmp(line, "EA ", 3) == 0)
		return (set_tex_path(&g->paths.ea, line + 3));
	return (false);
}

int	parse_header(char **lines, t_game *g)
{
	int	i;

	i = 0;
	while (lines[i])
	{
		if (is_blank_line(lines[i]))
		{
			i++;
			continue ;
		}
		if (is_map_line(lines[i]))
			return (i);
		if (parse_tex_line(lines[i], g))
		{
			i++;
			continue ;
		}
		if (parse_color_line(lines[i], g))
		{
			i++;
			continue ;
		}
		print_exit(ERR_MAP_CHARS, g, true);
	}
	print_exit(ERR_MAP_EMPTY, g, true);
	return (-1);
}

