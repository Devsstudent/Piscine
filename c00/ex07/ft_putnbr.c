/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odessein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 17:18:50 by odessein          #+#    #+#             */
/*   Updated: 2022/02/09 06:26:20 by odessein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_print_arr(int *arr, int size);

void	ft_convert(int *arr, int size)
{
	int		base[10];
	int		count;
	int		start;
	int		n;

	start = 48;
	n = 0;
	while (start < 58)
	{
		base[n] = start;
		start++;
		n++;
	}
	count = 0;
	while (count < size)
	{
		write(1, &base[*(arr + count)], 1);
		count++;
	}
}

int	ft_size(int nb)
{
	int		size;

	size = 1;
	while (nb >= 10)
	{
		nb /= 10;
		++size;
	}
	return (size);
}

int	*ft_fill_arr(int arr[], int size, int number)
{
	int		buffer_mod;
	int		buffer_loop;
	int		buffer_div;

	buffer_loop = size - 1;
	buffer_mod = number;
	buffer_div = number;
	while (buffer_loop >= 0)
	{
		buffer_mod %= 10;
		buffer_div /= 10;
		arr[buffer_loop] = buffer_mod;
		buffer_mod = buffer_div;
		buffer_loop--;
	}
	return (arr);
}

void	ft_putnbr(int nb)
{
	char	neg_sign;
	int		size;
	int		arr[11];

	neg_sign = '-';
	if (nb == -2147483648)
	{
		write(1, &neg_sign, 1);
		ft_putnbr(21474);
		ft_putnbr(83648);
		return ;
	}
	else
	{
		if (nb < 0)
		{
			write(1, &neg_sign, 1);
			nb = -1 * nb;
		}
		size = ft_size(nb);
		ft_fill_arr(arr, size, nb);
		ft_convert(arr, size);
	}
}
