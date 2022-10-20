/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crazyd <crazyd@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 21:42:32 by crazyd            #+#    #+#             */
/*   Updated: 2022/10/19 22:37:14 by crazyd           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

bool	isinstr(char c, char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (true);
		i++;
	}
	return (false);
}

static void	check_space(t_map *map, int x, int y)
{
	if (x + 1 < (int)ft_strlen(map->map[y]) && map->map[y][x + 1] == '0')
		ft_map_error(map, "Invalid map description", 1);
	if (x - 1 >= 0 && map->map[y][x - 1] == '0')
		ft_map_error(map, "Invalid map description", 1);
	if (y + 1 < (int)ft_array_size(map->map) && map->map[y + 1][x] == '0')
		ft_map_error(map, "Invalid map description", 1);
	if (y - 1 >= 0 && map->map[y - 1][x] == '0')
		ft_map_error(map, "Invalid map description", 1);
}

static void	check_void(t_map *map, int x, int y)
{
	if (y == 0 || y == (int)ft_array_size(map->map) - 1 || x + 1 == (int)ft_strlen(map->map[y]) - 1 || x == 0)
		ft_map_error(map, "Wall breach", 1);
	if (x + 1 < (int)ft_strlen(map->map[y]) && !isinstr(map->map[y][x + 1], "NSEW01"))
		ft_map_error(map, "Invalid map description", 1);
	if (x - 1 >= 0 && !isinstr(map->map[y][x - 1], "NSEW01"))
		ft_map_error(map, "Invalid map description", 1);
	if (y + 1 < (int)ft_array_size(map->map) && !isinstr(map->map[y + 1][x], "NSEW01"))
		ft_map_error(map, "Invalid map description", 1);
	if (y - 1 >= 0 && !isinstr(map->map[y - 1][x], "NSEW01"))
		ft_map_error(map, "Invalid map description", 1);
}

void	check_map(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (map->map[y] != NULL)
	{
		x = 0;
		while (map->map[y][x] != '\0')
		{
			if (isinstr(map->map[y][x], "NSEW"))
			{
				if (map->player_x != 0)
					ft_map_error(map, "Too many POV", 1);
				map->player_x = x;
				map->player_y = y;
				map->player = map->map[y][x];
			}
			else if (map->map[y][x] == ' ')
				check_space(map, x, y);
			else if (map->map[y][x] == '0')
				check_void(map, x, y);
			else if (map->map[y][x] != '1' && map->map[y][x] != '\n')
				ft_map_error(map, "Invalid character in map description", 1);
			x++;
		}
		y++;
	}
}

void	get_map(t_map *map, char *argv)
{
	char	*line;
	int		counter;
	int		i;

	map->fd = open(argv, O_RDONLY);
	if (map->fd == -1)
		ft_map_error(map, strerror(errno), errno);
	counter = 0;
	i = -1;
	line = get_next_line(map->fd);
	while (line)
	{
		if (!ft_iswhitespacestr(line) && counter < 6)
			counter++;
		else if (!ft_iswhitespacestr(line) && counter == 6)
		{
			while (line && !ft_iswhitespacestr(line))
			{
				map->map[++i] = ft_strdup(line);
				if (!map->map[i])
					ft_map_error(map, strerror(errno), errno);
				free(line);
				line = get_next_line(map->fd);
			}
			map->map[++i] = NULL;
		}
		free(line);
		line = get_next_line(map->fd);
	}
	free(line);
	close(map->fd);
}