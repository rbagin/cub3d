/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macro.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 16:22:59 by imutavdz          #+#    #+#             */
/*   Updated: 2026/01/24 17:31:24 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAKRO_H
# define MAKRO_H

//error messages
# define ERR_ARGS "Error\nIncorrect number of arguments"
# define ERR_MAP_CHARS "Error\nInvalid characters in map"
# define ERR_MAP_RECT "Error\nMap is not rectangular"
# define ERR_MAP_WALLS "Error\nMap is not surrounded by walls"
# define ERR_MAP_EXT "Error\nMap file must have .cub extension"
# define ERR_MAP_OPEN "Error\nCould not open map file"
# define ERR_MEMORY "Error\nMemory allocation failed"
# define ERR_MLX "Error\nMLX initialization failed"
# define ERR_MAP_EMPTY "Error\nMAP file is invalid"

# define NO
# define SO
# define EA
# define WE
# define F
# define C

# define PLAYER_N 'N'
# define PLAYER_S 'S'
# define PLAYER_W 'W'
# define PLAYER_E 'E'

#endif