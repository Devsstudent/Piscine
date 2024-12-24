/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odessein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 13:19:48 by odessein          #+#    #+#             */
/*   Updated: 2022/02/24 16:35:46 by odessein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include "ft_stock_str.h"

void	ft_putstr(char *str)
{
	while (*str)
	{
		write(STDOUT_FILENO, str, 1);
		str++;
	}
	write(STDOUT_FILENO, "\n", 1);
}

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

void	ft_show_tab(struct s_stock_str *par)
{
	int	i;

	i = 0;
	if (!par)
		return ;
	while (par[i].str != 0)
	{
		ft_putstr(par[i].str);
		ft_putnbr(par[i].size);
		write(STDOUT_FILENO, "\n", 1);
		ft_putstr(par[i].copy);
		i++;
	}
}
