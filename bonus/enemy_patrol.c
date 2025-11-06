/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_patrol.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wintoo <wintoo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 13:48:32 by wintoo            #+#    #+#             */
/*   Updated: 2025/11/06 12:16:08 by wintoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	get_enemypos(t_game *data, int frame, int i)
{
	int				pos_x;
	int				pos_y;
	static int		iswall;

	pos_x = (int)(data->bonus.epos / PX) + data->bonus.edir;
	pos_y = (int)(data->bonus.enemy[frame]->instances[i].y / PX);
	if (data->map[pos_y][pos_x] == '1' && !iswall)
	{
		data->bonus.esp *= -1;
		iswall = 1;
	}
	else if (data->map[pos_y][pos_x] != '1')
		iswall = 0;
	if (pos_x == data->play.x && pos_y == data->play.y)
		show_result(data, 0);
	if (data->bonus.esp > 0)
	{
		data->bonus.edir = 1;
		data->bonus.epos += data->bonus.esp * data->mlx->delta_time * 10;
	}
	else
	{
		data->bonus.edir = 0;
		data->bonus.epos += data->bonus.esp * data->mlx->delta_time * 5;
	}
}

void	anim_enemy(void	*param)
{
	static float	timer;
	int				frame;
	t_game			*data;
	int				i;
	int				j;

	data = param;
	data->anim.speed = 0.25f;
	data->anim.end = 2;
	data->bonus.eside = get_frame(data, &timer, data->bonus.eside);
	frame = data->bonus.eside + (data->bonus.edir * 2);
	j = -1;
	while (++j < data->bonus.ecount)
	{
		data->bonus.epos = data->bonus.enemy[frame]->instances[j].x;
		get_enemypos(data, frame, j);
		i = -1;
		while (++i < 4)
		{
			data->bonus.enemy[i]->instances[j].x = data->bonus.epos;
			data->bonus.enemy[i]->instances[j].enabled = false;
		}
		data->bonus.enemy[frame]->instances[j].enabled = true;
	}
}
