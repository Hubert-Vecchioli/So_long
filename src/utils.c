/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 14:50:23 by hvecchio          #+#    #+#             */
/*   Updated: 2024/06/19 12:27:55 by hvecchio         ###   ########.fr       */
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
