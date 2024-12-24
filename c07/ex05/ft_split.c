/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odessein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 12:15:08 by odessein          #+#    #+#             */
/*   Updated: 2022/02/24 12:18:00 by odessein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int		ft_wordlen(char *str, char *spliter, int word_nb);
int		ft_check(char *charset, char c);
int		ft_count_word(char *str, char *charset);
void	ft_fill_res(char **res, char *str, char *spliter, int size);

char	**ft_split(char *str, char *charset)
{
	int		lenght_of_res;
	char	**res;
	int		i;

	lenght_of_res = ft_count_word(str, charset);
	res = malloc(sizeof(*res) * (lenght_of_res + 1));
	if (!res)
		return (res);
	res[lenght_of_res] = 0;
	i = 1;
	while (i < lenght_of_res + 1)
	{
		res[i - 1] = malloc(sizeof(**res) * (ft_wordlen(str, charset, i) + 1));
		if (!res[i - 1])
			return (NULL);
		i++;
	}
	ft_fill_res(res, str, charset, lenght_of_res);
	return (res);
}

void	ft_fill_res(char **res, char *str, char *spliter, int size)
{
	int	i;
	int	j;
	int	k;

	i = -1;
	j = 0;
	while (str[j] != '\0')
	{
		if (!ft_check(spliter, str[j]) && i < (size - 1))
		{
			i++;
			k = 0;
			while (!ft_check(spliter, str[j + k]) && str[j + k] != '\0')
			{
				res[i][k] = str[j + k];
				k++;
			}
			j = j + k;
			res[i][k] = '\0';
		}
		j++;
	}
}

int	ft_wordlen(char *str, char *spliter, int word_nb)
{
	int	word;
	int	len;
	int	j;

	j = 0;
	word = 0;
	while (str[j] != '\0')
	{
		len = 0;
		while (!ft_check(spliter, str[j]))
		{
			len++;
			j++;
		}
		if (len > 0)
			word++;
		if (word == word_nb)
			return (len);
		j++;
	}
	return (len);
}

int	ft_count_word(char *str, char *charset)
{
	int	j;
	int	count;

	j = 0;
	count = 0;
	while (str[j] != '\0')
	{
		if (ft_check(charset, str[j]) && j != 0)
		{
			if (!ft_check(charset, str[j + 1]))
			{
				count++;
			}
		}
		j++;
	}
	return (count + 1);
}

int	ft_check(char *charset, char c)
{
	while (*charset)
	{
		if (c == *charset)
			return (1);
		charset++;
	}
	return (0);
}
