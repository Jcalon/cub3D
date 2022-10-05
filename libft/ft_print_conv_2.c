/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_conv_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcalon <jcalon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 15:21:04 by jcalon            #+#    #+#             */
/*   Updated: 2022/05/26 11:46:50 by jcalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	custom_putnbr_base(unsigned long nbr, char *base)
{
	unsigned long		lenbase;
	unsigned long		nb;
	char				*str;
	int					len;
	int					i;

	i = 1;
	lenbase = ft_strlen(base);
	nb = nbr;
	while (nb >= lenbase)
	{
		nb /= lenbase;
		i++;
	}
	len = i;
	str = (char *)ft_calloc(sizeof(char), i + 1);
	str[i] = '\0';
	while (i > 0)
	{
		str[--i] = base[nbr % 16];
		nbr /= lenbase;
	}
	ft_putstr_fd(str, 1);
	free(str);
	return (len);
}

void	print_ptr(t_printf	*tab)
{
	unsigned long	i;
	int				len;

	len = 0;
	i = (unsigned long)va_arg(tab->args, void *);
	if (i == 0)
	{
		ft_putstr_fd("(nil)", 1);
		tab->retv += 5;
		return ;
	}
	ft_putstr_fd("0x", 1);
	tab->retv += 2;
	len = custom_putnbr_base(i, "0123456789abcdef");
	tab->retv += len;
}

void	print_hexa(t_printf	*tab, char c)
{
	unsigned int	i;
	int				len;

	len = 0;
	i = va_arg(tab->args, unsigned int);
	if (c == 'x')
		len = custom_putnbr_base(i, "0123456789abcdef");
	else
		len = custom_putnbr_base(i, "0123456789ABCDEF");
	tab->retv += len;
}
