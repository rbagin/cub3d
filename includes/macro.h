/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macro.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 16:22:59 by imutavdz          #+#    #+#             */
/*   Updated: 2026/02/03 20:03:45 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAKRO_H
# define MAKRO_H

//error messages
# define ERR_ARGS "Error\nIncorrect number of arguments"
# define ERR_HEAD_CH "Error\nIncorrct identifier in header"
# define ERR_MAP_CHARS "Error\nInvalid characters in map"
# define ERR_MAP_SPAWN "Error\nMap must contain exactly one spawn"
# define ERR_MAP_RECT "Error\nMap is not rectangular"
# define ERR_MAP_WALLS "Error\nMap is not surrounded by walls"
# define ERR_MAP_EXT "Error\nMap file must have .cub extension"
# define ERR_MAP_OPEN "Error\nCould not open map file"
# define ERR_MEMORY "Error\nMemory allocation failed"
# define ERR_MLX "Error\nMLX initialization failed"
# define ERR_MAP_EMPTY "Error\nNo map found"
//.cub identifiers
# define NO "NO"
# define SO "SO"
# define EA "EA"
# define WE "WE"
# define F "F"
# define C "C"

# define PLAYER_N 'N'
# define PLAYER_S 'S'
# define PLAYER_W 'W'
# define PLAYER_E 'E'

#endif