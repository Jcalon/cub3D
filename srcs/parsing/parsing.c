/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crazyd <crazyd@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 23:50:23 by crazyd            #+#    #+#             */
/*   Updated: 2022/10/05 05:14:29 by crazyd           ###   ########.fr       */
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
