/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npetitpi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 12:36:55 by npetitpi          #+#    #+#             */
/*   Updated: 2022/02/06 15:14:56 by nmathieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	rush(int x, int y);
int		ft_atoi_rush(char *str);
void	ft_putstr(char *str);

int	main(int argc, char *argv[])
{
	int	x;
	int	y;

	if (argc <= 1)
		rush(5, 8);
	else if (argc == 2)
		ft_putstr("wesh faut 2 arguments >:(\n");
	else if (argc == 3)
	{
		x = ft_atoi_rush(argv[1]);
		y = ft_atoi_rush(argv[2]);
		if (x < 0 || y < 0)
			ft_putstr("met un nombre valide stp");
		else
			rush(x, y);
	}
	else
		ft_putstr("t'as mis trop d'arguments bg\n");
	return (0);
}
