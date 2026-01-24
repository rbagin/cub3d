/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 16:29:24 by imutavdz          #+#    #+#             */
/*   Updated: 2026/01/24 18:08:35 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static void	init_g_struct(t_game *game)
{
	ft_bzero(game, sizeof(*game));
	game->screen_w = 1280;
	game->screen_h = 720;
}

int	main(int argc, char const *argv[])
{
	//parsing (reads file + fills paths/color/map/player)
	if (argc != 2)
		return (print_exit(ERR_ARGS, NULL, false), 1);
	init_g_struct(&game);
	if (!load_map(&game, argv[1]))
		return (EXIT_FAILURE);
	//validation (map closed/ 1spawn / all ids present / rgb valid)
	if (!valid_cub(&game))
		return (cleanup(&game), 1);
	//initialisation
	if (!init_mlx(&game))
		return (cleanup(&game), 1);
	//create init frame buff
	//load textures
	//render
	//raycast walls
	//movement rotation hooks+loop
	celanup(&game);
	return (0);
}