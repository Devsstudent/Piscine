/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetitpi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 10:45:49 by npetitpi          #+#    #+#             */
/*   Updated: 2022/02/06 15:37:14 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str)
	{
		ft_putchar(*str);
		str += 1;
	}
}

int	ft_atoi_rush(char *str)
{
	int	res;

	res = 0;
	while (*str)
	{
		if (*str < 48 || *str > 57)
			return (-1);
		if (res > 214748364)
			return (-1);
		res = res * 10;
		if (res == 2147483640 && *str - 48 > 7)
			return (-1);
		res = res + (*str - 48);
		str++;
	}
	return (res);
}

void	ft_print_line(char left, char mid, char right, int len)
{
	int	count;

	count = 0;
	while (count < len)
	{
		if (count == 0)
			ft_putchar(left);
		else if (count == len - 1)
			ft_putchar(right);
		else
			ft_putchar(mid);
		++count;
	}
	return ;
}

void	ft_ultimate_rush(int x, int y, char *charset)
{
	int	counter;

	if (x <= 0 || y <= 0)
		return ;
	counter = 0;
	while (counter < y)
	{
		if (counter == 0)
			ft_print_line(charset[0], charset[1], charset[2], x);
		else if (counter == y - 1)
			ft_print_line(charset[6], charset[7], charset[8], x);
		else
			ft_print_line(charset[3], charset[4], charset[5], x);
		ft_putchar('\n');
		++counter;
	}
	return ;
}
