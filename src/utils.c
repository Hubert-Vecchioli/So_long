/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 14:50:23 by hvecchio          #+#    #+#             */
/*   Updated: 2024/06/17 18:11:53 by hvecchio         ###   ########.fr       */
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

char	*ft_strdup(const char *src)
{
	char	*copy_str;
	int		i;

	copy_str = (malloc((ft_strlen(src) + 1) * sizeof(char)));
	if (copy_str == NULL)
		return (NULL);
	i = 0;
	while (src[i])
	{
		copy_str[i] = src[i];
		i++;
	}
	copy_str[i] = 0;
	return (copy_str);
}