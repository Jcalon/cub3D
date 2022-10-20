#include "cub.h"

double	digital_differential_analyzer(t_cub *data)
{
	double	perp_wall_dist;

	perp_wall_dist = 0;	
	while (data->hit == 0)
	{
		if (data->side_dist_x < data->side_dist_y) 
		{
			data->side_dist_x += data->delta_dist_x;// agrandis le rayon
			data->map_x += data->step_x;// prochaine case ou case précédente sur X
			data->side = 0;// orientation du mur
			if (data->ray_dir_x < 0)
				data->wall_type = WEST;
			else
				data->wall_type = EAST;
		}
		else
		{
			data->side_dist_y += data->delta_dist_y;// agrandis le rayon
			data->map_y += data->step_y;// prochaine case ou case précédente sur Y
			data->side = 1;// orientation du mur
			if (data->ray_dir_y < 0)
				data->wall_type = NORTH;
			else
				data->wall_type = SOUTH;
		}
		if (data->map.map[(int)data->map_y][(int)data->map_x] == '1') // si le rayon rencontre un mur
			data->hit = 1;// stoppe la boucle
	}
	if (data->side == 0)
	{
		perp_wall_dist = data->side_dist_x - data->delta_dist_x;
		data->wall_x = data->pos_y + perp_wall_dist * data->ray_dir_y;
	}
	else
	{
		perp_wall_dist = data->side_dist_y - data->delta_dist_y;
		data->wall_x = data->pos_x + perp_wall_dist * data->ray_dir_x;
	}
	return (perp_wall_dist);
}

void	init_ray(t_cub *data, int x)
{
	data->hit = 0;
	data->camerax = 2.0 * (double)x / (double)data->win_width - 1.0;
	data->ray_dir_x = data->dir_x + data->plane_x * data->camerax;
	data->ray_dir_y = data->dir_y + data->plane_y * data->camerax;
	data->map_x = (int)data->pos_x;
	data->map_y = (int)data->pos_y;
	data->delta_dist_x = fabs(1.0 / data->ray_dir_x);
	data->delta_dist_y = fabs(1.0 / data->ray_dir_y);
	if (data->ray_dir_x < 0)
	{
		data->step_x = -1.0;
 		data->side_dist_x = (data->pos_x - data->map_x) * data->delta_dist_x;
	}
	else
	{
		data->step_x = 1.0;
 		data->side_dist_x = (1.0 - data->pos_x + data->map_x) * data->delta_dist_x;
	}
	if (data->ray_dir_y < 0)
	{
		data->step_y = -1.0;
 		data->side_dist_y = (data->pos_y - data->map_y) * data->delta_dist_y;
	}
	else
	{
		data->step_y = 1.0;
 		data->side_dist_y = (1.0 - data->pos_y + data->map_y) * data->delta_dist_y;
	}
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

int	ft_raycasting(t_cub *data)
{
	int	x;
	double	perp_wall_dist;

	ft_key(data);
	x = 0;
	while (x < data->win_width)
	{
		init_ray(data, x);
		perp_wall_dist = digital_differential_analyzer(data); // distance corrigée du rayon
		data->wall_len = (double)data->win_height / perp_wall_dist;
		data->wall_x -= floor((data->wall_x));
		put_column_to_win(data, x);
		x++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->screen.img, 0, 0);
	// ft_key(data);
	return (0);
}