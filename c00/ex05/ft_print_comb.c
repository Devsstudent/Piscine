/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odessein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 02:22:58 by odessein          #+#    #+#             */
/*   Updated: 2022/02/09 07:32:11 by odessein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putnbr(int nb)
{
	char	c_nb;

	c_nb = ((nb % 10) + '0');
	write(1, &c_nb, 1);
}

void	ft_print(int *arr, int size)
{
	int		brows_arr;
	char	space;
	char	comma;
	int		*buffer_start;

	buffer_start = arr;
	space = ' ';
	comma = ',';
	brows_arr = 0;
	while (brows_arr <= size)
	{
		ft_putnbr(*arr);
		arr = arr + 1;
		brows_arr++;
	}
	if (buffer_start[0] >= (10 - (size + 1)))
		return ;
	write(1, &comma, 1);
	write(1, &space, 1);
}

void	ft_create_arr(int *array, int n)
{
	int	brows_arr;
	int	counter;

	brows_arr = 0;
	while (brows_arr < n)
	{
		array[brows_arr] = brows_arr;
		++brows_arr;
	}
	counter = brows_arr;
	while (counter < 10)
	{
		array[counter] = -1;
		++counter;
	}
}

void	ft_increment(int *arr, int size, int *counter)
{
	int	buffer_size;
	int	brows_op;

	buffer_size = (size - 1);
	while (arr[buffer_size] < 9)
	{
		++arr[buffer_size];
		ft_print(arr, buffer_size);
	}
	brows_op = *counter;
	++arr[buffer_size - brows_op];
	while (brows_op > 0)
	{
		arr[buffer_size - brows_op + 1] = arr[buffer_size - brows_op] + 1;
		--brows_op;
	}
	if (arr[buffer_size] < 10)
		ft_print(arr, buffer_size);
}

void	ft_print_comb(void)
{
	int	arr[10];
	int	counter;
	int	*ptr_counter;
	int	n;

	n = 3;
	ptr_counter = &counter;
	counter = 0;
	if (n < 0 || n > 10)
	{
		return ;
	}
	ft_create_arr(arr, n);
	ft_print(arr, (n - 1));
	while (arr[0] < 10 - n)
	{
		if (arr[n - counter - 1] >= (10 - counter))
			++counter;
		if ((n == 1 && arr[0] >= 9))
		{
			break ;
		}
		ft_increment(arr, n, ptr_counter);
	}
}
