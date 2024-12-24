/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odessein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 11:31:51 by odessein          #+#    #+#             */
/*   Updated: 2022/02/23 18:25:01 by odessein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

void	ft_fill_arr(int *arr, int size, int min)
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

int	*ft_range(int min, int max)
{
	int	*arr;
	int	size;

	size = max - min;
	if (size >= 1)
	{
		arr = malloc(size * sizeof(arr));
		if (arr != NULL)
			ft_fill_arr(arr, size, min);
		return (arr);
	}
	return (0);
}
