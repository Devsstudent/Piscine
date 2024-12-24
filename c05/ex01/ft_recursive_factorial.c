/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odessein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 15:33:20 by odessein          #+#    #+#             */
/*   Updated: 2022/02/17 22:15:50 by odessein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_recursive_factorial(int nb)
{
	if (nb == 0)
		return (1);
	else if (nb < 1)
		return (0);
	else if (nb < 2)
		return (nb);
	return (nb * ft_recursive_factorial(nb - 1));
}
