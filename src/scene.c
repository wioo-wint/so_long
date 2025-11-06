/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wintoo <wintoo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 18:38:25 by wintoo            #+#    #+#             */
/*   Updated: 2025/11/05 13:16:54 by wintoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

mlx_image_t	*load_texture(mlx_t *mlx, char *path)
{
	mlx_texture_t	*tex;
	mlx_image_t		*img;

	tex = mlx_load_png(path);
	if (!tex)
		mlxerror(mlx);
	img = mlx_texture_to_image(mlx, tex);
	if (!img)
		mlxerror(mlx);
	mlx_delete_texture(tex);
	return (img);
}

void	assign_map(t_game *data, int row, int col)
{
	int	px;
	int	py;
	int	wpattern;

	while (data->map[row][++col] && data->map[row][col] != '\n')
	{
		px = col * PX;
		py = row * PX;
		mlx_image_to_window(data->mlx, data->tex.floor, px, py);
		wpattern = (row + 7 * col + 1) % 3;
		if (data->map[row][col] == '1')
		{
			if (wpattern == 0)
				mlx_image_to_window(data->mlx, data->tex.wall[1], px, py);
			else
				mlx_image_to_window(data->mlx, data->tex.wall[0], px, py);
		}
		else if (data->map[row][col] == 'C')
			mlx_image_to_window(data->mlx, data->tex.collect, px, py);
		else if (data->map[row][col] == 'E')
			mlx_image_to_window(data->mlx, data->tex.exit, px, py);
		else if (data->map[row][col] == 'B')
			data->bonus.ecount++;
	}
}

void	generate_map(t_game *data)
{
	int	row;

	row = -1;
	data->tex.floor = load_texture(data->mlx, "assets/floor/floor.png");
	data->tex.wall[0] = load_texture(data->mlx, "assets/wall/wall1.png");
	data->tex.wall[1] = load_texture(data->mlx, "assets/wall/wall2.png");
	data->tex.collect = load_texture(data->mlx, "assets/collect/collect3.png");
	data->tex.exit = load_texture(data->mlx, "assets/exit.png");
	data->tex.player = load_texture(data->mlx, "assets/player/idle1.png");
	while (data->map[++row] && data->map[row][0] != '\n')
		assign_map(data, row, -1);
	load_playerframes(data, data->play.x * PX, data->play.y * PX);
	if (data->bonus.ecount > 0)
		load_enemyframes(data);
	mlx_image_to_window(data->mlx, data->tex.player,
		data->play.x * PX, data->play.y * PX);
	data->bonus.txtmovenb = mlx_put_string(data->mlx, "Moves: 0",
			INFOX, data->height - (PX / 2) + 15);
	data->bonus.txtscore = mlx_put_string(data->mlx, "Your Score: 0",
			INFOX * 10, data->height - (PX / 2) + 15);
}
