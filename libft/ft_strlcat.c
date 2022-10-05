/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcalon <jcalon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 15:28:51 by jcalon            #+#    #+#             */
/*   Updated: 2022/05/05 11:53:56 by jcalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = ft_strlen(dest);
	j = ft_strlen(src);
	if (!size)
		return (j);
	if (size < i)
		j += size;
	else
		j += i;
	k = 0;
	while (src[k] != '\0' && (i + k) < (size - 1))
	{
		dest[i + k] = src[k];
		k++;
	}
	dest[i + k] = '\0';
	return (j);
}
