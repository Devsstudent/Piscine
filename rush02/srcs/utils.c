/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmathie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 20:28:41 by thmathie          #+#    #+#             */
/*   Updated: 2022/02/20 20:31:14 by thmathie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/struct.h"
#include "../includes/head.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] < s2[i])
			return (-1);
		if (s1[i] > s2[i])
			return (1);
		i++;
	}
	return (0);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i++], 1);
	}
}

int	cmplen(int a, int b)
{
	if (a == b)
		return (1);
	else
		return (0);
}

int	cmpchar(char input, char key)
{
	if (input == key)
		return (1);
	else
		return (0);
}
