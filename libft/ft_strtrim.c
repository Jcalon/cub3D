/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcalon <jcalon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 15:42:28 by jcalon            #+#    #+#             */
/*   Updated: 2022/05/05 13:43:11 by jcalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	test_char(char const c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

static size_t	counter(char const *s1, char const *set)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (s1[i] != '\0' && test_char(s1[i], set))
	{
		count++;
		i++;
	}
	if (s1[count] == '\0')
		return (count);
	while (s1[i] != '\0')
		i++;
	i--;
	while (s1[i] != '\0' && test_char(s1[i], set))
	{
		count++;
		i--;
	}
	return (count);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	char	*s2;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	s2 = (char *)malloc(sizeof(char) * (ft_strlen(s1) - counter(s1, set) + 1));
	if (!s2)
		return (NULL);
	s2[ft_strlen(s1) - counter(s1, set)] = '\0';
	i = 0;
	j = 0;
	while (s1[i] != '\0' && test_char(s1[i], set))
		i++;
	while (j < ft_strlen(s1) - counter(s1, set))
	{
		s2[j] = s1[i];
		j++;
		i++;
	}
	return (s2);
}
