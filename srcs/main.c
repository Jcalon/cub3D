/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crazyd <crazyd@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 23:42:00 by crazyd            #+#    #+#             */
/*   Updated: 2022/10/21 21:42:08 by crazyd           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	ft_key_action(t_cub *data)
{
	if (data->w == W)
		move_forward(data);
	if (data->a == A)
		move_left(data);
	if (data->s == S)
		move_backward(data);
	if (data->d == D)
		move_right(data);
	if (data->r == RIGHT)
		rotate(data, 0);
	if (data->l == LEFT)
		rotate(data, 1);
	return (0);
}

static int	ft_keypress(int keycode, t_cub *data)
{
	if (keycode == ESC)
		ft_end(data);
	else if (keycode == W)
		data->w = keycode;
	else if (keycode == A)
		data->a = keycode;
	else if (keycode == S)
		data->s = keycode;
	else if (keycode == D)
		data->d = keycode;
	else if (keycode == RIGHT)
		data->r = keycode;
	else if (keycode == LEFT)
		data->l = keycode;
	return (0);
}

static int	ft_keyrelease(int keycode, t_cub *data)
{
	if (keycode == ESC)
		ft_end(data);
	else if (keycode == W)
		data->w = 0;
	else if (keycode == A)
		data->a = 0;
	else if (keycode == S)
		data->s = 0;
	else if (keycode == D)
		data->d = 0;
	else if (keycode == RIGHT)
		data->r = 0;
	else if (keycode == LEFT)
		data->l = 0;
	return (0);
}

static void	ft_render_next_frame(t_cub *data)
{
	mlx_hook(data->win, 17, 1L << 2, ft_end, data);
	mlx_hook(data->win, 2, 1L << 0, ft_keypress, data);
	mlx_loop_hook(data->mlx, ft_raycasting, data);
	mlx_hook(data->win, 3, 1L << 1, ft_keyrelease, data);
	mlx_loop(data->mlx);
}

int	main(int argc, char *argv[])
{
	t_cub	data;

	if (argc != 2)
		return (errmsg("Write ./cub3D path_to_map", 1));
	if (!check_extension(argv[1]))
		return (errmsg("Map extension must be .cub", 1));
	else
	{
		data.map.fd = open(argv[1], O_RDONLY);
		if (data.map.fd == -1)
			return (strerror(errno), errno);
		init_map(&data.map, argv[1]);
	}
	data.mlx = mlx_init();
	init_data(&data);
	init_screen(&data);
	ft_render_next_frame(&data);
	return (0);
}
