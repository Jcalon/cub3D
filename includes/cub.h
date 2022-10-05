/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crazyd <crazyd@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 23:41:22 by crazyd            #+#    #+#             */
/*   Updated: 2022/10/05 05:00:48 by crazyd           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include "libft.h"
# include "mlx.h"
# include <stdbool.h>

# define IMG_W 40
# define IMG_H 40
# define ESC 65307
# define W 119
# define A 97
# define S 115
# define D 100

typedef struct s_map
{
	int		no;
	int		so;
	int		we;
	int		ea;
	int		f;
	int		c;
	char	*no_path;
	char	*so_path;
	char	*we_path;
	char	*ea_path;
	int		f_color[3];
	int		c_color[3];
	int		size_map;
	char	**map;
}	t_map;


bool	check_extension(char *filename);

#endif