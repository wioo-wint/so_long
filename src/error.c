/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wintoo <wintoo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 11:38:10 by wintoo            #+#    #+#             */
/*   Updated: 2025/10/23 17:44:09 by wintoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	index;

	index = 0;
	while (s[index])
	{
		write(fd, &s[index], 1);
		index++;
	}
	write(fd, "\n", 1);
}

void	put_error(char *reason, int type)
{
	write(2, "Error\n", 6);
	if (type == 1)
		perror(reason);
	else if (type == 2)
		ft_putstr_fd(reason, 2);
	exit(EXIT_FAILURE);
}

void	mlxerror(mlx_t *mlx)
{
	write(2, "Error\n", 6);
	ft_putstr_fd((char *)mlx_strerror(mlx_errno), 2);
	if (mlx)
		mlx_close_window(mlx);
	exit(EXIT_FAILURE);
}
