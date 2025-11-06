/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wintoo <wintoo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 12:32:08 by wintoo            #+#    #+#             */
/*   Updated: 2025/11/05 12:32:24 by wintoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	set_score(t_game *data, int x, int y)
{
	static size_t	collected;
	size_t			i;

	if (data->map[y][x] == 'C')
	{
		data->map[y][x] = '0';
		i = -1;
		while (++i < data->tex.collect->count)
		{
			if (data->tex.collect->instances[i].x == x * PX
				&& data->tex.collect->instances[i].y == y * PX)
			{
				data->tex.collect->instances[i].enabled = false;
				break ;
			}
		}
		collected++;
		put_info(data, collected, INFOX * 10, &data->bonus.txtscore);
	}
	else if (data->map[y][x] == 'E' && collected == data->score)
		show_result(data, 1);
	else if (data->map[y][x] == 'E')
		return (0);
	return (1);
}

int	move_player(t_game *data, char dir, int speed)
{
	int		new_y;
	int		new_x;

	new_y = data->play.y;
	new_x = data->play.x;
	if (dir == 'W' || dir == 'S')
		new_y += speed;
	else if (dir == 'A' || dir == 'D')
		new_x += speed;
	if (data->map[new_y][new_x] == '1' || !set_score(data, new_x, new_y))
		return (0);
	data->play.y = new_y;
	data->play.x = new_x;
	anim_player(data, dir);
	return (1);
}

void	input_setting(mlx_key_data_t keydata, void *param)
{
	t_game		*data;
	static int	movenb;
	int			pre_nb;
	int			speed;

	data = param;
	speed = 1;
	pre_nb = movenb;
	if (keydata.action == MLX_PRESS)
	{
		if (keydata.key == MLX_KEY_ESCAPE)
			mlx_close_window(data->mlx);
		else if (keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_UP)
			movenb += move_player(data, 'W', -speed);
		else if (keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_DOWN)
			movenb += move_player(data, 'S', speed);
		else if (keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_LEFT)
			movenb += move_player(data, 'A', -speed);
		else if (keydata.key == MLX_KEY_D || keydata.key == MLX_KEY_RIGHT)
			movenb += move_player(data, 'D', speed);
		if (pre_nb != movenb)
			put_info(data, movenb, INFOX, &data->bonus.txtmovenb);
	}
}

// void	input_setting(void *param)
// {
// 	t_game	*data;
// 	int		speed;

// 	data = param;
// 	speed = 1;
// 	if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE))
// 		mlx_close_window(data->mlx);
// 	if (mlx_is_key_down(data->mlx, MLX_KEY_W))
// 		move_player(data, 'U', -speed);
// 	if (mlx_is_key_down(data->mlx, MLX_KEY_S))
// 		move_player(data, 'D', speed);
// 	if (mlx_is_key_down(data->mlx, MLX_KEY_A))
// 		move_player(data, 'L', -speed);
// 	if (mlx_is_key_down(data->mlx, MLX_KEY_D))
// 		move_player(data, 'R', speed);
// }
