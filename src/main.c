/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 14:55:32 by hvecchio          #+#    #+#             */
/*   Updated: 2024/06/17 08:01:34 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int ac, char **av)
{
	t_game	game;
	
	ft_review_input(ac, av);
	ft_init_game(&game);
	ft_parse_game(av[1], &game);
	ft_review_game(&game);
	ft_init_mlb(&game);
	ft_init_images(&game); // WIP
	// generate screen
	// get inputs via the hook
	mlx_loop(game.frame_init_ptr);
	return (ft_free(game), ft_error('w'));
}
