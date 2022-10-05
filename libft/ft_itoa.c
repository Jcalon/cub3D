/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcalon <jcalon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 15:47:16 by jcalon            #+#    #+#             */
/*   Updated: 2022/05/08 17:54:27 by jcalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	strsize(long int nb)
{
	size_t	count;

	count = 1;
	if (nb < 0)
	{
		count++;
		nb *= -1;
	}
	while (nb >= 10)
	{
		nb /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char		*str;
	int			size;
	long int	nb;

	nb = (long int)n;
	size = strsize(nb);
	str = (char *)malloc(sizeof(char) * (size + 1));
	if (!str)
		return (NULL);
	str[size] = '\0';
	size--;
	if (nb < 0)
		nb *= -1;
	while (size >= 0)
	{
		str[size] = nb % 10 + '0';
		nb /= 10;
		size--;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}
