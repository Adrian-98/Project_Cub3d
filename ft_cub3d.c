/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub3d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amunoz-p <amunoz-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1019/11/11 17:51:10 by glopez-a          #+#    #+#             */
/*   Updated: 2020/01/24 23:28:22 by amunoz-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libcub.h"

int			cub3d(t_cub *cub)
{
	cub->lenline = -1;
	cub->player.shooting = 0;
	cub->player.fr = 17;
	cub->player.name = "THE KING!";
	cub->player.life = 100;
	cub->player.bullets = 8;
	cub->player.reload = 0;
	cub->player.x_pos += 0.5;
	cub->player.y_pos += 0.5;
	if (!(cub->zbuffer = malloc(sizeof(double) * cub->window.window_width)))
		return (0);
	system("afplay ./sounds/sound.mp3& 2&>/dev/null >/dev/null");
	return (1);
}

void		ft_inicialize(t_cub *cub)
{
	cub->width = 900;
	cub->height = 700;
	cub->movespeed = 0.3;
	cub->rotatespeed = 0.2;
	cub->sky_color = 4626496;
	cub->wall_color = 0x56050;
	cub->floor_color = 48878;
	cub->crouch = 0;
	cub->shot = 0;
}

void		principal(char **argv, t_cub *cub)
{
	int		fd;
	char	*line;

	line = malloc(sizeof(char *));
	fd = open(*argv, O_RDONLY);
	cub3d(cub);
	ft_create_matrix(fd, line, cub);
	cub->mlx_ptr = mlx_init();
	cub->win_ptr = mlx_new_window(cub->mlx_ptr,
	cub->width, cub->height, "mlx42");
	load_cubs(cub);
	mlx_hook(cub->win_ptr, 2, 0, key_press, cub);
	mlx_hook(cub->win_ptr, 3, 0, key_realese, cub);
	mlx_hook(cub->win_ptr, 17, 0, close_window, cub);
	mlx_loop_hook(cub->mlx_ptr, ft_loop, cub);
	mlx_loop(cub->mlx_ptr);
	free(cub);
}

int			main(int argc, char **argv)
{
	t_cub	*cub;

	if (!(cub = malloc(sizeof(t_cub))))
		ft_error();
	ft_inicialize(cub);
	if (argc == 2)
		principal(&argv[1], cub);
	else if (argc == 3 && ft_strncmp("--save", argv[2], 6) == 0)
	{
		printf("\nhola\n");
		principal2(&argv[1], cub);
	}
	else
		ft_error();
	return (0);
}
