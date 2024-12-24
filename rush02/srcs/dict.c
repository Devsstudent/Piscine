/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmathie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 20:21:00 by thmathie          #+#    #+#             */
/*   Updated: 2022/02/20 20:26:32 by thmathie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/struct.h"
#include "../includes/head.h"

char	*grabnbr(char *file, int i)
{
	int		size;
	int		j;
	char	*ret;

	size = 0;
	j = 0;
	while (file[i] < '0' || file[i] > '9')
		i++;
	while (file[i] >= '0' && file[i] <= '9')
	{
		i++;
		size++;
	}
	ret = malloc(sizeof(char) * size + 1);
	i = i - size;
	while (file[i] >= '0' && file[i] <= '9')
	{
		ret[j] = file[i];
		j++;
		i++;
	}
	ret[size] = '\0';
	return (ret);
}

char	*grabvalue(char *file, int i)
{
	int		size;
	int		j;
	char	*ret;

	j = 0;
	size = 0;
	while (file[i] < 'a' || file[i] > 'z')
		i++;
	while (file[i] >= 'a' && file[i] <= 'z')
	{
		i++;
		size++;
	}
	ret = malloc(sizeof(char) * size + 1);
	i = i - size;
	while (file[i] >= 'a' && file[i] <= 'z')
	{
		ret[j] = file[i];
		j++;
		i++;
	}
	ret[size] = '\0';
	return (ret);
}

int	is_dict(t_dict *tab, char *input)
{
	int	i;

	i = 0;
	while (tab[i].key != 0)
	{
		if (ft_strcmp(tab[i].key, input) == 0)
		{
			return (i);
		}
		i++;
	}
	return (0);
}
