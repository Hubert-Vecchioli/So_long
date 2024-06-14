/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlb_actions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 14:36:44 by hvecchio          #+#    #+#             */
/*   Updated: 2024/06/14 14:44:57 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_init_mlb(t_game *game)
{
	game->frame_height = 100; // TO BE MODIFIED
	game->frame_width = 100; // TO BE MODIFIED
	game->frame_init_ptr = mlx_init();
	if (game->frame_init_ptr == NULL)
		return(ft_free(game), ft_error('x'), 0);
	game->frame_ptr = mlx_new_window(game->frame_init_ptr, game->frame_width, game->frame_height, "So_long");
	if (game->frame_ptr == NULL)
		return(ft_free(game), ft_error('x'), 0);
}

int	ft_init_images(t_game *game)
{

}
