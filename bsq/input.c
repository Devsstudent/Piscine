/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odessein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 17:12:59 by odessein          #+#    #+#             */
/*   Updated: 2022/02/22 11:35:01 by odessein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int		ft_recursive_power(int nb, int power);
int		ft_rev_int(int to_rev);
int		ft_line(int fd, char *arguments, int *size);
int		ft_check(char *args, int size, int *line);

int	ft_rev_int(int to_rev)
{
	int	size;
	int	nb;
	int	res;
	int	res_r;

	nb = to_rev;
	size = 0;
	res_r = 0;
	while (nb > 9)
	{
		nb = nb / 10;
		size++;
	}
	while (size >= 0)
	{
		res = to_rev % 10;
		res = res * ft_recursive_power(10, size);
		res_r += res;
		to_rev = to_rev / 10;
		size--;
	}
	return (res_r);
}

int	ft_check_occu(char *args, int size)
{
	int	i;
	int	j;

	size = size - 1;
	i = size;
	j = size;
	while (i >= size - 2)
	{
		while (j >= size - 2)
		{
//			printf("%c\n", args[j]);
			if (args[j] == args[i] && i != j)
				return (0);
			j--;
		}
		i--;
	}
	return (1);
}

int	ft_check(char *args, int size, int *line)
{
	int	buff;
	int	len;

	if (!ft_check_occu(args, size))
		return (0);
	size = size - 1;
	len = 0;
	buff = size - 1;
	*line = 0;
	while (size >= 0)
	{
		if ((args[size] > 32 && args[size] < 127) && size > (buff - 2))
			size--;
		else if ((args[size] < 58 && args[size] > 47) && size <= (buff - 2))
		{
			*line = *line * 10;
			*line = *line + (args[size] - 48);
			size--;
		}
		else
			return (0);
	}
	return (1);
	//ispace or not ? 
}

int	ft_recursive_power(int nb, int power)
{
	if (power < 0)
		return (0);
	else if (power < 1)
		return (1);
	else if (power < 2)
		return (nb);
	return (nb * ft_recursive_power(nb, power - 1));
}

int	ft_line(int fd, char *arguments, int *size)
{
	int		j;
	int		i;
	int		len;
	char	buf;

	*size = 0;
	len = 0;
	i = 0;
	j = 0;
	while (read(fd, &buf, 1) && buf != '\n')
		i++;
	while (read(fd, &buf, 1))
	{
		len++;
		if (buf == '\n')
		{
			if (len != *size && j > len)
				return (0);
			*size = len;
			len = 0;
		}
		j++;
	}
	return (i);
}
