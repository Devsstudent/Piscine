/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odessein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 19:21:10 by odessein          #+#    #+#             */
/*   Updated: 2022/02/22 19:42:08 by odessein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

char	**ft_fill_map(int fd, int line_nb, int line_len);
void	ft_fill_args(int fd, char *args);
int		ft_check_map(char *f_name, char *args, int size);
int		ft_recursive_power(int nb, int power);
void	ft_print(char **map);
int		ft_rev_int(int to_rev);
int		ft_line(int fd, char *arguments, int *size);
int		ft_check(char *args, int size, int *line);

int	ft_read(char *filename, char **arguments, char ***map)
{
	int		size_line;
	int		size_firstline;
	int		fd;
	int		line_nb;

	fd = open(filename, O_RDONLY);
	size_firstline = ft_line(fd, *arguments, &size_line);
	if (!size_firstline)
		return (0);
	*arguments = malloc(sizeof(**arguments) * size_firstline);
	close(fd);
	fd = open(filename, O_RDONLY);
	ft_fill_args(fd, *arguments);
	if (!ft_check(*arguments, size_firstline, &line_nb))
	{
		free(arguments);
		return (0);
	}
	line_nb = ft_rev_int(line_nb);
	if (!ft_check_map(filename, *arguments, size_firstline))
		return (0);
	*map = ft_fill_map(fd, line_nb, size_line);
	ft_print(*map);
	return (0);
}

void	ft_fill_args(int fd, char *args)
{
	char	buf;
	int		i;

	i = 0;
	while (read(fd, &buf, 1))
	{
		if (buf == '\n')
			break ;
		args[i] = buf;
		i++;
	}
	args[i] = '\0';
}

char	**ft_fill_map(int fd, int line_nb, int line_len)
{
	int		i;
	int		j;
	char	buf;
	char	**map;

	i = 0;
	j = 0;
	map = malloc(sizeof(char *) * line_nb + 1);
	map[line_nb] = 0;
	while (read(fd, &buf, 1))
	{
		*(map + i) = malloc(sizeof(**map) * line_len);
		if (j == (line_len - 1))
		{
			map[i][j] = '\0';
			i++;
			j = 0;
			continue ;
		}
		map[i][j] = buf;
//		printf("%c", map[i][j]);
		j++;
	}
	return (map);
}

int	ft_check_map(char *f_name, char *args, int size)
{
	int		fd;
	char	buf;
	int		j;
	int		i;

	size = size - 1;
	i = 0;
	j = size;
	fd = open(f_name, O_RDONLY);
	while (read(fd, &buf, 1))
	{
		if (buf == '\n')
			i++;
		j = 0;
		while (j >= size - 2)
		{
			if (args[j] != buf && i != 0)
				return (0);
		}
	}
	return (1);
}

void	ft_print_error(void)
{
	write(STDERR_FILENO, "Error\n", 6);
}
