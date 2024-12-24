/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odessein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 12:14:56 by odessein          #+#    #+#             */
/*   Updated: 2022/02/24 12:19:25 by odessein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	long	ft_power(int long nb, int long power);
void	ft_fill(char *final_nbr, long int value, int size_base, char *base);
int		ft_size_value_base(long int value, int size_base);
int		ft_strlen(char *str);
int		ft_size(long int value);

long int	ft_convert_from(char *str, char *base)
{
	int			size_base;
	int			size_num;
	long int	result;
	int			count;

	result = 0;
	size_base = ft_strlen(base);
	size_num = ft_strlen(str);
	while (*str)
	{
		count = 0;
		while (base[count])
		{
			if (base[count] == *str)
			{
				result += count * ft_power(size_base, (size_num - 1));
				break ;
			}
			count++;
		}
		str++;
		size_num--;
	}
	return (result);
}

void	ft_to(long int value, char *base, char **final_nbr, int *neg_sign)
{
	int	size_val_base;
	int	size_base;

	size_base = ft_strlen(base);
	size_val_base = ft_size_value_base(value, size_base);
	if (*neg_sign < 0)
	{
		*final_nbr = malloc(sizeof(**final_nbr) * (size_val_base + 2));
		if (!(*final_nbr))
		{
			*final_nbr = NULL;
			return ;
		}
		(*final_nbr)[0] = '-';
	}
	else
	{
		*final_nbr = malloc(sizeof(**final_nbr) * (size_val_base + 1));
		if (!(*final_nbr))
		{
			*final_nbr = NULL;
			return ;
		}
	}	
	ft_fill(*final_nbr, value, size_base, base);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_size_value_base(long int value, int size_base)
{
	int	size;

	size = 1;
	while (value > size_base)
	{
		value = value / size_base;
		size++;
	}
	return (size);
}

int	long	ft_power(int long nb, int long power)
{
	if (power < 0)
		return (0);
	else if (power < 1)
		return (1);
	else if (power < 2)
		return (nb * power);
	return (nb * ft_power(nb, power - 1));
}
