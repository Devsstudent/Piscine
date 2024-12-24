/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odessein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 21:04:01 by odessein          #+#    #+#             */
/*   Updated: 2022/02/16 10:27:30 by odessein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putstr(char *str)
{
	int	brows;

	brows = 0;
	while (str[brows] != '\0')
	{
		write(STDOUT_FILENO, &str[brows], 1);
		++brows;
	}
}
