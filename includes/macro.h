/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   macro.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: imutavdz <imutavdz@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/01/23 16:22:59 by imutavdz      #+#    #+#                 */
/*   Updated: 2026/02/06 20:07:36 by rbagin        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACRO_H
# define MACRO_H

//error messages
# define ERR_ARGS "Error\nIncorrect number of arguments"
# define ERR_HEAD_CH "Error\nIncorrct identifier in header"
# define ERR_MAP_CHARS "Error\nInvalid characters in map"
# define ERR_MISS_COLOR "Error\nMissing color"
# define ERR_MAP_EMPTY_LN "Error\nEmpty lines inside map"
# define ERR_MAP_LN "Error\nInvalid map line"
# define ERR_MAP_SPAWN "Error\nMap must contain exactly one spawn"
# define ERR_MAP_RECT "Error\nMap is not rectangular"
# define ERR_MAP_WALLS "Error\nMap is not surrounded by walls"
# define ERR_MAP_EXT "Error\nMap file must have .cub extension"
# define ERR_MAP_OPEN "Error\nCould not open map file"
# define ERR_MEMORY "Error\nMemory allocation failed"
# define ERR_MLX "Error\nMLX initialization failed"
# define ERR_MAP_EMPTY "Error\nMAP file is invalid"
# define ERR_NO_TEX_ID "Error\nTexture identifier not present"
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

# define SCREEN_WIDTH 1920
# define SCREEN_HEIGHT 1080
# define FOV_SCALE 66

# define CREATE_RGBA(r, g, b, a) ((r) << 24 | (g) << 16 | (b) << 8 | (a))

# define N_COLOR CREATE_RGBA(167, 17, 17, 255)
# define S_COLOR CREATE_RGBA(26, 214, 26, 255)
# define E_COLOR CREATE_RGBA(2, 47, 226, 255)
# define W_COLOR CREATE_RGBA(192, 244, 5, 255)
# define FLOOR_COLOR CREATE_RGBA(0, 0, 0, 255)
# define CEILING_COLOR CREATE_RGBA(255,255,255, 255)

#endif
