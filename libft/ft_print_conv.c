/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_conv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcalon <jcalon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 15:18:51 by jcalon            #+#    #+#             */
/*   Updated: 2022/05/26 11:46:56 by jcalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	print_char(t_printf	*tab)
{
	char	c;

	c = va_arg(tab->args, int);
	tab->retv += write(1, &c, 1);
}

void	print_str(t_printf	*tab)
{
	char	*str;

	str = va_arg(tab->args, char *);
	if (str == NULL)
	{
		ft_putstr_fd("(null)", 1);
		tab->retv += 6;
		return ;
	}
	ft_putstr_fd(str, 1);
	tab->retv += ft_strlen(str);
}

void	print_nbr(t_printf	*tab)
{
	int		i;
	char	*str_i;

	i = va_arg(tab->args, int);
	str_i = ft_itoa(i);
	ft_putstr_fd(str_i, 1);
	tab->retv += ft_strlen(str_i);
	free(str_i);
}

void	print_unsigned(t_printf	*tab)
{
	unsigned int	i;
	char			*str_i;

	i = va_arg(tab->args, unsigned int);
	str_i = ft_utoa(i);
	ft_putstr_fd(str_i, 1);
	tab->retv += ft_strlen(str_i);
	free(str_i);
}
