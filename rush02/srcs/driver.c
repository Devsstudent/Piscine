/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   driver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmathie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 20:26:52 by thmathie          #+#    #+#             */
/*   Updated: 2022/02/20 22:16:58 by odessein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "../includes/struct.h"
#include "../includes/head.h"
#define BUF_SIZE 4096

int	get_struct_len(char *file)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (file[i])
	{
		if (file[i] == '\n')
			len++;
		i++;
	}
	return (len);
}

t_dict	*split_dict(char *file)
{
	int		i;
	int		j;
	int		len;
	t_dict	*tab;

	i = 0;
	j = 0;
	len = get_struct_len(file);
	tab = malloc(sizeof(tab) * get_struct_len(file));
	while (i < len)
	{
		tab[i].key = grabnbr(file, j);
		tab[i].value = grabvalue(file, j);
		while (file[j] != '\n')
			j++;
		j++;
		i++;
	}
	tab[i].key = 0;
	tab[i].value = 0;
	return (tab);
}

char	*decompo(char *input, t_dict *tab)
{
	int		i;

	i = 0;
	while (tab[i].key)
	{
		if (cmplen(ft_strlen(input), ft_strlen(tab[i].key)))
		{
			while (!cmpchar(input[0], tab[i].key[0]))
				i++;
			return (tab[i].value);
		}
		i++;
	}
	return (tab[i].key);
}

char	*gettest(char *input, int i)
{
	char	*str;

	str = malloc(sizeof(char) * 2);
	str[0] = input[i];
	str[1] = '\0';
	return (str);
}

char	*print(t_dict *tab, char *input, int a)
{
	if (is_dict(tab, input))
	{	
		ft_putstr(tab[is_dict(tab, input)].value);
		return (input);
	}
	else if (a < ft_strlen(input))
	{
		ft_putstr(decompo(input, tab));
		write(1, " ", 1);
		print(tab, gettest(input, a + 1), a + 1);
	}
	return (input);
}
