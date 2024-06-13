/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 12:15:24 by hvecchio          #+#    #+#             */
/*   Updated: 2024/06/13 16:45:52 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_init_game(t_game *game)
{
	ft_init_map(game);
	ft_init_fix_images(game);
	ft_init_mov_images(game);
}

void	ft_init_map(t_game *game)
{
	game->map = malloc(sizeof(t_map));
	if (!game->map)
		return (ft_error('m'));
	game->map->content = NULL;
	game->map->row_size = 0;
	game->map->col_size = 0;
	game->map->fd = 0;
}

void	ft_init_fix_images(t_game *game)
{
	game->images = malloc(sizeof(t_fix_game_images));
	if (!game->images)
		return (ft_free(game), ft_error('m'));
	game->images->free_space = NULL;
	game->images->wall = NULL;
	game->images->collectible = NULL;
	game->images->enemy = NULL;
	game->images->exit = NULL;
}

void	ft_init_mov_images(t_game *game)
{
	game->player = malloc(sizeof(t_mov_game_images));
	if (!game->player)
		return (ft_free(game), ft_error('m'));
	game->player->player_front = NULL;
	game->player->player_right = NULL;
	game->player->player_left = NULL;
	game->player->player_back = NULL;
	game->player->count_actions = 0;
	game->player->health_points = 0;
}