/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odessein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 22:07:22 by odessein          #+#    #+#             */
/*   Updated: 2022/02/14 22:26:06 by odessein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(STDOUT_FILENO, &str[i], 1);
		i++;
	}
}

int	main(int argc, char *argv[])
{
	int	buff;

	buff = argc - 1;
	if (argc != 1)
	{
		while (buff > 0)
		{
			ft_putstr(argv[buff]);
			write(STDOUT_FILENO, "\n", 1);
			buff--;
		}
	}
	return (0);
}
