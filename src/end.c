/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 12:15:51 by hvecchio          #+#    #+#             */
/*   Updated: 2024/06/13 16:28:02 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// function to end

// function to free

// example from push swp:
void	ft_error(char err)
{
	ft_putstr_fd("Error\n", 2);
	if (err == 'i')
	{
		ft_putstr_fd("Wrong arg number\n", 2);
	}
	else if (err == 'b')
	{
		ft_putstr_fd("Wrong file format\n", 2);
	}
	else if (err == 'm')
	{
		ft_putstr_fd("Malloc failure\n", 2);
	}
	exit(0);
}

void	ft_free(t_game *game)
{
	if (game->map)
	{
	}	
	if (game->images)
	{
	}	
	if (game->player)
	{
	}
}