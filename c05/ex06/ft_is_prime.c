/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odessein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 11:14:47 by odessein          #+#    #+#             */
/*   Updated: 2022/02/18 09:48:23 by odessein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_round_sqrt(int nb)
{
	int		i;

	if (nb == 1)
		return (1);
	i = 2;
	while (i * i <= nb && i <= 46340)
	{
		if (i * i == nb)
			return (i);
		i += 1;
	}
	if (i * i > nb)
		return (i - 1);
	return (i);
}

int	ft_is_prime(int nb)
{
	int	sqrt_nb;
	int	start;

	if (nb <= 1)
		return (0);
	else if (nb == 2 || nb == 3)
		return (1);
	start = 2;
	sqrt_nb = ft_round_sqrt(nb);
	while (start <= sqrt_nb)
	{
		if (nb % start == 0)
			return (0);
		start += 1;
	}
	return (1);
}
