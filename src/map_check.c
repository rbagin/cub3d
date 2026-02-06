/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_check.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: imutavdz <imutavdz@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/01/25 17:42:59 by imutavdz      #+#    #+#                 */
/*   Updated: 2026/02/06 19:38:50 by rbagin        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	parse_color_line(const char *line, t_game *g)
{
	if (ft_strncmp(line, "F", 2) == 0)
		return (parse_rgb(line + 2, &g->color.floor));
	if (ft_strncmp(line, "C", 2) == 0)
		return (parse_rgb(line + 2, &g->color.ceiling));
	return (false);
}

bool	set_tex_path(char **dst, const char *path_pt)
{
	char	*trim;

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
