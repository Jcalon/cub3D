/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crazyd <crazyd@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 20:45:23 by crazyd            #+#    #+#             */
/*   Updated: 2022/10/21 21:15:10 by crazyd           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

bool	check_extension(char *filename)
{
	if (ft_strlen(filename) > 4
		&& !ft_strcmp(filename + ft_strlen(filename) - 4, ".cub"))
		return (true);
	return (false);
}

bool	ft_isinstr(char c, char *str)
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
