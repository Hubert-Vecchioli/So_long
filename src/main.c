/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 14:55:32 by hvecchio          #+#    #+#             */
/*   Updated: 2024/06/13 16:47:28 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int ac, char **av)
{
	t_game	game;
	
	ft_review_input(ac, av);
	ft_init_game(&game);
	ft_parse_game(av[1], &game);
	ft_review_game(&game);	// Review the game quality
	// generate screen
	// get inputs & impact the game
	// close & free
}
