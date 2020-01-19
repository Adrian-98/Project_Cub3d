/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amunoz-p <amunoz-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1019/11/11 17:51:10 by glopez-a          #+#    #+#             */
/*   Updated: 2020/01/17 15:45:40 by amunoz-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libcub.h"

void	ft_inicialize(t_cub *cub)
{
	cub->width = 1920;
	cub->height = 1080;
	cub->movespeed = 0.08;
	cub->rotatespeed = 0.08;
	cub->sky_color = 4626496;
	cub->wall_color = 0x56050;
	cub->floor_color = 48878;
	cub->crouch = 0;
	cub->jump = 0;
	
}


int		main(void)
{
	t_cub	*cub;
	int		fd;
	char	*line;
	
	line = malloc(sizeof(char *));
	fd = open("map.cub", O_RDONLY);
	if (!(cub = malloc(sizeof(t_cub))))
		return (0);
	ft_inicialize(cub);
	ft_create_matrix(fd, line, cub);
	cub->mlx_ptr = mlx_init();
	cub->win_ptr = mlx_new_window(cub->mlx_ptr, cub->width, cub->height, "mlx42");
	load_cubs(cub);
	


	mlx_hook(cub->win_ptr, 2, 0, key_press, cub);
	mlx_hook(cub->win_ptr, 3, 0, key_realese, cub);
	
	mlx_loop_hook(cub->mlx_ptr, ft_loop, cub);
	

	mlx_loop(cub->mlx_ptr);
	free(cub);
	return (0);
}
