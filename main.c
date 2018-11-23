/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asicat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 11:32:14 by asicat            #+#    #+#             */
/*   Updated: 2018/11/23 15:22:36 by asicat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int		main(int ac, char **av)
{
	int		n;
	int		fd;
	char	**line;

	n = 66;
	if (!(line = (char**)malloc(sizeof(char*) * 50)))
		return (0);
	fd = open(av[1], O_RDONLY);
	while (get_next_line(fd, line))
		printf("%s\n", *line);
}
