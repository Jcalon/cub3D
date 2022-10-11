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