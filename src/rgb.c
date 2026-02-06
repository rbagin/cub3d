/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 17:26:31 by imutavdz          #+#    #+#             */
/*   Updated: 2026/02/06 19:53:13 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	parse_single_value(const char *str, int *value, char **next)
{
	int	result;
	int	digits;

	result = 0;
	digits = 0;
	while (*str == ' ' || *str == '\t')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		digits++;
		str++;
		if (result > 255)
			return (false);
	}
	if (digits == 0)
		return (false);
	*value = result;
	*next = (char *)str;
	return (true);
}

bool	parse_rgb(const char *s, int *out_color)
{
	int		r;
	int		g;
	int		b;
	int		a;
	char	*next;

	a = 255;
	if (!s || !out_color)
		return (false);
	if (!parse_single_value(s, &r, &next))
		return (false);
	while (*next == ' ' || *next == '\t')
		next++;
	if (*next != ',')
		return (false);
	next++;
	if (!parse_single_value(next, &g, &next))
		return (false);
	while (*next == ' ' || *next == '\t')
		next++;
	if (*next != ',')
		return (false);
	next++;
	if (!parse_single_value(next, &b, &next))
		return (false);
	while (*next == ' ' || *next == '\t' || *next == '\n' || *next == '\r')
		next++;
	if (*next != '\0')
		return (false);
	*out_color = (r << 24) | (g << 16) | (b << 8) | a;
	return (true);
}
