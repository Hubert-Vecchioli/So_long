/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 12:15:51 by hvecchio          #+#    #+#             */
/*   Updated: 2024/06/19 16:33:14 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error(char err)
{
	ft_putstr_fd("Error\n", 2);
	if (err == 'i')
		ft_putstr_fd("Wrong arg number\n", 2);
	else if (err == 'b')
		ft_putstr_fd("Wrong file format\n", 2);
	else if (err == 'm')
		ft_putstr_fd("Malloc failure\n", 2);
	else if (err == 'o')
		ft_putstr_fd("Open failure\n", 2);
	else if (err == 'e' || err == 'u')
		ft_putstr_fd("Wrong map:(wronf nb of exit, wrong param or size)\n", 2);
	else if (err == 'p')
		ft_putstr_fd("Wrong number of player\n", 2);
	else if (err == 'c')
		ft_putstr_fd("Wrong number of collectible\n", 2);
	else if (err == 'r')
		ft_putstr_fd("Wrong map: no rectangular wall surrounding\n", 2);
	else if (err == 's')
		ft_putstr_fd("Wrong map: no solution\n", 2);
	else if (err == 'x')
		ft_putstr_fd("Minilibx failure\n", 2);
	else if (err == 'l')
		ft_putstr_fd("You lost! Try again.\n", 2);
	exit(0);
}

void	ft_close(void)
{
	ft_putstr_fd("You left... See you soon!\n", 2);
	exit(0);
}

void	ft_win(void)
{
	ft_putstr_fd("You won!\n", 2);
	exit(0);
}

void	ft_free(t_game *game)
{
	if (game->map)
	{
		ft_free_map(game->map->content);
		free(game->map);
	}	
	if (game->images)
	{
		ft_clean_images(game);
		free(game->images);
	}
	if (game->player)
		free(game->player);
	if (game->frame_ptr)
		mlx_destroy_window(game->frame_init_ptr, game->frame_ptr);
	if (game->frame_init_ptr)
	{
		mlx_destroy_display(game->frame_init_ptr);
		free(game->frame_init_ptr);
	}
}

void	ft_clean_images(t_game *game)
{
	if (game->images->wall.ptr)
	{
		mlx_destroy_image(game->frame_init_ptr, game->images->wall.ptr);
		mlx_destroy_image(game->frame_init_ptr, game->images->free_space.ptr);
		mlx_destroy_image(game->frame_init_ptr, game->images->collectible.ptr);
		mlx_destroy_image(game->frame_init_ptr, game->images->exit_closed.ptr);
		mlx_destroy_image(game->frame_init_ptr, game->images->exit_open.ptr);
		mlx_destroy_image(game->frame_init_ptr, game->images->enemy.ptr);
		mlx_destroy_image(game->frame_init_ptr,
			game->images->enemy_animated.ptr);
		mlx_destroy_image(game->frame_init_ptr, game->player->player_front.ptr);
		mlx_destroy_image(game->frame_init_ptr, game->player->player_right.ptr);
		mlx_destroy_image(game->frame_init_ptr, game->player->player_left.ptr);
		mlx_destroy_image(game->frame_init_ptr, game->player->player_back.ptr);
	}
}
