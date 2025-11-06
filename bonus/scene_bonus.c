/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wintoo <wintoo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 11:10:07 by wintoo            #+#    #+#             */
/*   Updated: 2025/11/05 14:57:18 by wintoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	load_playerframes(t_game *data, int x, int y)
{
	data->play.up[0] = load_texture(data->mlx, "assets/player/up1.png");
	data->play.up[1] = load_texture(data->mlx, "assets/player/up2.png");
	data->play.down = load_texture(data->mlx, "assets/player/down1.png");
	data->play.right = load_texture(data->mlx, "assets/player/right1.png");
	data->play.left[0] = load_texture(data->mlx, "assets/player/left1.png");
	data->play.left[1] = load_texture(data->mlx, "assets/player/left2.png");
	mlx_image_to_window(data->mlx, data->play.up[0], x, y);
	mlx_image_to_window(data->mlx, data->play.up[1], x, y);
	mlx_image_to_window(data->mlx, data->play.down, x, y);
	mlx_image_to_window(data->mlx, data->play.right, x, y);
	mlx_image_to_window(data->mlx, data->play.left[0], x, y);
	mlx_image_to_window(data->mlx, data->play.left[1], x, y);
	data->play.up[0]->instances[0].enabled = false;
	data->play.up[1]->instances[0].enabled = false;
	data->play.down->instances[0].enabled = false;
	data->play.right->instances[0].enabled = false;
	data->play.left[0]->instances[0].enabled = false;
	data->play.left[1]->instances[0].enabled = false;
}

void	generate_enemy(t_game *data, int row)
{
	int	col;
	int	inst;
	int	i;

	col = -1;
	while (data->map[row][++col] && data->map[row][col] != '\n')
	{
		if (data->map[row][col] == 'B')
		{
			i = 0;
			while (i < 4)
			{
				mlx_image_to_window(data->mlx, data->bonus.enemy[i],
					col * PX, row * PX);
				inst = data->bonus.enemy[i]->count - 1;
				if (inst >= 0)
					data->bonus.enemy[i]->instances[inst].enabled = false;
				i++;
			}
		}
	}
}

void	load_enemyframes(t_game *data)
{
	int	row;

	row = -1;
	data->bonus.enemy[0] = load_texture(data->mlx, "assets/enemy/L1.png");
	data->bonus.enemy[1] = load_texture(data->mlx, "assets/enemy/L2.png");
	data->bonus.enemy[2] = load_texture(data->mlx, "assets/enemy/R1.png");
	data->bonus.enemy[3] = load_texture(data->mlx, "assets/enemy/R2.png");
	while (data->map[++row] && data->map[row][0] != '\n')
		generate_enemy(data, row);
}

void	load_gameover_frames(t_game *data)
{
	int	i;

	data->bonus.gameover[0] = load_texture(data->mlx, "assets/gameover/1.png");
	data->bonus.gameover[1] = load_texture(data->mlx, "assets/gameover/2.png");
	data->bonus.gameover[2] = load_texture(data->mlx, "assets/gameover/3.png");
	data->bonus.gameover[3] = load_texture(data->mlx, "assets/gameover/4.png");
	data->bonus.gameover[4] = load_texture(data->mlx, "assets/gameover/5.png");
	data->bonus.gameover[5] = load_texture(data->mlx, "assets/gameover/6.png");
	i = -1;
	while (++i < 6)
	{
		mlx_resize_image(data->bonus.gameover[i],
			data->width, data->height - (PX / 2));
		mlx_image_to_window(data->mlx, data->bonus.gameover[i], 0, 0);
		data->bonus.gameover[i]->instances[0].enabled = false;
	}
}

void	load_win_frames(t_game *data)
{
	int	i;

	data->bonus.win[0] = load_texture(data->mlx, "assets/win/win1.png");
	data->bonus.win[1] = load_texture(data->mlx, "assets/win/win2.png");
	data->bonus.win[2] = load_texture(data->mlx, "assets/win/win3.png");
	data->bonus.win[3] = load_texture(data->mlx, "assets/win/win4.png");
	data->bonus.win[4] = load_texture(data->mlx, "assets/win/win5.png");
	data->bonus.win[5] = load_texture(data->mlx, "assets/win/win6.png");
	data->bonus.win[6] = load_texture(data->mlx, "assets/win/win7.png");
	data->bonus.win[7] = load_texture(data->mlx, "assets/win/win8.png");
	data->bonus.win[8] = load_texture(data->mlx, "assets/win/win9.png");
	data->bonus.win[9] = load_texture(data->mlx, "assets/win/win10.png");
	data->bonus.win[10] = load_texture(data->mlx, "assets/win/win11.png");
	i = -1;
	while (++i < 11)
	{
		mlx_resize_image(data->bonus.win[i],
			data->width, data->height - (PX / 2));
		mlx_image_to_window(data->mlx, data->bonus.win[i], 0, 0);
		data->bonus.win[i]->instances[0].enabled = false;
	}
}
