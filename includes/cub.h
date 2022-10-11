/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crazyd <crazyd@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 23:41:22 by crazyd            #+#    #+#             */
/*   Updated: 2022/10/11 04:38:02 by crazyd           ###   ########.fr       */
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

# define IMG_W 40
# define IMG_H 40
# define ESC 65307
# define W 119
# define A 97
# define S 115
# define D 100

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
	int		size_map;
	int		wall_x;
	char	**map;
}	t_map;

typedef struct	s_cub
{
	struct	t_map *mapdata;
}	t_cub;

void	init_map(t_map *map, char *argv);
void	get_map(t_map *map, char *argv);
void	check_map(t_map *map);

bool	ft_iswhitespacestr(char *str);

int		errmsg(char *str, int code);
void	ft_map_error(t_map *map, char *str, int code);
void	clean_map(t_map *map);

int		backtrack_top(int x, int y, t_map *map);

int		backtrack_bot(int x, int y, t_map *map);

int		backtrack_left(int x, int y, t_map *map);

int		backtrack_right(int x, int y, t_map *map);

#endif