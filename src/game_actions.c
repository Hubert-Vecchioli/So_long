/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_actions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 16:23:04 by hvecchio          #+#    #+#             */
/*   Updated: 2024/06/17 18:57:18 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_on_keypress(int keycode, t_game *game)
{
	if (keycode == KEY_W || keycode == KEY_ARROW_TOP)
		ft_player_move(game, game->player->pos_y - 1, \
			game->player->pos_x, 1); //TO UPDATE
	if (keycode == KEY_S || keycode == KEY_ARROW_BOT)
		ft_player_move(game, game->player->pos_y + 1, \
			game->player->pos_x, 2); //TO UPDATE
	if (keycode == KEY_A || keycode == KEY_ARROW_LEFT)
		ft_player_move(game, game->player->pos_y, \
		game->player->pos_x - 1, 3); //TO UPDATE
	if (keycode == KEY_D || keycode == KEY_ARROW_RIGHT)
		ft_player_move(game, game->player->pos_y, \
		game->player->pos_x + 1, 4); //TO UPDATE
	if (keycode == KEY_Q || keycode == KEY_ESC)
		return (ft_free(game), ft_close(), 0);
	return (0);
}

int	ft_player_move(t_game *game, int y, int x, int direction)
{
	int	prev_x;
	int	prev_y;

	prev_x = game->player->pos_x;
	prev_y = game->player->pos_y;
	if (game->map->content[y][x] == 'E' && ft_count_elem(game->map->content, 'C') < 1)
		return (ft_free(game), ft_win(), 1);
	else if (game->map->content[y][x] == 'E')
		return (ft_free(game), ft_loose(), 0);
	else if (is_valid_move(game, game->map->content, x, y) \
		&& game->map->content[y][x] != 'E')
	{
		game->map->content[prev_y][prev_x] = '0';
		if (game->map->content[y][x] == 'C')
			game->map->content[y][x] = '0';
		game->player->pos_x = x;
		game->player->pos_y = y;
		game->map->content[y][x] = 'P';
		game->player->count_actions++;
	}
	game->player->last_direction = direction;
	ft_render(game);
}
