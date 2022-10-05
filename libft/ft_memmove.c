/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcalon <jcalon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 15:16:18 by jcalon            #+#    #+#             */
/*   Updated: 2022/05/04 09:42:47 by jcalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*tmpdest;
	unsigned char	*tmpsrc;

	tmpdest = (unsigned char *)dest;
	tmpsrc = (unsigned char *)src;
	if (dest == src)
		return (dest);
	if (tmpdest > tmpsrc)
		while (n--)
			tmpdest[n] = tmpsrc[n];
	else
		while (n--)
			*tmpdest++ = *tmpsrc++;
	return (dest);
}
