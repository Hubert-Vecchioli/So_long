/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 14:55:56 by hvecchio          #+#    #+#             */
/*   Updated: 2024/06/13 16:45:45 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdio.h>

typedef struct s_image
{
// ptr?
}	t_image;

typedef struct s_fix_game_images
{
	t_image	*free_space;
	t_image	*wall;
	t_image	*collectible;
	t_image	*enemy;
	t_image	*exit;	
}	t_fix_game_images;

typedef struct s_mov_game_images
{
	t_image	*player_front;
	t_image	*player_right;
	t_image	*player_left;
	t_image	*player_back;
	int		count_actions;
	int		health_points;
}	t_mov_game_images;

typedef struct s_map
{
	int		fd;
	char	**content;
	int		row_size;
	int		col_size;
}	t_map;

typedef struct s_game
{
	t_map				*map;
	t_fix_game_images	*images;
	t_mov_game_images	*player;
}	t_game;

#endif
