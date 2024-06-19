/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 12:44:40 by hvecchio          #+#    #+#             */
/*   Updated: 2024/06/19 12:23:22 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_review_input(int ac, char **av)
{
	if (ac != 2)
		ft_error('i');
	if (!ft_strstr(av[1], ".ber"))
		ft_error('b');
}

int	ft_review_game(t_game *game)
{
	if (ft_has_invalid_param(game->map->content) == 1)
		return (ft_free(game), ft_error('u'), 0);
	if (ft_count_elem(game->map->content, 'E') != 1)
		return (ft_free(game), ft_error('e'), 0);
	if (ft_count_elem(game->map->content, 'P') != 1)
		return (ft_free(game), ft_error('p'), 0);
	if (ft_count_elem(game->map->content, 'C') < 1)
		return (ft_free(game), ft_error('c'), 0);
	if (ft_check_rectangle_wall(game) != 1)
		return (ft_free(game), ft_error('r'), 0);
	if (ft_check_map_is_doable(game) != 1)
		return (ft_free(game), ft_error('s'), 0);
	return (1);
}

int	ft_has_invalid_param(char **content)
{
	int	i;
	int	j;

	i = 0;
	while (content[i])
	{
		j = 0;
		while (content[i][j])
		{
			if (content[i][j] != '1' && content[i][j] != 'E'
				&& content[i][j] != 'P' && content[i][j] != '0'
				&& content[i][j] != 'V' && content[i][j] != 'C')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_count_elem(char **content, char c)
{
	int	i;
	int	j;
	int	res;

	i = 0;
	res = 0;
	while (content[i])
	{
		j = 0;
		while (content[i][j])
		{
			if (content[i][j] == c)
				res += 1;
			j++;
		}
		i++;
	}
	return (res);
}

int	ft_check_rectangle_wall(t_game *game)
{
	int	j;

	j = 0;
	while (game->map->content[0][j] == '1')
		j++;
	if (game->map->col_size != j)
		return (0);
	j = 0;
	while (game->map->content[game->map->row_size - 1][j] == '1')
		j++;
	if (game->map->col_size != j)
		return (0);
	j = 0;
	while (game->map->content[j] && game->map->content[j][0] == '1')
		j = j + 1;
	if (game->map->row_size != j)
		return (0);
	j = 0;
	while (game->map->content[j]
		&& game->map->content[j][game->map->col_size - 1] == '1')
		j = j + 1;
	if (game->map->row_size != j)
		return (0);
	return (1);
}
