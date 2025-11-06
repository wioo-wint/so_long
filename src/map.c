/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wintoo <wintoo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 10:34:07 by wintoo            #+#    #+#             */
/*   Updated: 2025/10/30 12:30:25 by wintoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

size_t	find_height(char *file)
{
	int		fd;
	int		len;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		put_error(file, 1);
	len = 0;
	line = NULL;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		free1s(&line);
		len++;
	}
	close(fd);
	return (len);
}

void	get_map(t_game *data, char *file)
{
	int		fd;
	int		row;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		put_error(file, 1);
	data->height = find_height(file);
	data->map = malloc(sizeof(char *) * (data->height + 1));
	if (!data->map)
		put_error("malloc", 1);
	row = 0;
	while (1)
	{
		data->map[row] = get_next_line(fd);
		if (!data->map[row])
			break ;
		row++;
	}
	if (!data->map || !data->map[0])
		put_error("Empty Map", 2);
	isvalid_rect(data->map);
	check_wall(data->map);
	check_cep(data);
	check_path(data);
	close(fd);
}
