/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crazyd <crazyd@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 20:20:21 by crazyd            #+#    #+#             */
/*   Updated: 2022/10/21 20:22:41 by crazyd           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	init_camera_direction_ew(t_cub *data)
{
	if (data->map.player == 'W')
	{
		data->dir_x = -1.0;
		data->dir_y = 0.0;
		data->plane_x = 0.0;
		data->plane_y = -0.66;
	}
	else if (data->map.player == 'E')
	{
		data->dir_x = 1.0;
		data->dir_y = 0.0;
		data->plane_x = 0.0;
		data->plane_y = 0.66;
	}
}

static void	init_camera_direction(t_cub *data)
{
	if (data->map.player == 'N')
	{
		data->dir_x = 0.0;
		data->dir_y = -1.0;
		data->plane_x = 0.66;
		data->plane_y = 0.0;
	}
	else if (data->map.player == 'S')
	{
		data->dir_x = 0.0;
		data->dir_y = 1.0;
		data->plane_x = -0.66;
		data->plane_y = 0.0;
	}
	else
		init_camera_direction_ew(data);
}

void	init_data(t_cub *data)
{
	data->speed = 0.2;
	data->pos_x = data->map.player_x;
	data->pos_y = data->map.player_y;
	data->w = 0;
	data->a = 0;
	data->s = 0;
	data->d = 0;
	data->l = 0;
	data->r = 0;
	init_camera_direction(data);
}

static void	init_texture_img(t_cub *data)
{
	data->north.img = mlx_xpm_file_to_image(data->mlx, data->map.no,
			&data->north.width, &data->north.height);
	data->north.addr = mlx_get_data_addr(data->north.img,
			&data->north.bits_per_pixel, &data->north.size_line,
			&data->north.endian);
	data->south.img = mlx_xpm_file_to_image(data->mlx, data->map.so,
			&data->south.width, &data->south.height);
	data->south.addr = mlx_get_data_addr(data->south.img,
			&data->south.bits_per_pixel, &data->south.size_line,
			&data->south.endian);
	data->east.img = mlx_xpm_file_to_image(data->mlx, data->map.ea,
			&data->east.width, &data->east.height);
	data->east.addr = mlx_get_data_addr(data->east.img,
			&data->east.bits_per_pixel, &data->east.size_line,
			&data->east.endian);
	data->west.img = mlx_xpm_file_to_image(data->mlx, data->map.we,
			&data->west.width, &data->west.height);
	data->west.addr = mlx_get_data_addr(data->west.img,
			&data->west.bits_per_pixel, &data->west.size_line,
			&data->west.endian);
}

void	init_screen(t_cub *data)
{
	data->win_width = 0;
	data->win_height = 0;
	mlx_get_screen_size(data->mlx, &data->win_width, &data->win_height);
	data->win = mlx_new_window(data->mlx,
			data->win_width, data->win_height, "La magie des fêtes");
	data->screen.img = mlx_new_image(data->mlx,
			data->win_width, data->win_height);
	data->screen.addr = mlx_get_data_addr(data->screen.img,
			&data->screen.bits_per_pixel, &data->screen.size_line,
			&data->screen.endian);
	init_texture_img(data);
}
