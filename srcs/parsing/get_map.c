/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crazyd <crazyd@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 21:42:32 by crazyd            #+#    #+#             */
/*   Updated: 2022/10/21 21:57:12 by crazyd           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	dup_map(t_map *map, char *line)
{
	int		i;

	i = -1;
	while (line && !ft_iswhitespacestr(line))
	{
		map->map[++i] = ft_strdup(line);
		if (!map->map[i])
		{
			free(line);
			ft_map_error(map, strerror(errno), errno);
		}
		free(line);
		line = get_next_line(map->fd);
	}
	map->map[++i] = NULL;
}

void	get_map(t_map *map)
{
	char	*line;
	int		counter;

	counter = 0;
	line = get_next_line(map->fd);
	while (line)
	{
		if (!ft_iswhitespacestr(line) && counter < 6)
		{
			counter++;
			free(line);
		}
		else if (!ft_iswhitespacestr(line) && counter == 6)
			dup_map(map, line);
		else
			free(line);
		line = get_next_line(map->fd);
	}
	free(line);
}
