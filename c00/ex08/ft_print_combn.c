/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odessein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 03:36:24 by odessein          #+#    #+#             */
/*   Updated: 2022/02/14 21:15:20 by odessein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdio.h>

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
	printf("%i ", brows_op);;
	++arr[buffer_size - brows_op];
	while (brows_op > 0)
	{
		arr[buffer_size - brows_op + 1] = arr[buffer_size - brows_op] + 1;
		--brows_op;
	}
	*counter--;
	if (arr[buffer_size] < 10)
		ft_print(arr, buffer_size);
}

void	ft_print_combn(int n)
{
	int	arr[10];
	int	counter;
	int	*ptr_counter;

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
		if (arr[n - counter - 1]>= (10 - counter))
		{
	//		printf("%i", arr[n - counter - 1]);
			++counter;
		}
		if ((n == 1 && arr[0] >= 9))
		{
			break ;
		}
		ft_increment(arr, n, ptr_counter);
		write(1, "\n", 1);
	}
}

int	main(void)
{
	ft_print_combn(3);
	return (0);
}
