/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odessein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 11:47:57 by odessein          #+#    #+#             */
/*   Updated: 2022/02/24 11:58:20 by odessein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

void	ft_fill_arr(int	*arr, int size, int min)
{
	int	i;
	int	value_in_range;

	i = 0;
	value_in_range = min;
	while (i < size)
	{
		arr[i] = value_in_range;
		i++;
		value_in_range++;
	}
}

int	ft_ultimate_range(int **range, int min, int max)
{
	int	size;

	size = max - min;
	if (size < 1)
		*range = NULL;
	else
	{
		*range = malloc(size * sizeof(**range));
		if (*range != NULL)
			ft_fill_arr(*range, size, min);
		else
			return (-1);
	}
	return (size);
}
