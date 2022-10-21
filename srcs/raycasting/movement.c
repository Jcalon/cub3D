/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crazyd <crazyd@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 20:03:33 by crazyd            #+#    #+#             */
/*   Updated: 2022/10/21 20:03:56 by crazyd           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	move_forward(t_cub *data)
{
	int	x;
	int	y;

	x = floor(data->pos_x + data->dir_x * data->speed);
	y = floor(data->pos_y + data->dir_y * data->speed);
	if (data->map.map[y][x] == '1')
		return ;
	data->pos_x += (data->dir_x * data->speed);
	data->pos_y += (data->dir_y * data->speed);
}

void	move_backward(t_cub *data)
{
	int	x;
	int	y;

	x = floor(data->pos_x - data->dir_x * data->speed);
	y = floor(data->pos_y - data->dir_y * data->speed);
	if (data->map.map[y][x] == '1')
		return ;
	data->pos_x -= (data->dir_x * data->speed);
	data->pos_y -= (data->dir_y * data->speed);
}

void	move_left(t_cub *data)
{
	int	x;
	int	y;

	x = floor(data->pos_x - data->plane_x * data->speed);
	y = floor(data->pos_y - data->plane_y * data->speed);
	if (data->map.map[y][x] == '1')
		return ;
	data->pos_x -= (data->plane_x * data->speed);
	data->pos_y -= (data->plane_y * data->speed);
}

void	move_right(t_cub *data)
{
	int	x;
	int	y;

	x = floor(data->pos_x + data->plane_x * data->speed);
	y = floor(data->pos_y + data->plane_y * data->speed);
	if (data->map.map[y][x] == '1')
		return ;
	data->pos_x += (data->plane_x * data->speed);
	data->pos_y += (data->plane_y * data->speed);
}

void	rotate(t_cub *data, bool lr)
{
	double	tmp_dir;
	double	tmp_plane;
	double	rot_speed;

	rot_speed = data->speed;
	if (lr == 1)
		rot_speed *= -1;
	tmp_dir = data->dir_x;
	data->dir_x = data->dir_x * cos(rot_speed) - data->dir_y * sin(rot_speed);
	data->dir_y = tmp_dir * sin(rot_speed) + data->dir_y * cos(rot_speed);
	tmp_plane = data->plane_x;
	data->plane_x = data->plane_x * cos(rot_speed)
		- data->plane_y * sin(rot_speed);
	data->plane_y = tmp_plane * sin(rot_speed) + data->plane_y * cos(rot_speed);
}
