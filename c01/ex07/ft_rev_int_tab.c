/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odessein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 12:03:10 by odessein          #+#    #+#             */
/*   Updated: 2022/02/08 20:46:05 by odessein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int	*array, int size)
{
	int	middle;
	int	buffer;
	int	counter;

	counter = 0;
	middle = size / 2;
	size = size - 1;
	while (counter < middle)
	{
		buffer = array[counter];
		array[counter] = array[size];
		array[size] = buffer;
		--size;
		counter += 1;
	}
}
