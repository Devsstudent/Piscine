/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odessein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 03:14:25 by odessein          #+#    #+#             */
/*   Updated: 2022/02/09 05:49:18 by odessein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

char	*ft_strlowcase(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < 91 && str[i] > 64)
			str[i] = str[i] + 32;
		++i;
	}
	return (str);
}

int	ft_check(char c)
{
	if (c > 47 && c < 58)
		return (2);
	else if (c > 96 && c < 123)
		return (1);
	else if (c > 64 && c < 91)
		return (0);
	else
		return (3);
}

char	*ft_strcapitalize(char *str)
{
	int	cursor;

	ft_strlowcase(str);
	cursor = 0;
	while (str[cursor] != '\0')
	{
		if (cursor == 0 && ft_check(str[cursor]) == 1)
		{
			str[cursor] -= 32;
		}
		else if (ft_check(str[cursor]) == 3)
		{
			if (str[cursor + 1] != '\0' && ft_check(str[cursor + 1]) == 1)
				str[cursor + 1] -= 32;
		}
		++cursor;
	}
	return (str);
}
