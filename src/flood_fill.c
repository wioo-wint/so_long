/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wintoo <wintoo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 15:20:23 by wintoo            #+#    #+#             */
/*   Updated: 2025/11/05 12:32:24 by wintoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	find_player_pos(t_game *data)
{
	int		i;
	int		j;

	i = -1;
	while (data->map[++i])
	{
		j = -1;
		while (data->map[i][++j])
		{
			if (data->map[i][j] == 'P')
			{
				data->play.y = i;
				data->play.x = j;
				return ;
			}
		}
	}
}

int	fill(char **map, int height, int row, int col)
{
	static int	ce;
	int			width;

	width = ft_strlen(map[0]);
	if (row < 0 || col < 0 || row >= height || col >= width)
		return (ce);
	if (map[row][col] == 'F' || map[row][col] == '1' || map[row][col] == 'E')
		return (ce);
	if (map[row][col] == 'C')
		ce++;
	map[row][col] = 'F';
	fill(map, height, row - 1, col);
	fill(map, height, row + 1, col);
	fill(map, height, row, col - 1);
	fill(map, height, row, col + 1);
	return (ce);
}

char	**dup_map(char **map, int h)
{
	char	**res;
	int		i;
	int		j;

	i = -1;
	res = malloc(sizeof(char *) * (h + 1));
	if (!res)
		put_error("malloc", 1);
	while (++i < h)
	{
		res[i] = ft_strdup(map[i]);
		if (!res[i])
		{
			j = 0;
			while (j < i)
				free(res[j++]);
			put_error("malloc", 1);
		}
	}
	res[h] = NULL;
	return (res);
}

void	check_path(t_game *data)
{
	size_t	ce;
	char	**mdup;

	find_player_pos(data);
	mdup = dup_map(data->map, data->height);
	ce = fill(mdup, data->height, data->play.y, data->play.x);
	free2s(mdup);
	if (ce != data->score)
	{
		free2s(data->map);
		put_error("The map does not have valid path.", 2);
	}
}
