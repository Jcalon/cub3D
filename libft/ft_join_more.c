/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_join_more.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcalon <jcalon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 16:37:11 by jcalon            #+#    #+#             */
/*   Updated: 2022/07/07 16:38:40 by jcalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_join_more(char **str, char *new_value)
{
	char	*tmp;

	tmp = ft_strjoin(*str, new_value);
	free(*str);
	*str = tmp;
}
