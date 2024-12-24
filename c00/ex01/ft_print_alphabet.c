/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odessein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 15:34:37 by odessein          #+#    #+#             */
/*   Updated: 2022/02/04 10:17:05 by odessein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_alphabet(void)
{
	char	letter;
	int		count;

	count = 0;
	letter = 'a';
	while (count != 26)
	{
		write(1, &letter, 1);
		++count;
		++letter;
	}
}
