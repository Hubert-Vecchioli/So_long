/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 12:15:51 by hvecchio          #+#    #+#             */
/*   Updated: 2024/06/14 14:51:47 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// function to end

// function to free
void	ft_error(char err)
{
	ft_putstr_fd("Error\n", 2);
	if (err == 'i')
		ft_putstr_fd("Wrong arg number\n", 2);
	else if (err == 'b')
		ft_putstr_fd("Wrong file format\n", 2);
	else if (err == 'm')
		ft_putstr_fd("Malloc failure\n", 2);
	else if (err == 'o')
		ft_putstr_fd("Open failure\n", 2);
	else if (err == 'e')
		ft_putstr_fd("Wrong number of exit\n", 2);	
	else if (err == 'p')
		ft_putstr_fd("Wrong number of player\n", 2);
	else if (err == 'c')
		ft_putstr_fd("Wrong number of collectible\n", 2);
	else if (err == 'r')
		ft_putstr_fd("Wrong map, no rectangular wall surrounding\n", 2);
	else if (err == 's')
		ft_putstr_fd("Wrong map with no solution\n", 2);
	else if (err == 'x')
		ft_putstr_fd("Minilibx failure\n", 2);
	else if (err == 'w')
		ft_putstr_fd("You won!\n", 2);
	exit(0);
}

void	ft_free(t_game *game)
{
	if (game->map)
	{
		//clean map
	}	
	if (game->images)
	{
	}	
	if (game->player)
	{
	}
}

void	ft_free_map(char **map)
{
	
}
