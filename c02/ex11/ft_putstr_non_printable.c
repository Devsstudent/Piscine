/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odessein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 05:52:24 by odessein          #+#    #+#             */
/*   Updated: 2022/02/09 05:53:28 by odessein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_print_hex(unsigned char unprintable)
{
	char			back_slash;
	char			*base_hex;
	unsigned int	char_to_int;

	base_hex = "0123456789abcdef";
	back_slash = '\\';
	char_to_int = (unsigned int) unprintable;
	write(STDOUT_FILENO, &back_slash, 1);
	write(STDOUT_FILENO, (base_hex + (char_to_int / 16)), 1);
	write(STDOUT_FILENO, (base_hex + (char_to_int % 16)), 1);
}

void	ft_putstr_non_printable(char *str)
{
	while (*str)
	{
		if (*str < 32 || *str > 126)
			ft_print_hex((unsigned char) *str);
		else
			write(STDOUT_FILENO, str, 1);
		++str;
	}
}
