/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcalon <jcalon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 15:21:04 by jcalon            #+#    #+#             */
/*   Updated: 2022/05/04 09:49:07 by jcalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	nbr;

	nbr = n;
	if (nbr < 0)
	{
		nbr = -nbr;
		write(fd, "-", 1);
	}	
	if (nbr >= 10)
	{
		ft_putnbr_fd(nbr / 10, fd);
	}	
	nbr = nbr % 10 + '0';
	write(fd, &nbr, 1);
}
