/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcalon <jcalon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 20:55:40 by crazyd            #+#    #+#             */
/*   Updated: 2022/10/31 16:30:05 by jcalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

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
	if (y == 0 || y == (int)ft_array_size(map->map) - 1
		|| x + 1 == (int)ft_strlen(map->map[y]) - 1 || x == 0)
		ft_map_error(map, "Wall breach", 1);
	if (x + 1 < (int)ft_strlen(map->map[y])
		&& !ft_isinstr(map->map[y][x + 1], "NSEW01"))
		ft_map_error(map, "Invalid map description", 1);
	if (x - 1 >= 0 && !ft_isinstr(map->map[y][x - 1], "NSEW01"))
		ft_map_error(map, "Invalid map description", 1);
	if (y + 1 < (int)ft_array_size(map->map)
		&& !ft_isinstr(map->map[y + 1][x], "NSEW01"))
		ft_map_error(map, "Invalid map description", 1);
	if (y - 1 >= 0 && !ft_isinstr(map->map[y - 1][x], "NSEW01"))
		ft_map_error(map, "Invalid map description", 1);
}

static void	set_player_pos(t_map *map, int x, int y)
{
	check_void(map, x, y);
	if (map->player_x != 0)
		ft_map_error(map, "Too many POV", 1);
	map->player_x = x + 0.5;
	map->player_y = y + 0.5;
	map->player = map->map[y][x];
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
			if (ft_isinstr(map->map[y][x], "NSEW"))
				set_player_pos(map, x, y);
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
