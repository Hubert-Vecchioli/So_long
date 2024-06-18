/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 14:55:56 by hvecchio          #+#    #+#             */
/*   Updated: 2024/06/18 16:48:34 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "../libft/libft.h"
#include "../mlx-linux/mlx.h"
#include "../mlx-linux/mlx_int.h"

# include <stdio.h>


// LINUX
#  define KEY_ESC			65307
#  define KEY_Q				113
#  define KEY_W				119
#  define KEY_E				101
#  define KEY_A				97
#  define KEY_S				115
#  define KEY_D				100
#  define KEY_ARROW_TOP		65362
#  define KEY_ARROW_BOT		65364
#  define KEY_ARROW_LEFT	65361
#  define KEY_ARROW_RIGHT	65363

typedef struct s_image
{
	void		*ptr;
	char		*addr;
	int			bits_per_pixel;
	int			size_x;
	int			size_y;
	int			size_line;
	int			endian;
}	t_image;

typedef struct s_fix_game_images
{
	t_image	*free_space;
	t_image	*wall;
	t_image	*collectible;
	t_image	*enemy;
	t_image	*exit_open;	
	t_image	*exit_closed;	
}	t_fix_game_images;

typedef struct s_mov_game_images
{
	t_image	*player_front;
	t_image	*player_right;
	t_image	*player_left;
	t_image	*player_back;
	int		pos_x;
	int		pos_y;
	char	last_direction;
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
	void				*frame_init_ptr;
	void				*frame_ptr;
	int					frame_height;
	int					frame_width;
}	t_game;

char		*ft_strstr(const char *str, const char *to_find);
//char		*ft_strdup(const char *src);
char		**ft_strcontentdup(t_game *game);
int			ft_find_position_row(t_game *game, char c);
int			ft_find_position_col(t_game *game, char c);
int			ft_window_close(t_game *game);
int			ft_on_keypress(int keycode, t_game *game);
int			ft_init_map(t_game *game);
int			ft_init_fix_images(t_game *game);
int			ft_init_mov_images(t_game *game);
int			ft_init_mlb(t_game *game);
int			ft_render(t_game *game);
int			ft_render_life(t_game *game);
int			ft_render_movements(t_game *game);
int			ft_review_game(t_game *game);
int			ft_count_elem(char **content, char c);
int			ft_check_rectangle_wall(t_game *game);
int			ft_check_map_is_doable(t_game *game);
int			ft_player_move(t_game *game, int y, int x, int direction);
int			ft_is_valid_mvt(t_game *game, char **content, int x, int y);
int			ft_parse_game(char **av, t_game *game);
t_image		ft_init_image(t_game *game, char *path);
void		ft_init_images(t_game *game);
void		ft_init_game(t_game *game);
void		ft_render_interface(t_game *game);
void		ft_render_sprite(t_game *game, t_image sprite, int line, int column);
void		ft_get_sprite(t_game *game, int y, int x);
void		ft_render_player(t_game *game, int y, int x);
void		ft_review_input(int ac, char **av);
void		ft_error(char err);
void		ft_close(void);
void		ft_win(void);
void		ft_free(t_game *game);
void		ft_free_map(char **split);
void		ft_flood_map(t_game *game, char **content_copy, int pos_x, int pos_y);
void		ft_loose(void);

#endif
