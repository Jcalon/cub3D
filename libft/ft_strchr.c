/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcalon <jcalon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 15:23:02 by jcalon            #+#    #+#             */
/*   Updated: 2022/07/11 18:51:24 by jcalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	*res;

	i = 0;
	res = NULL;
	while (i < ft_strlen(s))
	{
		if ((unsigned char) s[i] == (unsigned char) c)
		{
			res = (char *)s + i + 1;
			return (res);
		}
		i++;
	}
	return (res);
}
