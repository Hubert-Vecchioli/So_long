/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 12:44:40 by hvecchio          #+#    #+#             */
/*   Updated: 2024/06/18 17:18:26 by hvecchio         ###   ########.fr       */
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
	if (ft_count_elem(game->map->content, 'E') != 1)
		return(ft_free(game), ft_error('e'), 0);
	if (ft_count_elem(game->map->content, 'P') != 1)
		return(ft_free(game), ft_error('p'), 0);
	if (ft_count_elem(game->map->content, 'C') < 1)
		return(ft_free(game), ft_error('c'), 0);
	if (ft_check_rectangle_wall(game) != 1)
		return (ft_free(game), ft_error('r'), 0);
	if (ft_check_map_is_doable(game) != 1)
		return (ft_free(game), ft_error('s'), 0);
	return (1);
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

	j = -1;
	while (game->map->content[0][++j] == '1')
	{}
	if (game->map->col_size != j)
		return (0);
	j = -1;
	while (game->map->content[game->map->row_size - 1][++j] == '1')
	{}
	if (game->map->col_size != j)
		return (0);
	j = 0;
	while (game->map->content[j] && game->map->content[j][0] == '1')
		j = j + 1;
	if (game->map->row_size != j)
		return (0);
	j = 0;
	while (game->map->content[j] && game->map->content[j][game->map->col_size - 1] == '1')
		j = j + 1;
	if (game->map->row_size != j)
		return (0);
	return (1);
}

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
	char **content_copy;
	int	i;
	
	i = 0;
	content_copy = malloc(sizeof(char *) * (game->map->row_size + 1));
	if (content_copy == NULL)
		return (ft_free(game), ft_error('m'), NULL);
	while (i < game->map->row_size)
	{
		content_copy[i] = ft_strdup(game->map->content[i]);
		i++;
		//mid copy malloc failure ft_free_map
	}
	content_copy[i] = 0;
	return (content_copy);
}

void	ft_flood_map(t_game *game, char **content_copy, int pos_x, int pos_y)
{
	if (pos_y < 0 || pos_y >= game->map->col_size || pos_x < 0 || pos_x >= game->map->col_size || (content_copy[pos_x][pos_y] == '1') || (content_copy[pos_x][pos_y] == 'V') || (content_copy[pos_x][pos_y] == 'E'))
		return;
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
