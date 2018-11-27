/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asicat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 09:56:45 by asicat            #+#    #+#             */
/*   Updated: 2018/11/27 10:34:05 by asicat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	check_line(char *str)
{
	int		n;

	n = 0;
	if (str == NULL)
		return (0);
	while (str[n] != '\n' && str[n] != '\0')
		n++;
	if (str[n] == '\n')
		return (n);
	return (0);
}

static char	*read_file(char *str, int fd)
{
	int		pos;
	char	*buff;
	char	*tmp;

	if (!(buff = (char*)malloc(BUFF_SIZE + 1)))
		return (NULL);
	while (check_line(str) == 0 && (pos = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[pos] = '\0';
		tmp = str;
		if (!(str = ft_strjoin(str, buff)))
			return (NULL);
		free(tmp);
	}
	free(buff);
	return (str);
}

int			get_next_line(int fd, char **line)
{
	int			n;
	char		*tmp;
	static char *str[1024];

	if (fd < 0 || line == NULL || read(fd, str, 0) < 0
			|| (str[fd] == NULL && !(str[fd] = ft_strnew(0))))
		return (-1);
	str[fd] = read_file(str[fd], fd);
	if (str[fd][0] != '\0' && !(n = 0))
	{
		while (str[fd][n] != '\n' && str[fd][n] != '\0')
			n++;
		if (n == 0)
			*line = ft_strdup("");
		else
			*line = ft_strsub(str[fd], 0, n);
		tmp = str[fd];
		if (str[fd][n] == '\n' && (str[fd] = ft_strdup(&str[fd][n + 1])))
			free(tmp);
		else if (!(str[fd] = NULL))
			free(str[fd]);
		return (1);
	}
	*line = ft_strdup("");
	return (0);
}
