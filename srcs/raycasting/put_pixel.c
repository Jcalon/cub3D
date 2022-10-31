/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcalon <jcalon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 20:07:13 by crazyd            #+#    #+#             */
/*   Updated: 2022/10/31 19:23:34 by jcalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

static void	pixel_put_wall(t_cub *data, int x, int y)
{
	int		px;
	int		px2;
	int		x2;
	int		y2;
	t_img	*wall;

	if (data->wall_type == NORTH)
		wall = &data->north;
	else if (data->wall_type == SOUTH)
		wall = &data->south;
	else if (data->wall_type == EAST)
		wall = &data->east;
	else if (data->wall_type == WEST)
		wall = &data->west;
	if (data->wall_type == NORTH || data->wall_type == EAST)
		x2 = (int)(data->wall_x * (double)IMG_W);
	else
		x2 = (int)((1 - data->wall_x) * (double)IMG_W);
	px = data->screen.size_line * y + x * data->screen.bits_per_pixel / 8;
	y = y - (data->win_height / 2 - (int)data->wall_len / 2);
	y2 = (int)((double)y * (double)wall->height / data->wall_len);
	px2 = wall->size_line * y2 + x2 * wall->bits_per_pixel / 8;
	data->screen.addr[px + 2] = (char)wall->addr[px2 + 2];
	data->screen.addr[px + 1] = (char)wall->addr[px2 + 1];
	data->screen.addr[px] = (char)wall->addr[px2];
}

static void	pixel_put_floor(t_cub *data, int x, int y)
{
	char	*dst;

	dst = data->screen.addr + y * data->screen.size_line
		+ x * data->screen.bits_per_pixel / 8;
	*(unsigned int *)dst = create_trgb(0, data->map.f_color[0],
			data->map.f_color[1], data->map.f_color[2]);
}

static void	pixel_put_sky(t_cub *data, int x, int y)
{
	char	*dst;

	dst = data->screen.addr + y * data->screen.size_line
		+ x * data->screen.bits_per_pixel / 8;
	*(unsigned int *)dst = create_trgb(0, data->map.c_color[0],
			data->map.c_color[1], data->map.c_color[2]);
}

void	put_column_to_win(t_cub *data, int x)
{
	int	y;
	int	draw_end;

	y = 0;
	while (y < -data->wall_len / 2 + data->win_height / 2)
		pixel_put_sky(data, x, y++);
	y = -(int)data->wall_len / 2 + data->win_height / 2;
	if (y < 0)
		y = 0;
	draw_end = data->win_height / 2 + (int)data->wall_len / 2;
	if (draw_end >= data->win_height)
		draw_end = data->win_height;
	while (y < draw_end)
		pixel_put_wall(data, x, y++);
	while (y < data->win_height)
		pixel_put_floor(data, x, y++);
}
