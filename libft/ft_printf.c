/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcalon <jcalon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 10:38:58 by jcalon            #+#    #+#             */
/*   Updated: 2022/05/26 11:47:00 by jcalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	check_format(t_printf *tab, const char *to_print, int i)
{
	if (to_print[i] == 'c')
		print_char(tab);
	else if (to_print[i] == 's')
		print_str(tab);
	else if (to_print[i] == 'p')
		print_ptr(tab);
	else if (to_print[i] == 'd' || to_print[i] == 'i')
		print_nbr(tab);
	else if (to_print[i] == 'u')
		print_unsigned(tab);
	else if (to_print[i] == 'x' || to_print[i] == 'X')
		print_hexa(tab, to_print[i]);
	else if (to_print[i] == '%')
	{
		write(1, "%", 1);
		tab->retv += 1;
	}
	else
		write(1, &to_print[i], 1);
	return (i);
}

int	ft_printf(const char *to_print, ...)
{
	t_printf	*tab;
	int			i;
	int			ret;

	tab = malloc(sizeof(t_printf));
	if (!tab)
		return (0);
	tab->retv = 0;
	va_start(tab->args, to_print);
	i = 0;
	ret = 0;
	while (to_print[i])
	{
		if (to_print[i] == '%')
			i = check_format(tab, to_print, i + 1);
		else
			ret += write(1, &to_print[i], 1);
		i++;
	}
	va_end(tab->args);
	ret += tab->retv;
	free(tab);
	return (ret);
}
