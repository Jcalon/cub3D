/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crazyd <crazyd@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 23:50:23 by crazyd            #+#    #+#             */
/*   Updated: 2022/10/11 04:31:47 by crazyd           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

bool	ft_iswhitespacestr(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] && ft_iswhitespace(str[i]))
		i++;
	if (ft_strlen(str) == i)
		return (true);
	return (false);
}

bool	ft_isdigitstr(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] && ft_isdigit(str[i]))
		i++;
	if (ft_strlen(str) == i)
		return (true);
	return (false);
}

bool	ft_isrgb(int nbr)
{
	if (nbr < 0 || nbr > 255)
		return (false);
	return (true);
}

static int	check_rgb(t_map *map, char **rgb, int fc)
{
	if (ft_strlen(rgb[0]) < 4 && ft_strlen(rgb[1]) < 4 && ft_strlen(rgb[2])< 4
		&& ft_isdigitstr(rgb[0]) && ft_isdigitstr(rgb[1]) && ft_isdigitstr(rgb[2]))
	{
		if (fc == 0)
		{
			map->f_color[0] = ft_atoi(rgb[0]);
			map->f_color[1] = ft_atoi(rgb[1]);
			map->f_color[2] = ft_atoi(rgb[2]);
			if (!ft_isrgb(map->f_color[0]) || !ft_isrgb(map->f_color[1]) || !ft_isrgb(map->f_color[2]))
				return (0);
		}
		if (fc == 1)
		{
			map->c_color[0] = ft_atoi(rgb[0]);
			map->c_color[1] = ft_atoi(rgb[1]);
			map->c_color[2] = ft_atoi(rgb[2]);
			if (!ft_isrgb(map->c_color[0]) || !ft_isrgb(map->c_color[1]) || !ft_isrgb(map->c_color[2]))
				return (0);
		}
		return (1);
	}
	return (0);
}

static int	check_element(char **splited, t_map *map)
{
	char	**rgb;
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
	else if (map->we == NULL && splited[0][0] == 'W' && splited[0][1] == 'E')
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
	else if (map->f == 0 && splited[0][0] == 'F' && splited[0][1] == '\0')
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
	else
		return (0);
}

static void	get_element(char *line, t_map *map)
{
	char 	**splited;
	int		check;

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
	check = check_element(splited, map);
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
		{
			counter++;
			while (line && !ft_iswhitespacestr(line))
			{
				free(line);
				line = get_next_line(map->fd);
				map->size_map++;
			}
		}
		else if (!ft_iswhitespacestr(line) && counter > 6)
		{
			free(line);
			ft_map_error(map, "Too many elements in the .cub file", 1);
		}
		free(line);
		line = get_next_line(map->fd);
	}
	free(line);
	close(map->fd);
	if (counter < 7)
		ft_map_error(map, "Too many elements in the .cub file", 1);
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
	get_map(map, argv);
	check_map(map);
	printf("Map OK\n");
}


//CHECK_vide
//backtracking map fermee

