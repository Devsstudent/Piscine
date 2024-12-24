/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odessein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 13:09:24 by odessein          #+#    #+#             */
/*   Updated: 2022/02/17 13:09:25 by odessein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int n)
{
	char	to_int;

	if (n == -2147483648)
	{
		ft_putnbr(-214748);
		ft_putnbr(3648);
		return ;
	}
	if (n < 0)
	{
		write(STDOUT_FILENO, "-", 1);
		n = n * -1;
	}
	if (n <= 9)
	{
		to_int = 48 + (n % 10);
		write(STDOUT_FILENO, &to_int, 1);
		return ;
	}
	else
		ft_putnbr(n / 10);
	to_int = 48 + (n % 10);
	write(STDOUT_FILENO, &to_int, 1);
}
