/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odessein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 19:15:59 by odessein          #+#    #+#             */
/*   Updated: 2022/02/24 11:59:27 by odessein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_create_final_str(int size, char **strs, char *sep, char *final_str);
size_t	ft_calc_final_s(char *sep, char **strs, int strs_len);

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*final_str;
	size_t	final_size;

	if (size <= 0 || strs == NULL)
	{
		final_str = NULL;
		return (final_str);
	}
	final_size = ft_calc_final_s(sep, strs, size);
	final_str = malloc(sizeof(*final_str) * final_size);
	if (!final_str)
	{
		final_str = NULL;
		return (final_str);
	}
	ft_create_final_str(size, strs, sep, final_str);
	return (final_str);
}

void	ft_create_final_str(int size, char **strs, char *sep, char *final_str)
{
	char	*ptr_on_strs;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	while (i < size)
	{
		ptr_on_strs = strs[i];
		while (*ptr_on_strs)
		{
			final_str[j] = *ptr_on_strs;
			ptr_on_strs++;
			j++;
		}
		k = 0;
		while (sep != NULL && sep[k] != '\0' && i < size - 1)
		{
			final_str[j] = sep[k];
			k++;
			j++;
		}
		i++;
	}
}

size_t	ft_calc_final_s(char *sep, char **strs, int strs_len)
{
	int	len_sep;
	int	total_word_len;
	int	i;
	int	whiler;

	len_sep = 0;
	i = 0;
	total_word_len = 0;
	while (sep != NULL && sep[len_sep] != '\0')
		len_sep++;
	while (i < strs_len)
	{
		whiler = 0;
		while (strs[i][whiler] != '\0')
			whiler++;
		total_word_len += whiler;
		i++;
	}
	return (len_sep * sizeof(*sep) + total_word_len * sizeof(**strs));
}
