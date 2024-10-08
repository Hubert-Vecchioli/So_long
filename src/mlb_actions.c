/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlb_actions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 14:36:44 by hvecchio          #+#    #+#             */
/*   Updated: 2024/06/19 16:53:53 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_init_mlb(t_game *game)
{
	game->frame_height = 32 * game->map->row_size;
	game->frame_width = 32 * game->map->col_size;
	game->frame_init_ptr = mlx_init();
	if (game->frame_init_ptr == NULL)
		return (ft_free(game), ft_error('x'), 0);
	game->frame_ptr = mlx_new_window(game->frame_init_ptr,
			game->frame_width, game->frame_height, "So_long");
	if (game->frame_ptr == NULL)
		return (ft_free(game), ft_error('x'), 0);
	return (1);
}

void	ft_init_images(t_game *game)
{
	game->images->wall = ft_init_image(game, "./textures/wall.xpm");
	game->images->free_space = ft_init_image(game, "./textures/floor.xpm");
	game->images->collectible = ft_init_image(game,
			"./textures/collectible.xpm");
	game->images->exit_closed = ft_init_image(game,
			"./textures/exit_closed.xpm");
	game->images->exit_open = ft_init_image(game, "./textures/exit_open.xpm");
	game->images->enemy = ft_init_image(game, "./textures/enemy.xpm");
	game->images->enemy_animated = ft_init_image(game,
			"./textures/enemy_animated.xpm");
	game->player->player_front = ft_init_image(game, "./textures/player.xpm");
	game->player->player_right = ft_init_image(game, "./textures/player_r.xpm");
	game->player->player_left = ft_init_image(game, "./textures/player_l.xpm");
	game->player->player_back = ft_init_image(game,
			"./textures/player_back.xpm");
}

t_image	ft_init_image(t_game *game, char *path)
{
	t_image	image;

	image.ptr = mlx_xpm_file_to_image(game->frame_init_ptr, path, \
		&image.size_x, &image.size_y);
	if (image.ptr == NULL)
	{
		ft_free(game);
		ft_error('x');
	}
	return (image);
}
