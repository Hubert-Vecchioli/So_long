/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 02:56:07 by hvecchio          #+#    #+#             */
/*   Updated: 2024/05/27 13:17:18 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

# if BUFFER_SIZE < 0
#  undef BUFFER_SIZE
#  define BUFFER_SIZE 0
# endif

# define MAX_FD 1024

# include <stdlib.h>
# include <unistd.h>

typedef struct s_buffer
{
	char	content[BUFFER_SIZE];
	ssize_t	size;
}	t_buffer;

char	*get_next_line(int fd);
char	*ft_clean(char *line, t_buffer *buffer, size_t line_len, char to_find);
char	*ft_bfrjoin(char *line, t_buffer *buffer, size_t line_len);
int		ft_strchr(char *str, char to_find, size_t line_len);
size_t	ft_max(size_t a, size_t b);
void	ft_bzero(void *ptr, size_t n);
void	*ft_calloc(size_t n, size_t size);

#endif
