/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_screen_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wintoo <wintoo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 14:17:31 by wintoo            #+#    #+#             */
/*   Updated: 2025/11/05 16:59:42 by wintoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	put_info(t_game *data, int nb, int x, mlx_image_t **txt)
{
	char	*text;
	char	*tmp;

	tmp = ft_itoa(nb);
	if (!tmp)
		return ;
	if (x == INFOX)
		text = ft_strjoin("Moves: ", tmp);
	else
		text = ft_strjoin("Your Score: ", tmp);
	free1s(&tmp);
	if (!text)
		return ;
	if (x == INFOX)
		ft_putstr_fd(text, 1);
	if (*txt)
	{
		mlx_delete_image(data->mlx, *txt);
		*txt = NULL;
	}
	*txt = mlx_put_string(data->mlx, text,
			x, data->height - (PX / 2) + 15);
	free1s(&text);
}
