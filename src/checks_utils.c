/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 12:23:39 by hvecchio          #+#    #+#             */
/*   Updated: 2024/06/19 12:38:13 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_map_is_doable(t_game *game)
{
	char	**content_copy;

	content_copy = ft_strcontentdup(game);
	game->player->pos_y = ft_find_position_row(game, 'P');
	game->player->pos_x = ft_find_position_col(game, 'P');
	ft_flood_map(game, content_copy, game->player->pos_x, game->player->pos_y);
	if (ft_count_elem(content_copy, 'C') != 0)
		return (ft_free_map(content_copy), 0);
	return (ft_free_map(content_copy), 1);
}

char	**ft_strcontentdup(t_game *game)
{
	char	**content_copy;
	int		i;

	i = 0;
	content_copy = malloc(sizeof(char *) * (game->map->row_size + 1));
	if (content_copy == NULL)
		return (ft_free(game), ft_error('m'), NULL);
	while (i < game->map->row_size)
	{
		content_copy[i] = ft_strdup(game->map->content[i]);
		if (content_copy[i] == NULL)
			return (ft_free_map(content_copy),
				ft_free(game), ft_error('m'), NULL);
		i++;
	}
	content_copy[i] = 0;
	return (content_copy);
}

void	ft_flood_map(t_game *game, char **content_copy, int pos_x, int pos_y)
{
	if (pos_y < 0 || pos_y >= game->map->col_size || pos_x < 0
		|| pos_x >= game->map->col_size || (content_copy[pos_x][pos_y] == '1')
		|| (content_copy[pos_x][pos_y] == 'V')
		|| (content_copy[pos_x][pos_y] == 'E'))
		return ;
	content_copy[pos_x][pos_y] = '1';
	ft_flood_map(game, content_copy, pos_x - 1, pos_y);
	ft_flood_map(game, content_copy, pos_x + 1, pos_y);
	ft_flood_map(game, content_copy, pos_x, pos_y - 1);
	ft_flood_map(game, content_copy, pos_x, pos_y + 1);
}

int	ft_find_position_row(t_game *game, char c)
{
	int	i;
	int	j;

	i = 0;
	while (game->map->content[i])
	{
		j = 0;
		while (game->map->content[i][j])
		{
			if (game->map->content[i][j] == c)
			{
				return (j);
			}
			j++;
		}
		i++;
	}
	return (-1);
}

int	ft_find_position_col(t_game *game, char c)
{
	int	i;
	int	j;

	i = 0;
	while (game->map->content[i])
	{
		j = 0;
		while (game->map->content[i][j])
		{
			if (game->map->content[i][j] == c)
			{
				return (i);
			}
			j++;
		}
		i++;
	}
	return (-1);
}
