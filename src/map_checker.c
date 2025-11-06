/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wintoo <wintoo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 15:56:30 by wintoo            #+#    #+#             */
/*   Updated: 2025/11/04 16:08:16 by wintoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	isvalid_rect(char **map)
{
	size_t	firstlen;
	size_t	nextlen;
	int		i;

	i = 1;
	firstlen = ft_strlen(map[0]) - 1;
	while (map[i])
	{
		nextlen = ft_strlen(map[i]);
		if (map[i][nextlen - 1] == '\n')
			nextlen -= 1;
		if (firstlen != nextlen)
		{
			free2s(map);
			put_error("The map is not rectangular.", 2);
		}
		i++;
	}
	if (map[i - 1][firstlen] == '\n')
	{
		free2s(map);
		put_error("Found new line at the last of the map.", 2);
	}
}

// C - a collectible,
// E - a map exit,
// P - the player’s starting position.
void	valid_cep(char **map, int c, int e, int p)
{
	if (c < 1)
	{
		free2s(map);
		put_error("A map must contain at least 1 collectible.", 2);
	}
	else if (e != 1)
	{
		free2s(map);
		put_error("A map must contain 1 exit.", 2);
	}
	else if (p != 1)
	{
		free2s(map);
		put_error("A map must contain 1 player.", 2);
	}
}

void	check_cep(t_game *data)
{
	int	i;
	int	j;
	int	e;
	int	p;

	i = 0;
	e = 0;
	p = 0;
	while (data->map[++i + 1])
	{
		j = 0;
		while (data->map[i][++j + 1])
		{
			if (data->map[i][j] == 'C')
				data->score++;
			else if (data->map[i][j] == 'E')
				e++;
			else if (data->map[i][j] == 'P')
				p++;
			else if (data->map[i][j] != '1' && data->map[i][j] != '0'
				&& data->map[i][j] != 'B')
				return (free2s(data->map), put_error("Invalid Map", 2));
		}
	}
	valid_cep(data->map, data->score, e, p);
}

void	check_wall(char **map)
{
	int	i;
	int	len;
	int	iswall;

	i = -1;
	iswall = 1;
	while (map[++i] && iswall == 1)
	{
		len = ft_strlen(map[i]) - 2;
		if (map[i][0] != '1' || map[i][len] != '1')
			iswall = 0;
	}
	len = 0;
	while (map[0][len] != '\n' && map[i - 1][len] && iswall == 1)
	{
		if (map[0][len] != '1' || map[i - 1][len] != '1')
			iswall = 0;
		len++;
	}
	if (iswall == 0)
	{
		free2s(map);
		put_error("The map is not enclosed by walls.", 2);
	}
}
