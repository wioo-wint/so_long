/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wintoo <wintoo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 11:46:13 by wintoo            #+#    #+#             */
/*   Updated: 2025/11/06 13:07:42 by wintoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	init_screen(t_game *data)
{
	data->bonus.esp = -10;
	data->bonus.edir = 0;
	data->bonus.ecount = 0;
	data->bonus.eside = 0;
	data->width = PX * (ft_strlen(data->map[0]) - 1);
	data->height = (PX * data->height) + PX / 2;
	data->mlx = mlx_init(data->width, data->height, "so_long", false);
	if (!data->mlx)
		mlxerror(data->mlx);
	generate_map(data);
	mlx_key_hook(data->mlx, input_setting, data);
	if (data->bonus.ecount > 0)
		mlx_loop_hook(data->mlx, (void *)anim_enemy, data);
}

void	isvalid_file(char *file)
{
	int	len;
	int	i;

	len = ft_strlen(file);
	i = len - 4;
	if (ft_strncmp(file + i, ".ber", 4))
		put_error("Invalid File Extension", 2);
}

int	main(int argc, char **argv)
{
	t_game	data;

	if (argc < 2)
		put_error("Argument too short - Please enter map file", 2);
	data.score = 0;
	isvalid_file(argv[1]);
	get_map(&data, argv[1]);
	init_screen(&data);
	mlx_loop(data.mlx);
	free_img(&data);
	free2s(data.map);
	mlx_terminate(data.mlx);
	return (0);
}
