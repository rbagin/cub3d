/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 18:51:43 by imutavdz          #+#    #+#             */
/*   Updated: 2026/02/03 21:18:47 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// t_input flags key press - update every move/rotate
/*hooks + loop

key press: set flags in g->inp

key release: unset flags

loop hook:

compute dt

update_player(g, dt) (movement+rotation+collision)

render(g) (ceiling/floor + rays + textures)

put image to window*/
