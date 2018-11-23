/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asicat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 09:56:45 by asicat            #+#    #+#             */
/*   Updated: 2018/11/23 16:31:42 by asicat           ###   ########.fr       */
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

	if (!(buff = (char*)malloc(BUFF_SIZE + 1)))
		return (NULL);
	while (check_line(str) == 0 && (pos = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[pos] = '\0';
		str = ft_strjoin(str, buff);
	}
	free(buff);
	return (str);
}

int			get_next_line(int fd, char **line)
{
	int			n;
	static char *str[1024];

	if (fd < 0 || line == NULL || read(fd, str, 0) < 0)
		return (-1);
	if (str[fd] == NULL && !(str[fd] = ft_strnew(0)))
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
		if (str[fd][n] == '\n')
			str[fd] = &str[fd][n + 1];
		else
			str[fd] = ft_strdup("");
		return (1);
	}
	*line = ft_strdup("");
	return (0);
}
