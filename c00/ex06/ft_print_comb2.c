/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odessein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 12:03:35 by odessein          #+#    #+#             */
/*   Updated: 2022/02/09 00:53:35 by odessein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print(char first, char second, char third, char fourth)
{
	char	space;
	char	comma;

	space = ' ';
	comma = ',';
	ft_putchar(first);
	ft_putchar(second);
	ft_putchar(space);
	ft_putchar(third);
	ft_putchar(fourth);
	if (first == 57 && second == 56)
		return ;
	ft_putchar(comma);
	ft_putchar(space);
}

void	ft_incr_to_pos_1_2(char *first, char *second, char *third, char *fourth)
{
	if (*third == 57 && *fourth == 57)
	{
		++*second;
		if (*second > 57)
		{
			++*first;
			*second = 48;
		}
		*third = *first;
		*fourth = *second + 1;
	}	
}

void	ft_print_comb2(void)
{
	char	first;
	char	second;
	char	third;
	char	fourth;

	first = 48;
	second = 48;
	third = 48;
	fourth = 49;
	while (third <= 57 && fourth <= 57)
	{
		ft_print(first, second, third, fourth);
		if (first == 57 && second == 56)
			return ;
		if (third == 57 && fourth == 57)
			ft_incr_to_pos_1_2(&first, &second, &third, &fourth);
		else
			fourth++;
		if (fourth > 57)
		{
			third++;
			fourth = 48;
		}
	}	
}
