/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_interface.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 11:41:39 by lquehec           #+#    #+#             */
/*   Updated: 2024/06/17 17:31:06 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_render_life(t_game *game)
{
	char	*life;
	char	*phrase;

	life = ft_itoa(game->player->health_points);
	if (!life)
		return (ft_free(game), ft_error(), 0);
	phrase = ft_strjoin("Life : ", life);
	if (!phrase)
		return (ft_free(game), ft_error(), 0);
	mlx_string_put(game->frame_init_ptr, game->frame_ptr, \
		10, 40, 16777215, phrase); // TO BE REVIEWED
	free(life);
	free(phrase);
	return (1);
}

int	ft_render_movements(t_game *game)
{
	char	*movements;
	char	*phrase;

	movements = ft_itoa(game->player->count_actions);
	if (!movements)
		return (ft_free(game), ft_error(), 0);
	phrase = ft_strjoin("Movements : ", movements);
	if (!phrase)
		return (ft_free(game), ft_error(), 0);
	mlx_string_put(game->frame_init_ptr, game->frame_ptr, \
		10, 20, 16777215, phrase); // TO BE REVIEWED
	free(movements);
	free(phrase);
	return (1);
}

void	ft_render_interface(t_game *game)
{
	ft_render_movements(game);
	ft_render_life(game);
}