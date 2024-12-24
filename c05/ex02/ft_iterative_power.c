/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odessein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 16:13:29 by odessein          #+#    #+#             */
/*   Updated: 2022/02/17 22:02:17 by odessein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_iterative_power(int nb, int power)
{
	int	buff;

	buff = nb;
	if (power < 0)
		return (0);
	else if (power < 1)
		return (1);
	while (power > 1)
	{
		nb = buff * nb;
		power--;
	}	
	return (nb);
}
