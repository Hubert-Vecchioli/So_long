/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 15:00:16 by hvecchio          #+#    #+#             */
/*   Updated: 2024/06/19 12:42:09 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_count_map_rows(char **av, t_game *game)
{
	int		i;
	char	*line;

	i = 0;
	game->map->fd = open(av[1], O_RDONLY);
	if (game->map->fd == -1)
		return (ft_free(game), ft_error('o'), 0);
	while (1)
	{
		line = get_next_line(game->map->fd);
		i++;
		if (!line)
			break ;
		free(line);
	}
	close(game->map->fd);
	return (i);
}

int	ft_parse_game(char **av, t_game *game)
{
	int		i;

	i = ft_count_map_rows(av, game);
	game->map->content = malloc(sizeof(char *) * (i + 1));
	if (game->map->content == NULL)
		return (ft_free(game), ft_error('m'), 0);
	game->map->fd = open(av[1], O_RDONLY);
	if (game->map->fd == -1)
		return (ft_free(game), ft_error('o'), 0);
	i = 0;
	while (1)
	{
		game->map->content[i] = get_next_line(game->map->fd);
		if (!game->map->content[i])
			break ;
		i++;
	}
	game->map->content[i] = 0;
	close(game->map->fd);
	game->map->row_size = i;
	game->map->col_size = ft_strlen(game->map->content[0]);
	return (1);
}
