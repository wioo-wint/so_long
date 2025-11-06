/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animate_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wintoo <wintoo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 12:51:02 by wintoo            #+#    #+#             */
/*   Updated: 2025/11/05 14:54:09 by wintoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	get_frame(t_game *data, float *timer, int fr)
{
	*timer += data->mlx->delta_time;
	if (*timer > data->anim.speed)
	{
		*timer = 0.0f;
		fr = (fr + 1) % data->anim.end;
	}
	return (fr);
}

void	move_left(t_game *data)
{
	static int	lframe;

	if (lframe % 2 == 0)
	{
		data->play.left[0]->instances[0].y = data->play.y * PX;
		data->play.left[0]->instances[0].x = data->play.x * PX;
		data->play.left[0]->instances[0].enabled = true;
	}
	else
	{
		data->play.left[1]->instances[0].y = data->play.y * PX;
		data->play.left[1]->instances[0].x = data->play.x * PX;
		data->play.left[1]->instances[0].enabled = true;
	}
	lframe++;
}

void	move_right(t_game *data)
{
	static int	rframe;

	if (rframe % 2 == 0)
	{
		data->tex.player->instances[0].y = data->play.y * PX;
		data->tex.player->instances[0].x = data->play.x * PX;
		data->tex.player->instances[0].enabled = true;
	}
	else
	{
		data->play.right->instances[0].y = data->play.y * PX;
		data->play.right->instances[0].x = data->play.x * PX;
		data->play.right->instances[0].enabled = true;
	}
	rframe++;
}

void	move_updown(t_game *data, char dir)
{
	static int	uframe;

	if (dir == 'W')
	{
		if (uframe % 2 == 0)
		{
			data->play.up[0]->instances[0].y = data->play.y * PX;
			data->play.up[0]->instances[0].x = data->play.x * PX;
			data->play.up[0]->instances[0].enabled = true;
		}
		else
		{
			data->play.up[1]->instances[0].y = data->play.y * PX;
			data->play.up[1]->instances[0].x = data->play.x * PX;
			data->play.up[1]->instances[0].enabled = true;
		}
		uframe++;
	}
	else if (dir == 'S')
	{
		data->play.down->instances[0].y = data->play.y * PX;
		data->play.down->instances[0].x = data->play.x * PX;
		data->play.down->instances[0].enabled = true;
	}
}

void	anim_player(t_game *data, char dir)
{
	data->play.up[0]->instances[0].enabled = false;
	data->play.up[1]->instances[0].enabled = false;
	data->play.down->instances[0].enabled = false;
	data->play.right->instances[0].enabled = false;
	data->play.left[0]->instances[0].enabled = false;
	data->play.left[1]->instances[0].enabled = false;
	data->tex.player->instances[0].enabled = false;
	if (dir == 'W' || dir == 'S')
		move_updown(data, dir);
	else if (dir == 'A')
		move_left(data);
	else if (dir == 'D')
		move_right(data);
}
