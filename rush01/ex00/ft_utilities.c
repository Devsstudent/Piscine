/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utilities.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odessein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 15:48:08 by odessein          #+#    #+#             */
/*   Updated: 2022/02/13 09:22:50 by khuynh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdio.h>

void	ft_init(int skyscraper[4][4])
{
	int		i;
	int		j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			skyscraper[i][j] = 0; // skyscraper = malloc(sizeof(int)*
			j++;
		}
		i++;
	}
}

void	ft_display(int skyscraper[4][4])
{
	int		i;
	int		j;
	char	value;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			value = skyscraper[i][j] + 48;
			write (STDOUT_FILENO, &value, 1);
			if (j < 3)
				write (STDOUT_FILENO, " ", 1);
			j++;
		}
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
}

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	if (len != 31)
		return (-1);
	return (len);
}

int	ft_split_arg(char *str, int tab[16])
{
	int	i;
	int	j;
	int	ref;

	i = 0;
	j = 0;
	ref = 0;
	while (str[i])
	{
		if ((str[i] >= '1') && (str[i] <= '4') && (ref == 0))
		{
			tab[j] = str[i] - '0'; //tab = malloc(sizeof(int)*j); if tab == NULL, return (0); 
			ref = 1;
			j++;
		}
		else if ((str[i] == ' ') && (ref == 1))
			ref = 0;
		else
			return (1);
		i++;
	}
	if (i != 31)
		return (1);
	return (0);
}
