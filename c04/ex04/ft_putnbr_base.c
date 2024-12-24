/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odessein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 09:51:51 by odessein          #+#    #+#             */
/*   Updated: 2022/02/17 12:40:49 by odessein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	ft_check_string(char *base, char to_find)
{
	while (*base)
	{
		if (to_find == *base)
			return (0);
		++base;
	}
	return (1);
}

int	ft_length_base(char *base)
{
	int		size;

	size = 0;
	while (*base)
	{
		if (*base != '\0' && ft_check_string(base + 1, *base) == 0)
			return (0);
		if (*base == '+' || *base == '-')
			return (0);
		++base;
		++size;
	}
	return (size);
}

void	ft_is_neg(long *nb)
{
	if (*nb < 0)
	{
		write(STDOUT_FILENO, "-", 1);
		*nb *= (long) -1;
	}
}

int	ft_recursive_power(long nb, long power)
{
	if (power < 0)
		return (0);
	else if (power < 1)
		return (1);
	else if (power < 2)
		return (nb * power);
	return (nb * ft_recursive_power(nb, power - 1));
}

void	ft_putnbr_base(int nbr, char *base)
{
	long	size_base;
	long	size_nbr;
	long	buff;
	long	to_print;
	long	long_from_int;

	long_from_int = (long) nbr;
	ft_is_neg(&long_from_int);
	buff = long_from_int;
	size_base = ft_length_base(base);
	size_nbr = 0;
	while (buff > 9)
	{
		buff /= size_base;
		size_nbr++;
	}
	while (size_nbr >= 0)
	{
		buff = long_from_int / ft_recursive_power(size_base, size_nbr);
		to_print = buff;
		write(STDOUT_FILENO, base + to_print, 1);
		long_from_int = long_from_int % ft_recursive_power(size_base, size_nbr);
		size_nbr--;
	}
}
