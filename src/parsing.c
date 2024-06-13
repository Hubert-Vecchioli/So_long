/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 15:00:16 by hvecchio          #+#    #+#             */
/*   Updated: 2024/06/13 17:29:48 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "so_long.h"

void 	ft_parse_game(char **av, t_game *game)
{
	ft_get_map_content(av[1], game);
	//parse collectible
}

char *ft_get_map_content(char **av, t_game *game)
{
	int		i;
	
	i = 0;
	game->map->fd = open(av[1], O_RDONLY);
	if (game->map->fd = -1)
		return (ft_free(game), ft_error('o'));
	while(get_next_line(game->map->fd))
		i++;
	close(game->map->fd)
	game->map->fd = open(av[1], O_RDONLY);
	if (game->map->fd = -1)
		return (ft_free(game), ft_error('o'));
	game->map->content = malloc(sizeof(char *) * (i + 1))
	i = 0;
	game->map->content[i] = get_next_line(game->map->fd)
	while(game->map->content[i])
	{
		game->map->content[++i] = get_next_line(game->map->fd)
		//protect GNL failures check si [0] = NULL
		//return (ft_free(game), ft_error('g'));
	}
	game->map->content[i] = 0;
	game->map->row_size = i;
	game->map->col_size = ft_strlen(game->map->content[0]);
}
