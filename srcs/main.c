/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crazyd <crazyd@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 23:42:00 by crazyd            #+#    #+#             */
/*   Updated: 2022/10/07 21:07:02 by crazyd           ###   ########.fr       */
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

	if (argc != 2)
		return(printf("erreur nbr args\n"));
	if (!check_extension(argv[1]))
		return(printf("erreur ext\n"));
	else
	{
		printf("cc\n");
		map.fd = open(argv[1], O_RDONLY);
		if (map.fd == -1)
			return(printf("erreur open\n"));
		init_map(&map);
		printf("cc\n");
	}
}
