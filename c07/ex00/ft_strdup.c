/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odessein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 10:53:28 by odessein          #+#    #+#             */
/*   Updated: 2022/02/23 18:10:22 by odessein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

char	*ft_strdup(char *src)
{
	char	*res;
	int		i;

	i = 0;
	while (src[i] != '\0')
		i++;
	res = malloc(sizeof(*res) * (i + 1));
	i = 0;
	if (!res)
	{
		while (src[i] != '\0')
		{
			res[i] = src[i];
			i++;
		}
		res[i] = src[i];
	}
	return (res);
}
