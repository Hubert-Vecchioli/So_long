/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_actions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 16:23:04 by hvecchio          #+#    #+#             */
/*   Updated: 2024/06/19 12:36:07 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_window_close(t_game *game)
{
	return (ft_free(game), ft_close(), 0);
}

int	ft_on_keypress(int keycode, t_game *game)
{
	if (keycode == KEY_W || keycode == KEY_ARROW_TOP)
		ft_player_move(game, game->player->pos_x - 1, \
			game->player->pos_y, 1);
	if (keycode == KEY_S || keycode == KEY_ARROW_BOT)
		ft_player_move(game, game->player->pos_x + 1, \
			game->player->pos_y, 2);
	if (keycode == KEY_A || keycode == KEY_ARROW_LEFT)
		ft_player_move(game, game->player->pos_x, \
		game->player->pos_y - 1, 3);
	if (keycode == KEY_D || keycode == KEY_ARROW_RIGHT)
		ft_player_move(game, game->player->pos_x, \
		game->player->pos_y + 1, 4);
	if (keycode == KEY_Q || keycode == KEY_ESC)
		return (ft_free(game), ft_close(), 0);
	return (0);
}

int	ft_player_move(t_game *game, int x, int y, int direction)
{
	int	prev_x;
	int	prev_y;

	prev_x = game->player->pos_x;
	prev_y = game->player->pos_y;
	if (game->map->content[x][y] == 'E'
		&& ft_count_elem(game->map->content, 'C') < 1)
		return (ft_free(game), ft_win(), 1);
	else if (game->map->content[x][y] == 'V')
		return (ft_free(game), ft_error('l'), 0);
	else if (ft_is_valid_mvt(game, game->map->content, x, y) \
		&& game->map->content[x][y] != 'E')
	{
		game->map->content[prev_x][prev_y] = '0';
		if (game->map->content[x][y] == 'C')
			game->map->content[x][y] = '0';
		game->player->pos_x = x;
		game->player->pos_y = y;
		game->map->content[x][y] = 'P';
		game->player->count_actions++;
	}
	game->player->last_direction = direction;
	ft_render(game);
	return (1);
}

int	ft_is_valid_mvt(t_game *game, char **content, int x, int y)
{
	return (x >= 0
		&& x < game->map->row_size
		&& y >= 0
		&& y < game->map->col_size
		&& content[x][y] != '1');
}
