/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wintoo <wintoo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 10:27:29 by wintoo            #+#    #+#             */
/*   Updated: 2025/11/06 13:03:43 by wintoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <errno.h>
# include "mlxlib/include/MLX42/MLX42.h"

// game data
# define PX 100
# define WALL_NO 2
# define INFOX 30

typedef struct s_texture
{
	mlx_image_t	*floor;
	mlx_image_t	*wall[WALL_NO];
	mlx_image_t	*collect;
	mlx_image_t	*exit;
	mlx_image_t	*player;
}	t_texture;

typedef struct s_player
{
	int			x;
	int			y;
	mlx_image_t	*up[2];
	mlx_image_t	*down;
	mlx_image_t	*right;
	mlx_image_t	*left[2];
}	t_player;

typedef struct s_animation
{
	int		end;
	float	speed;
}	t_animation;

typedef struct s_bonus
{
	mlx_image_t	*txtmovenb;
	mlx_image_t	*txtscore;
	mlx_image_t	*gameover[6];
	mlx_image_t	*win[11];
	mlx_image_t	*enemy[4];
	int			ecount;
	int			esp;
	int			edir;
	int			eside;
	int			epos;
}	t_bonus;

typedef struct s_game
{
	char			**map;
	size_t			height;
	size_t			width;
	mlx_t			*mlx;
	t_texture		tex;
	t_player		play;
	size_t			score;
	t_animation		anim;
	t_bonus			bonus;
}	t_game;

void		free2s(char **str);
void		free1s(char **str);
void		free_img(t_game *game);
void		put_error(char *reason, int type);
void		mlxerror(mlx_t *mlx);

// map validation
void		isvalid_rect(char **map);
void		check_cep(t_game *data);
void		check_wall(char **map);
void		check_path(t_game *data);
size_t		find_height(char *file);
void		get_map(t_game *data, char *file);

// mlx - game starts!
int			set_score(t_game *data, int x, int y);
void		input_setting(mlx_key_data_t keydata, void *param);
void		init_screen(t_game *game);
void		init_images(t_game *data);
mlx_image_t	*load_texture(mlx_t *mlx, char *path);
void		generate_map(t_game *data);

//bonus
void		put_info(t_game *data, int nb, int x, mlx_image_t **txt);
void		load_playerframes(t_game *data, int x, int y);
void		load_enemyframes(t_game *data);
void		load_win_frames(t_game *data);
void		load_gameover_frames(t_game *data);
int			get_frame(t_game *data, float *timer, int fr);
void		anim_enemy(void	*param);
void		anim_player(t_game *data, char dir);
void		show_result(t_game *data, int iswin);

// util libs
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 7
# endif

char		*get_next_line(int fd);

size_t		ft_strlen(const char *str);
char		*ft_strdup(const char *str);
char		*ft_strjoin(const char *s1, const char *s2);
char		*ft_strchr(const char *s, int c);
void		ft_putstr_fd(char *s, int fd);
char		*ft_itoa(int n);
int			ft_strncmp(const char *s1, const char *s2, size_t n);

#endif