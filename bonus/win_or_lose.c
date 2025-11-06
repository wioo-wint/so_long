/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_or_lose.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wintoo <wintoo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 14:46:35 by wintoo            #+#    #+#             */
/*   Updated: 2025/11/05 16:40:37 by wintoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	close_game(mlx_key_data_t keydata, void *param)
{
	t_game	*data;

	data = param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(data->mlx);
}

void	anim_gamewin(void *param)
{
	static float	timer;
	static int		frame;
	t_game			*data;
	int				i;

	data = param;
	data->anim.speed = 0.28f;
	data->anim.end = 11;
	if (frame < 10)
		frame = get_frame(data, &timer, frame);
	i = -1;
	while (++i < 11)
		data->bonus.win[i]->instances[0].enabled = false;
	data->bonus.win[frame]->instances[0].enabled = true;
}

void	anim_gameover(void *param)
{
	static float	timer;
	static int		frame;
	t_game			*data;
	int				i;

	data = param;
	data->anim.speed = 1.1f;
	data->anim.end = 6;
	if (frame < 5)
		frame = get_frame(data, &timer, frame);
	i = -1;
	while (++i < 6)
		data->bonus.gameover[i]->instances[0].enabled = false;
	data->bonus.gameover[frame]->instances[0].enabled = true;
}

void	show_result(t_game *data, int iswin)
{
	mlx_image_t	*text;
	size_t		height;			

	height = data->height - (PX / 2) + 15;
	if (iswin == 1)
	{
		load_win_frames(data);
		mlx_loop_hook(data->mlx, (void *)anim_gamewin, data);
		text = mlx_put_string(data->mlx, "YOU WIN! Press ESC to exit",
				INFOX * 30, height);
	}
	else
	{
		load_gameover_frames(data);
		mlx_loop_hook(data->mlx, (void *)anim_gameover, data);
		text = mlx_put_string(data->mlx, "GAME OVER! Press ESC to exit",
				INFOX * 30, height);
	}
	if (!text)
		mlxerror(data->mlx);
	mlx_key_hook(data->mlx, close_game, data);
}
