/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cleanup.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: imutavdz <imutavdz@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/02/05 13:31:50 by imutavdz      #+#    #+#                 */
/*   Updated: 2026/02/06 19:36:07 by rbagin        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_lines(char **lines)
{
	int	i;

	i = 0;
	if (!lines)
		return ;
	while (lines[i])
	{
		free(lines[i]);
		i++;
	}
	free(lines);
}
void	print_exit(const char *errmsg, t_game *game, bool do_cleanup)
{
	if (errmsg)
	{
		ft_putstr_fd((char *)errmsg, STDERR_FILENO);
		ft_putstr_fd("\n", STDERR_FILENO);
	}
	if (do_cleanup && game)
		// final_cleanup(game);
	exit(do_cleanup);
}
