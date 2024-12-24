/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odessein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 13:17:54 by odessein          #+#    #+#             */
/*   Updated: 2022/02/17 22:07:13 by odessein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_iterative_factorial(int nb)
{
	int	count;

	if (nb < 0)
		return (0);
	if (nb == 0)
		return (1);
	count = nb - 1;
	while (count > 0)
	{
		nb = nb * count;
		count--;
	}
	return (nb);
}
