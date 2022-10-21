/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crazyd <crazyd@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 21:59:12 by crazyd            #+#    #+#             */
/*   Updated: 2022/10/21 21:59:32 by crazyd           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	clean_map(t_map *map)
{
	if (map->no)
		free(map->no);
	if (map->so)
		free(map->so);
	if (map->we)
		free(map->we);
	if (map->ea)
		free(map->ea);
	if (map->map)
		ft_free_array(map->map);
}

int	ft_end(t_cub *data)
{
	clean_map(&data->map);
	mlx_destroy_image(data->mlx, data->screen.img);
	mlx_destroy_image(data->mlx, data->north.img);
	mlx_destroy_image(data->mlx, data->south.img);
	mlx_destroy_image(data->mlx, data->east.img);
	mlx_destroy_image(data->mlx, data->west.img);
	mlx_clear_window(data->mlx, data->win);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(EXIT_SUCCESS);
	return (1);
}

int	errmsg(char *str, int code)
{
	ft_putendl_fd("Error", 2);
	ft_putstr_fd("Cub3D: ", 2);
	ft_putendl_fd(str, 2);
	return (code);
}

void	ft_map_error(t_map *map, char *str, int code)
{
	ft_putendl_fd("Error", 2);
	ft_putstr_fd("While parsing the .cub file we found: ", 2);
	ft_putendl_fd(str, 2);
	clean_map(map);
	exit(code);
}
