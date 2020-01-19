/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_textures.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrian <adrian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 16:15:21 by glopez-a          #+#    #+#             */
/*   Updated: 2020/01/16 22:38:13 by adrian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libcub.h"

void	load_cubs(t_cub *cub)
{
	int		a;
	int		b;

	a = 64;
	b = 64;
	
	cub->tex[7].img = mlx_xpm_file_to_image(cub->mlx_ptr, "textures/wood.xpm", &a, &b);
	cub->tex[7].data = mlx_get_data_addr(cub->tex[7].img, &cub->tex[7].bpp,
			&cub->tex[7].size_line, &cub->tex[7].endian);
	cub->tex[1].img = mlx_xpm_file_to_image(cub->mlx_ptr, "textures/redbrick.xpm", &a, &b);
	cub->tex[1].data = mlx_get_data_addr(cub->tex[1].img, &cub->tex[1].bpp,
			&cub->tex[1].size_line, &cub->tex[1].endian);
	cub->tex[2].img = mlx_xpm_file_to_image(cub->mlx_ptr, "textures/mossy.xpm", &a, &b);
	cub->tex[2].data = mlx_get_data_addr(cub->tex[2].img, &cub->tex[2].bpp,
			&cub->tex[2].size_line, &cub->tex[2].endian);
	cub->tex[3].img = mlx_xpm_file_to_image(cub->mlx_ptr,
			"textures/redbrick.xpm", &a, &b);
	cub->tex[3].data = mlx_get_data_addr(cub->tex[3].img, &cub->tex[3].bpp,
			&cub->tex[3].size_line, &cub->tex[3].endian);
	cub->tex[4].img = mlx_xpm_file_to_image(cub->mlx_ptr, "textures/stone.xpm", &a, &b);
	cub->tex[4].data = mlx_get_data_addr(cub->tex[4].img, &cub->tex[4].bpp,
			&cub->tex[4].size_line, &cub->tex[4].endian);
	cub->tex[5].img = mlx_xpm_file_to_image(cub->mlx_ptr, "textures/sand.xpm", &a, &b);
	cub->tex[5].data = mlx_get_data_addr(cub->tex[5].img, &cub->tex[5].bpp,
			&cub->tex[5].size_line, &cub->tex[5].endian);
	a = 512;
	b = 512;
	cub->tex[6].img = mlx_xpm_file_to_image(cub->mlx_ptr, "textures/sky.xpm", &a, &b);
	cub->tex[6].data = mlx_get_data_addr(cub->tex[6].img, &cub->tex[6].bpp,
			&cub->tex[6].size_line, &cub->tex[6].endian);
}