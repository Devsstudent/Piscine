/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odessein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 21:59:40 by odessein          #+#    #+#             */
/*   Updated: 2022/02/18 21:31:01 by odessein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	main(int argc, char *argv[])
{
	int	i;

	(void) argc;
	i = 0;
	while (argv[0][i] != '\0')
	{
		write(STDOUT_FILENO, &argv[0][i], 1);
		i++;
	}
	write(STDOUT_FILENO, "\n", 1);
	return (0);
}
