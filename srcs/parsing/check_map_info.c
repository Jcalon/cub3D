/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_info.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crazyd <crazyd@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 21:04:05 by crazyd            #+#    #+#             */
/*   Updated: 2022/10/21 21:32:51 by crazyd           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static int	check_rgb(t_map *map, char **rgb, int fc)
{
	if (ft_strlen(rgb[0]) < 4 && ft_strlen(rgb[1]) < 4 && ft_strlen(rgb[2]) < 4
		&& ft_isdigitstr(rgb[0]) && ft_isdigitstr(rgb[1])
		&& ft_isdigitstr(rgb[2]))
	{
		if (fc == 0)
		{
			map->f_color[0] = ft_atoi(rgb[0]);
			map->f_color[1] = ft_atoi(rgb[1]);
			map->f_color[2] = ft_atoi(rgb[2]);
			if (!ft_isrgb(map->f_color[0]) || !ft_isrgb(map->f_color[1])
				|| !ft_isrgb(map->f_color[2]))
				return (0);
		}
		if (fc == 1)
		{
			map->c_color[0] = ft_atoi(rgb[0]);
			map->c_color[1] = ft_atoi(rgb[1]);
			map->c_color[2] = ft_atoi(rgb[2]);
			if (!ft_isrgb(map->c_color[0]) || !ft_isrgb(map->c_color[1])
				|| !ft_isrgb(map->c_color[2]))
				return (0);
		}
		return (1);
	}
	return (0);
}

static int	check_element_sky_floor(char **splited, t_map *map)
{
	char	**rgb;

	if (map->f == 0 && splited[0][0] == 'F' && splited[0][1] == '\0')
	{
		map->f = 1;
		rgb = ft_split(splited[1], ",");
		if (!rgb)
			return (2);
		if (ft_array_size(rgb) == 3 && check_rgb(map, rgb, 0))
			return (ft_free_array(rgb), 1);
		else
			return (ft_free_array(rgb), 0);
	}
	else if (map->c == 0 && splited[0][0] == 'C' && splited[0][1] == '\0')
	{
		map->c = 1;
		rgb = ft_split(splited[1], ",");
		if (!rgb)
			return (2);
		if (ft_array_size(rgb) == 3 && check_rgb(map, rgb, 1))
			return (ft_free_array(rgb), 1);
		else
			return (ft_free_array(rgb), 0);
	}
	return (0);
}

static int	check_element_east_west(char **splited, t_map *map)
{
	int		fd;

	if (map->we == NULL && splited[0][0] == 'W' && splited[0][1] == 'E')
	{
		map->we = ft_strdup(splited[1]);
		if (!map->we)
			return (2);
		fd = open(map->we, O_RDONLY);
		if (fd == -1)
			return (2);
		close(fd);
		return (1);
	}
	else if (map->ea == NULL && splited[0][0] == 'E' && splited[0][1] == 'A')
	{
		map->ea = ft_strdup(splited[1]);
		if (!map->ea)
			return (2);
		fd = open(map->ea, O_RDONLY);
		if (fd == -1)
			return (2);
		close(fd);
		return (1);
	}
	return (check_element_sky_floor(splited, map));
}

static int	check_element_north_south(char **splited, t_map *map)
{
	int		fd;

	if (map->no == NULL && splited[0][0] == 'N' && splited[0][1] == 'O')
	{
		map->no = ft_strdup(splited[1]);
		if (!map->no)
			return (2);
		fd = open(map->no, O_RDONLY);
		if (fd == -1)
			return (2);
		close(fd);
		return (1);
	}
	else if (map->so == NULL && splited[0][0] == 'S' && splited[0][1] == 'O')
	{
		map->so = ft_strdup(splited[1]);
		if (!map->so)
			return (2);
		fd = open(map->so, O_RDONLY);
		if (fd == -1)
			return (2);
		close(fd);
		return (1);
	}
	return (check_element_east_west(splited, map));
}

void	check_element(t_map *map, char **splited, char *line)
{
	int		check;

	check = check_element_north_south(splited, map);
	ft_free_array(splited);
	if (!check)
	{
		free(line);
		ft_map_error(map, "Invalid element in the .cub file", 1);
	}
	else if (check == 2)
	{
		free(line);
		ft_map_error(map, strerror(errno), errno);
	}
}
