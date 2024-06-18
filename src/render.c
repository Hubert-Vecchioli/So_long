/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 16:40:04 by hvecchio          #+#    #+#             */
/*   Updated: 2024/06/18 13:32:43 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_render_sprite(t_game *game, t_image sprite, int line, int column)
{
	mlx_put_image_to_window (game->frame_init_ptr, game->frame_ptr, \
	sprite.ptr, column * sprite.size_x, line * sprite.size_y);
}

void	ft_get_sprite(t_game *game, int y, int x)
{
	char	value;

	value = game->map->content[y][x];
	if (value == '1')
		ft_render_sprite(game, *game->images->wall, y, x);
	else if (value == '0')
		ft_render_sprite(game, *game->images->free_space, y, x);
	else if (value == 'C')
	{
		ft_render_sprite(game, *game->images->free_space, y, x);
		ft_render_sprite(game, *game->images->collectible, y, x);
	}
	else if (value == 'E')
	{
		if (ft_count_elem(game->map->content, 'C') < 1)
			ft_render_sprite(game, *game->images->exit_open, y, x);
		else
			ft_render_sprite(game, *game->images->exit_closed, y, x);
	}
	else if (value == 'V')
		ft_render_sprite(game, *game->images->enemy, y, x);
	else if (value == 'P')
		ft_render_player(game, y, x);
}

void	ft_render_player(t_game *game, int y, int x)
{
	ft_render_sprite(game, *game->images->free_space, y, x);
	if (game->player->last_direction == 2)
		ft_render_sprite (game, *game->player->player_front, y, x);
	if (game->player->last_direction == 1)
		ft_render_sprite (game, *game->player->player_back, y, x);
	if (game->player->last_direction == 3)
		ft_render_sprite (game, *game->player->player_left, y, x);
	if (game->player->last_direction == 4)
		ft_render_sprite (game, *game->player->player_right, y, x);
}

int	ft_render(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map->col_size)
	{
		x = 0;
		while (x < game->map->row_size)
		{
			ft_get_sprite(game, y, x);
			x++;
		}
		y++;
	}
	ft_render_interface(game);
	return (0);
}