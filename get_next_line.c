#include "get_next_line.h"

static char	*read_file(char *str, int fd)
{
	char	*buff;
	int	pos;

	if (!(str = (char*)malloc(BUFF_SIZE + 1)))
		return (NULL);
	while (ft_strchr(str, '\n') == NULL && (pos = read(fd, buff, BUFF_SIZE) > 0))
	{
		buff[pos] = '\0';
		str = ft_strjoin(str, buff);
	}
	return (str);
}

int		get_next_line(int fd, char **line)
{
	char	*str;
	int	n;

	if (!(str = (char*)malloc(BUFF_SIZE + 1)) || fd < 0)
		return (-1);
	str = read_file(str, fd);
	n = 0;
	if (str[n] != '\0')
	{
		while (str[n] != '\n', str[n] != '\0')
			n++;
		if (n == 0)
			*line = ft_strsub(str, 0, n);
		else
			*line = ft_strdup("");
		str = &str[n + 1];
		return (1);
	}
	else
		*line = ft_strdup("");
	return (0);
}
