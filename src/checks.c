/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 12:44:40 by hvecchio          #+#    #+#             */
/*   Updated: 2024/06/13 14:53:13 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_review_input(int ac, char **av)
{
	if (ac != 2)
		ft_error('i');
	if (!ft_strstr(av[1], ".ber"))
		ft_error('b');
}

// check the map has the need artefacts (1 E, 1+ c, 1P)
// check the map is a rectangle
// surronded by walls
// check the map is doable and all the collectible are reachable
