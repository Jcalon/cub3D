/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crazyd <crazyd@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 23:41:22 by crazyd            #+#    #+#             */
/*   Updated: 2022/10/06 23:39:09 by crazyd           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include "libft.h"
# include "mlx.h"
# include <stdbool.h>
# include <fcntl.h>

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
	int		size_map;
	char	**map;
}	t_map;

void	init_map(t_map *map);

#endif