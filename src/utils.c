/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 14:50:23 by hvecchio          #+#    #+#             */
/*   Updated: 2024/06/19 16:15:18 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strstr(const char *str, const char *to_find)
{
	size_t	i;
	size_t	j;

	if ((str == NULL || to_find == NULL))
		return (NULL);
	if (!*to_find)
		return ((char *)str);
	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i + j] && to_find[j] && str[i + j] == to_find[j])
			j++;
		if (!to_find[j])
			return ((char *)(str + i));
		i++;
	}
	return (NULL);
}

void	ft_free_map(char **split)
{
	int	i;

	i = 0;
	if (split)
	{
		while (split[i])
		{
			free(split[i]);
			i++;
		}
		free(split);
	}
}

void	ft_get_animated_enemy(t_game *game, int y, int x)
{
	if (game->images->enemy_to_display
		>= ft_count_elem(game->map->content, 'V'))
	{
		ft_render_sprite (game, game->images->enemy, y, x);
		game->images->enemy_to_display++;
		if (game->images->enemy_to_display
			> ft_count_elem(game->map->content, 'V') * 2 - 1)
			game->images->enemy_to_display = 0;
	}
	else
	{
		ft_render_sprite(game, game->images->enemy_animated, y, x);
		game->images->enemy_to_display++;
	}
}

int	ft_animated(t_game *game)
{
	ft_render(game);
	ft_render_movements(game, 0);
	usleep(300000);
	return (0);
}
