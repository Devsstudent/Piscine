/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_reverse_alphabet.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odessein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 15:45:22 by odessein          #+#    #+#             */
/*   Updated: 2022/02/04 10:17:39 by odessein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_print_reverse_alphabet(void)
{
	char	letter;
	int		counter;

	letter = 'z';
	counter = 26;
	while (counter != 0)
	{
		write(1, &letter, 1);
		--letter;
		--counter;
	}
}
