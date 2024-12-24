/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odessein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 10:37:13 by odessein          #+#    #+#             */
/*   Updated: 2022/02/06 17:40:52 by odessein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	buffer_div;
	int	buffer_mod;

	buffer_div = *a / *b;
	buffer_mod = *a % *b;
	*a = buffer_div;
	*b = buffer_mod;
}
