/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlb_actions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 14:36:44 by hvecchio          #+#    #+#             */
/*   Updated: 2024/06/16 22:02:00 by hvecchio         ###   ########.fr       */
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
	game->images->wall = ft_init_image(game, "./assets/wall.xpm");
	game->images->free_space = ft_init_image(game, "./assets/free_space.xpm");
	game->images->collectible = ft_init_image(game, "./assets/collectible.xpm");
	game->images->exit = ft_init_image(game, "./assets/exit.xpm");
	game->images->enemy = ft_init_image(game, "./assets/enemy.xpm");
	game->player->player_front =  ft_init_image(game, "./assets/player_front.xpm");
	game->player->player_right =  ft_init_image(game, "./assets/player_right.xpm");
	game->player->player_left =  ft_init_image(game, "./assets/player_left.xpm");
	game->player->player_back =  ft_init_image(game, "./assets/player_back.xpm");
}

t_image	*ft_init_image(t_game *game, char *path)
{
	
}