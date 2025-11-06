/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wintoo <wintoo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 15:19:23 by wintoo            #+#    #+#             */
/*   Updated: 2025/11/06 13:03:27 by wintoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

size_t	ft_strlen(const char *str)
{
	size_t	index;

	index = 0;
	if (!str)
		return (0);
	while (str[index])
	{
		index++;
	}
	return (index);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*res;
	size_t	s1len;
	size_t	s2len;
	size_t	i;

	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	res = malloc(s1len + s2len + 1);
	if (!res)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i])
		res[s1len++] = s2[i++];
	res[s1len] = '\0';
	return (res);
}

char	*ft_strdup(const char *str)
{
	char	*dup;
	int		len;
	int		index;

	len = ft_strlen(str);
	dup = malloc(len + 1);
	if (!dup)
		return (NULL);
	index = 0;
	while (str[index])
	{
		dup[index] = str[index];
		index++;
	}
	dup[index] = '\0';
	return (dup);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)(s + i));
	return (NULL);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] && s2[i] && s1[i] == s2[i] && i < n - 1)
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
