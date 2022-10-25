/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crazyd <crazyd@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 23:50:23 by crazyd            #+#    #+#             */
/*   Updated: 2022/10/25 15:55:33 by crazyd           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	get_element(char *line, t_map *map)
{
	char	**splited;

	splited = ft_split(line, "\a\b\t\n\v\f\r ");
	if (!splited)
	{
		free(line);
		ft_map_error(map, strerror(errno), errno);
	}
	if (ft_array_size(splited) != 2 || ft_strlen(splited[0]) > 2)
	{
		free(line);
		ft_free_array(splited);
		ft_map_error(map, "Invalid element in the .cub file", 1);
	}
	check_element(map, splited, line);
	free(line);
}

static int	skip_map_info(t_map *map, char *line)
{
	while (line && !ft_iswhitespacestr(line))
	{
		free(line);
		line = get_next_line(map->fd);
		map->size_map++;
	}
	return (1);
}

static void	get_texture_end(t_map *map, int counter, char *line)
{
	free(line);
	close(map->fd);
	if (counter < 7)
		ft_map_error(map, "Too many elements in the .cub file", 1);
}

static void	get_texture(t_map *map)
{
	char	*line;
	int		counter;

	counter = 0;
	line = get_next_line(map->fd);
	while (line)
	{
		if (!ft_iswhitespacestr(line) && counter < 6)
		{
			get_element(line, map);
			counter++;
		}
		else if (!ft_iswhitespacestr(line) && counter == 6)
			counter += skip_map_info(map, line);
		else if (!ft_iswhitespacestr(line) && counter > 6)
		{
			free(line);
			ft_map_error(map, "Too many elements in the .cub file", 1);
		}
		else
			free(line);
		line = get_next_line(map->fd);
	}
	get_texture_end(map, counter, line);
}

void	init_map(t_map *map, char *argv)
{
	map->no = NULL;
	map->so = NULL;
	map->we = NULL;
	map->ea = NULL;
	map->f = 0;
	map->c = 0;
	map->size_map = 1;
	map->player_x = 0;
	map->player_x = 0;
	map->map = NULL;
	get_texture(map);
	map->map = malloc(sizeof(char *) * map->size_map);
	if (!map->map)
		ft_map_error(map, strerror(errno), errno);
	map->fd = open(argv, O_RDONLY);
	if (map->fd == -1)
		ft_map_error(map, strerror(errno), errno);
	get_map(map);
	close(map->fd);
	check_map(map);
	if (map->player_x == 0)
		ft_map_error(map, "Player position unset", 1);
}
