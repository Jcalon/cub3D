/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcalon <jcalon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 10:56:35 by jcalon            #+#    #+#             */
/*   Updated: 2022/05/30 13:29:15 by jcalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strsearch(char *s, char c)
{
	size_t	i;

	i = 0;
	while (c != s[i] && i < ft_strlen(s))
		i++;
	return (i);
}

static char	*save_more(char *tmp, char *buffer)
{
	char	*newtmp;

	newtmp = ft_strjoin(tmp, buffer);
	free(tmp);
	return (newtmp);
}

static char	*make_line(char *save, char *tmp, char *buffer)
{
	size_t	i;
	char	*line;
	char	*strtmp;

	i = ft_strsearch(tmp, '\n');
	strtmp = ft_substr(tmp, 0, i + 1);
	if (!strtmp)
	{
		free (tmp);
		free (buffer);
		return (NULL);
	}
	line = ft_strjoin(save, strtmp);
	free(strtmp);
	ft_strcpy(ft_strchr(buffer, '\n'), save);
	free (tmp);
	free (buffer);
	return (line);
}

static char	*get_line(char *save, char *buffer, char *tmp, int fd)
{
	int		rbytes;

	rbytes = read(fd, buffer, BUFFER_SIZE);
	if (save[0] == '\0' && rbytes <= 0)
	{
		free (tmp);
		free (buffer);
		return (NULL);
	}
	buffer[rbytes] = '\0';
	while ((rbytes > 0) && (ft_strsearch(buffer, '\n') == ft_strlen(buffer)))
	{
		tmp = save_more(tmp, buffer);
		rbytes = read(fd, buffer, BUFFER_SIZE);
		if (rbytes < 0)
		{
			free (tmp);
			free (buffer);
			return (NULL);
		}
		buffer[rbytes] = '\0';
	}
	tmp = save_more(tmp, buffer);
	return (make_line(save, tmp, buffer));
}

char	*get_next_line(int fd)
{
	static char	save[FOPEN_MAX][BUFFER_SIZE + 1];
	char		*line;
	char		*buffer;
	char		*tmp;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	if ((ft_strsearch(save[fd], '\n') != ft_strlen(save[fd])))
	{
		line = ft_substr(save[fd], 0, ft_strsearch(save[fd], '\n') + 1);
		ft_strcpy(ft_strchr(save[fd], '\n'), save[fd]);
		return (line);
	}
	tmp = malloc(sizeof(char));
	if (!tmp)
		return (NULL);
	tmp[0] = '\0';
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
	{
		free(tmp);
		return (NULL);
	}
	line = get_line(save[fd], buffer, tmp, fd);
	return (line);
}
