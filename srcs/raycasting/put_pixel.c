#include "cub.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	pixel_put_wall(t_cub *data, int x, int y)
{
	int px;
	int px2;
	int x2;
	int y2;
	t_img	*wall;

	if (data->wall_type == NORTH)
		wall = &data->north;
	else if (data->wall_type == SOUTH)
		wall = &data->south;
	else if (data->wall_type == EAST)
		wall = &data->east;
	else if (data->wall_type == WEST)
		wall = &data->west;
	
	x2 = (int)(data->wall_x * (double)IMG_W);
	// if (data->wall_type == WEST || data->wall_type == NORTH)
	// 	x2 = wall->width - x2 - 1;
	px = data->screen.size_line * y + x * data->screen.bits_per_pixel / 8;
	y = y - (data->win_height / 2 - (int)data->wall_len / 2);
	y2 = (int)((double)y * (double)wall->height / data->wall_len);
	px2 = wall->size_line * y2 + x2 * wall->bits_per_pixel / 8;
	data->screen.addr[px + 2] = (char)wall->addr[px2 + 2];
	data->screen.addr[px + 1] = (char)wall->addr[px2 + 1];
	data->screen.addr[px] = (char)wall->addr[px2];
}

void	pixel_put_floor(t_cub *data, int x, int y)
{
	char	*dst;

	dst = data->screen.addr + y * data->screen.size_line + x * data->screen.bits_per_pixel / 8;
	*(unsigned int*)dst = create_trgb(0, data->map.f_color[0], data->map.f_color[1], data->map.f_color[2]);
}

void	pixel_put_sky(t_cub *data, int x, int y)
{
	char	*dst;

	dst = data->screen.addr + y * data->screen.size_line + x * data->screen.bits_per_pixel / 8;
	*(unsigned int*)dst = create_trgb(0, data->map.c_color[0], data->map.c_color[1], data->map.c_color[2]);
}