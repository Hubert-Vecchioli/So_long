/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 12:15:24 by hvecchio          #+#    #+#             */
/*   Updated: 2024/06/18 19:09:49 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/// INIT IMAGES
void	ft_init_game(t_game *game)
{
	ft_init_map(game);
	ft_init_fix_images(game);
	ft_init_mov_images(game);
	game->frame_init_ptr = NULL;
	game->frame_ptr = NULL;
	game->frame_height = 0;
	game->frame_width = 0;
}

int	ft_init_map(t_game *game)
{
	game->map = malloc(sizeof(t_map));
	if (!game->map)
		return (ft_error('m'), 0);
	game->map->content = NULL;
	game->map->row_size = 0;
	game->map->col_size = 0;
	game->map->fd = 0;
	return (1);
}

int	ft_init_fix_images(t_game *game)
{
	game->images = malloc(sizeof(t_fix_game_images));
	if (!game->images)
		return (ft_free(game), ft_error('m'), 0);
	game->images->free_space.ptr = NULL;
	game->images->wall.ptr = NULL;
	game->images->collectible.ptr = NULL;
	game->images->enemy.ptr = NULL;
	game->images->exit_open.ptr = NULL;
	game->images->exit_closed.ptr = NULL;
	return (1);
}

int	ft_init_mov_images(t_game *game)
{
	game->player = malloc(sizeof(t_mov_game_images));
	if (!game->player)
		return (ft_free(game), ft_error('m'), 0);
	game->player->player_front.ptr = NULL;
	game->player->player_right.ptr = NULL;
	game->player->player_left.ptr = NULL;
	game->player->player_back.ptr = NULL;
	game->player->count_actions = 0;
	game->player->last_direction = 0;
	game->player->pos_x = 0;	
	game->player->pos_y = 0;
	return (1);
}