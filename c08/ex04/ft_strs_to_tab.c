/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odessein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 13:25:37 by odessein          #+#    #+#             */
/*   Updated: 2022/02/24 18:08:25 by odessein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <unistd.h>
#include "ft_stock_str.h"

char	*ft_strcpy(char *dest, char *src)
{
	char	*start_dest;

	start_dest = dest;
	while (*src != '\0')
	{
		*dest = *src;
		++src;
		++dest;
	}
	*dest = *src;
	return (start_dest);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (*str)
	{
		i++;
		str++;
	}
	return (i);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int			i;
	int			size;
	t_stock_str	*res;

	i = 0;
	res = malloc(sizeof(t_stock_str) *(ac + 1));
	if (!res || !av)
		return (0);
	i = 0;
	while (av[i] != NULL && i < ac)
	{
		size = ft_strlen(av[i]);
		res[i].size = size;
		res[i].str = &av[i][0];
		res[i].copy = malloc(sizeof(char) * (size + 1));
		if (res[i].copy != 0)
			ft_strcpy(res[i].copy, av[i]);
		i++;
	}
	res[i].str = 0;
	return (res);
}
