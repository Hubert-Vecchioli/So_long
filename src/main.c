/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 14:55:32 by hvecchio          #+#    #+#             */
/*   Updated: 2024/06/19 16:14:43 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_game	game;

	ft_review_input(ac, av);
	ft_init_game(&game);
	ft_parse_game(av, &game);
	ft_review_game(&game);
	ft_init_mlb(&game);
	ft_init_images(&game);
	mlx_hook(game.frame_ptr, KeyPress, KeyPressMask, ft_on_keypress, &game);
	mlx_hook(game.frame_ptr, DestroyNotify, ButtonPressMask,
		ft_window_close, &game);
	mlx_loop_hook(game.frame_init_ptr, ft_animated, &game);
	mlx_loop(game.frame_init_ptr);
	return (ft_free(&game), ft_error('w'), 0);
}
