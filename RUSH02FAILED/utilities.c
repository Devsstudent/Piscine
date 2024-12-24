/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odessein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 18:06:00 by odessein          #+#    #+#             */
/*   Updated: 2022/02/20 20:33:13 by odessein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define BUF_SIZE 4096
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void	char_to_string(char c, char *str)
{
	if (str != 0)
		free(str);
	str = malloc(sizeof(*str) * 2);
	str[0] = c;
	str[1] = '\0';
}

int	ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strstr(char	*str, char *to_find)
{
	unsigned int	brows;
	unsigned int	brows_to_find;
	unsigned int	size_to_find;

	brows = 0;
	size_to_find = ft_strlen(to_find);
	if (to_find[0] == '\0')
		return (str);
	while (str[brows] != '\0')
	{
		brows_to_find = 0;
		while (str[brows] == to_find[brows_to_find])
		{
			++brows_to_find;
			++brows;
			if (brows_to_find == size_to_find)
				return (str + (brows - brows_to_find));
		}
		if (brows_to_find != 0)
			brows -= brows_to_find;
		++brows;
	}
	return (0);
}
void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
		write(1, &str[i++], 1);
}

int	ft_tab_len(char *str)
{
	return ((ft_strlen(str) / 3 + ft_strlen(str) % 3));
}

char	*rev_tab(char *tab, int size)
{
	int i;
	char tmp;
	char *res;
	int j;

	res = malloc(sizeof(*tab)*(size + 1));
	i = size - 1;
	j = 0;
	while(i > -1)
	{
		res[j] = tab[i];
		j++;
		i--;
	}
	res[j] = '\0';
	return res;
}
