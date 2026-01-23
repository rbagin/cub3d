/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 16:29:24 by imutavdz          #+#    #+#             */
/*   Updated: 2026/01/23 19:38:08 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static void	init_g_struct(t_game *game)
{
	ft_bzero(game, sizeof(t_game));
	game->game_over = false;
}

int	main(int argc, char const *argv[])
{
	if (argc != 2)
		return (print_exit(ERR_ARGS, NULL, false), EXIT_FAILURE);
	init_g_struct(&game);
	if (!load_map(&game, argv[1]))
		return (EXIT_FAILURE);
	//validation
	//initialisation
	//parsing
	//start
	//end
	//cleanup

	return (0);
}