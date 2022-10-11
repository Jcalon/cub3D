/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crazyd <crazyd@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 23:42:00 by crazyd            #+#    #+#             */
/*   Updated: 2022/10/11 04:32:53 by crazyd           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static bool	check_extension(char *filename)
{
	if (ft_strlen(filename) > 4
		&& !ft_strcmp(filename + ft_strlen(filename) - 4, ".cub"))
		return (true);
	return (false);
}

int	main(int argc, char *argv[])
{
	t_map	map;
	//t_cub	cub;

	if (argc != 2)
		return(errmsg("Write ./cub3D path_to_map", 1));
	if (!check_extension(argv[1]))
		return(errmsg("Map extension must be .cub", 1));
	else
	{
		map.fd = open(argv[1], O_RDONLY);
		if (map.fd == -1)
			return(strerror(errno), errno);
		init_map(&map, argv[1]);
	}
	clean_map(&map);
}
