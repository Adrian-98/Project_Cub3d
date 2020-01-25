/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libcub.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amunoz-p <amunoz-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 17:59:46 by glopez-a          #+#    #+#             */
/*   Updated: 2020/01/25 12:49:23 by amunoz-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBCUB_H
# define LIBCUB_H
# include "mlx.h"
# include "unistd.h"
# include "fcntl.h"
# include <stdio.h>
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <time.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/ioctl.h>
# include <stdlib.h>

# define texHeight 64
# define texWidth 64
# define WINX 1920
# define WINY 1080

typedef struct				s_sprites_work
{
	double					sp_x;
	double					sp_y;
	double					inv_det;
	double					transform_x;
	double					transform_y;
	int						sp_screen_x;
	int						vms;
	int						sp_height;
	int						draw_start_y;
	int						draw_end_y;
	int						sp_width;
	int						draw_start_x;
	int						draw_end_x;
	int						stripe;
	int						tex_x;
	int						y;
	int						d;
	int						tex_y;
	int						color;
}							t_sprites_work;

typedef struct				s_window
{
	void					*mlx;
	void					*win;
	void					*img;
	void					*img_ptr;
	int						window_width;
	int						window_height;
	int						bpp;
	int						endian;
	int						sl;
}							t_window;

typedef struct				s_sprites
{
	int						x;
	int						y;
	int						tex_index;
}							t_sprites;

typedef struct				s_player
{
	short					life;
	short					bullets;
	char					*name;
	int						shooting;
	int						fr;
	short					reload;
	int						chest_collected;
	int						chest_to_collect;
	int						ended;
	double					x_pos;
	double					y_pos;
	double					x_dir;
	double					y_dir;
}							t_player;

typedef struct	s_texture
{
	void	*img;
	void	*data;
	int		bpp;
	int		size_line;
	int		endian;
}				t_texture;


typedef struct	s_cub
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img;
	char		*data;
	int			bpp;
	int			size_line;
	int			endian;

	t_sprites	*sprites;
	t_player	player;
	t_window	window;
	double		*zbuffer;
	int			lenline;
	
	double		pos_x;
	double		pos_y;
	double		dir_x;
	double		dir_y;
	double		olddir_x;
	double		olddir_y;
	double		plane_x;
	double		plane_y;
	double		oldplane_x;
	double		camera_x;
	double		camera_y;
	double		raydir_x;
	double		raydir_y;
	double		sidedist_x;
	double		sidedist_y;
	double		deltadist_x;
	double		deltadist_y;
	double		perpWalldist;
	double		rotatespeed;
	int			drawstart;
	int			drawend;
	double		movespeed;
	
	int			width;
	int			height;
	int			sky_color;
	int			wall_color;
	int			floor_color;
	int			lineHeight;
	int			map_x;
	int			map_y;
	int			hit;
	int			step_x;
	int			step_y;
	int			side;
	int			matrix[100][100];

	int			walk_front;
	int			walk_back;
	int			walk_left;
	int			walk_right;
	int			rotate_left;
	int			rotate_right;
	
	
	int			tex_x;
	int			tex_y;
	double		wall_x;
	int			id;
	t_texture	tex[20];

	int			shot;
	int			crouch;
}				t_cub;

void		draw_gun(t_cub *cub);
char		*ft_itoa(int n);
void		fps(t_cub *cub);
size_t		ft_strlen(const char *s);
char		*ft_strchr(const char *s, int c);
char		*ft_strdup(const char *s1);
char		*ft_strcat(char *dst, char *src);
char		*ft_strcpy(char *dst, char *src);
char		*ft_strjoin(char const *s1, char const *s2);
int			get_next_line(int fd, char **line);
void		*ft_memcpy(void *dst, const void *src, size_t n);
void		load_cubs(t_cub *cub);
void		ft_crouch_jump(t_cub *cub);
void		ft_create_matrix(int fd, char *line, t_cub *cub);
void		ft_dir(t_cub *cub, char c);
int			ft_loop(t_cub *cub);
void		init_values(t_cub *cub, int x);
void		next_step(t_cub *cub);
void		ft_movement(t_cub *cub);
int			key_press(int keycode, t_cub *cub);
int			key_realese(int keycode, t_cub *cub);
void		put_id(t_cub *cub);
void		ft_verLine(int x, int y, t_cub *cub);
void		draw_sky(t_cub *cub);
int			close_window(t_cub *cub);
void		principal(char **argv, t_cub *cub);
void    	ft_error(void);
void		ft_walk_right(t_cub *cub);
void		ft_walk_left(t_cub *cub);
void		ft_screenshot(t_cub *cub);
void		principal2(char **argv, t_cub *cub);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			cub3d(t_cub *cub);

# endif