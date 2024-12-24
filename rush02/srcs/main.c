/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmathie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 20:31:26 by thmathie          #+#    #+#             */
/*   Updated: 2022/02/20 22:15:37 by odessein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "../includes/struct.h"
#include "../includes/head.h"
#define BUF_SIZE 4096

int	main(int ac, char **av)
{
	int		fd;
	int		ret;
	char	buf[BUF_SIZE];
	char	*filename;
	t_dict	*tab;

	if (ac > 3 || ac < 2)
	{
		write(STDERR_FILENO, "Error", 5);
		return (1);
	}
	else if (ac > 3)
		filename = av[2];
	else
		filename = "numbers.dict";
	fd = open(filename, O_RDONLY);
	ret = read(fd, buf, BUF_SIZE);
	tab = split_dict(buf);
	buf[ret] = '\0';
	print(tab, av[1], 0);
	free(tab);
	return (0);
}
