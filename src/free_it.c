/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_it.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wintoo <wintoo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 13:28:16 by wintoo            #+#    #+#             */
/*   Updated: 2025/11/05 14:55:58 by wintoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	free2s(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}

void	free1s(char **str)
{
	if (str && *str)
	{
		free(*str);
		*str = NULL;
	}
}

void	free_multi(mlx_t *mlx, mlx_image_t **img, int len)
{
	int	i;

	i = -1;
	while (++i < len)
	{
		if (img[i])
		{
			mlx_delete_image(mlx, img[i]);
			img[i] = NULL;
		}
	}
}

void	free_img(t_game *game)
{
	if (!game || !game->mlx)
		return ;
	if (game->tex.floor)
		mlx_delete_image(game->mlx, game->tex.floor);
	if (game->tex.collect)
		mlx_delete_image(game->mlx, game->tex.collect);
	if (game->tex.exit)
		mlx_delete_image(game->mlx, game->tex.exit);
	if (game->tex.player)
		mlx_delete_image(game->mlx, game->tex.player);
	if (game->bonus.txtmovenb)
		mlx_delete_image(game->mlx, game->bonus.txtmovenb);
	if (game->bonus.txtscore)
		mlx_delete_image(game->mlx, game->bonus.txtscore);
	free_multi(game->mlx, game->tex.wall, WALL_NO);
	if (game->play.right)
		mlx_delete_image(game->mlx, game->play.right);
	if (game->play.down)
		mlx_delete_image(game->mlx, game->play.down);
	free_multi(game->mlx, game->play.left, 2);
	free_multi(game->mlx, game->play.up, 2);
}
