/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crazyd <crazyd@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 23:41:22 by crazyd            #+#    #+#             */
/*   Updated: 2022/10/20 23:58:06 by crazyd           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include "libft.h"
# include "mlx.h"
# include <stdbool.h>
# include <fcntl.h>
# include <string.h>
# include <errno.h>
# include <math.h>

# define IMG_W 40
# define IMG_H 40
# define ESC 65307
# define W 119
# define A 97
# define S 115
# define D 100
# define LEFT 65361
# define RIGHT 65363
# define NORTH 0
# define SOUTH 1
# define EAST 2
# define WEST 3

typedef struct s_map
{
	int		fd;
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	int		f;
	int		c;
	int		f_color[3];
	int		c_color[3];
	int		player_x;
	int		player_y;
	char	player;
	int		size_map;
	int		wall_x;
	char	**map;
}	t_map;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	int		height;
	int		width;
}	t_img;


typedef struct	s_cub
{
	void	*mlx;
	void	*win;
	int		win_width;
	int		win_height;
	t_map 	map;
	t_img	screen;
	t_img	north;
	t_img	south;
	t_img	west;
	t_img	east;
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	double	ray_dir_x;
	double	ray_dir_y;
	double	map_x;
	double	map_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	step_x;
	double	step_y;
	double	camerax;
	double	speed;
	double	wall_len;
	double	wall_x;
	int		hit;
	int		side;
	int		w;
	int		a;
	int		s;
	int		d;
	int		l;
	int		r;
	int		wall_type;
}	t_cub;

void	init_map(t_map *map, char *argv);
void	get_map(t_map *map, char *argv);
void	check_map(t_map *map);

bool	ft_iswhitespacestr(char *str);

int		errmsg(char *str, int code);
void	ft_map_error(t_map *map, char *str, int code);
void	clean_map(t_map *map);

void	init_coord(t_cub *data);

void	init_window(t_cub *data);

void	move_forward(t_cub *data);
void	move_backward(t_cub *data);
void	move_left(t_cub *data);
void	move_right(t_cub *data);
void	rotate(t_cub *data, bool lr);

int		ft_raycasting(t_cub *data);

void	pixel_put_wall(t_cub *data, int x, int y);
void	pixel_put_floor(t_cub *data, int x, int y);
void	pixel_put_sky(t_cub *data, int x, int y);

int		ft_key(t_cub *data);

int		ft_end(t_cub *data);

#endif