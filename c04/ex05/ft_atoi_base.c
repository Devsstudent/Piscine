/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odessein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 09:59:52 by odessein          #+#    #+#             */
/*   Updated: 2022/02/17 21:15:41 by odessein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
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

char	*ft_check(char *str, int *neg_sign, int *counter, char *base)
{
	char	*res;
	int		i;	

	*neg_sign = 1;
	i = 0;
	while (*str == ' ' || (*str > 8 && *str < 14))
		++str;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			*neg_sign *= -1;
		++str;
	}
	res = str;
	while (res[i] != '\0')
	{
		if (ft_check_string(base, res[i]) == 0)
			*counter += 1;
		else
			break ;
		i++;
	}	
	return (str);
}

int	ft_check_str(char *str, char *base)
{
	int	count;

	count = 0;
	while (base[count] != '\0')
	{
		if (ft_check_string(&base[count + 1], base[count]) == 0)
			return (-1);
		if (base[count] == '+' || base[count] == '-' || base[count] == ' ')
		{
			if (base[count] < 14 && base[count] > 8)
				return (-1);
			return (-1);
		}
		if (*str == base[count])
		{
			return (count);
		}
		count++;
	}
	return (-1);
}

int	ft_power(int nb, int power)
{
	if (power < 0)
		return (0);
	else if (power < 1)
		return (1);
	else if (power < 2)
		return (nb * power);
	return (nb * ft_power(nb, power - 1));
}

int	ft_atoi_base(char *str, char *base)
{
	int	number;
	int	counter;
	int	neg_sign;
	int	size;
	int	buff_next;

	size = 0;
	counter = 0;
	number = 0;
	while (base[size] != '\0')
		size++;
	if (size <= 1)
		return (0);
	str = ft_check(str, &neg_sign, &counter, base);
	counter = counter - 1;
	while (*str)
	{
		buff_next = ft_check_str(str, base);
		if (buff_next < 0)
			return (neg_sign * number);
		number += buff_next * ft_power(size, counter);
		str++;
		counter--;
	}
	return (neg_sign * number);
}
#include <stdio.h>
int main(void)
{
	printf("%d", ft_atoi_base("     ---++-118","1686"));
	return(0);
}
