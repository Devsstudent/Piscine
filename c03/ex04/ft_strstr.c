/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odessein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 12:06:47 by odessein          #+#    #+#             */
/*   Updated: 2022/02/14 09:08:45 by odessein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_strlen(char *str)
{
	int	size;

	size = 0;
	while (str[size] != '\0')
		++size;
	return (size);
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
