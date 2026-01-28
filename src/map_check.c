/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 17:42:59 by imutavdz          #+#    #+#             */
/*   Updated: 2026/01/25 18:21:10 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool parse_valid_map(t_game *game)
{
	if (!game->map.grid[0] || game->map.height <= 0)
		print_exit(ERR_MAP_EMPTY, game, true);
}