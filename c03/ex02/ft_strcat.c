/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odessein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 13:48:40 by odessein          #+#    #+#             */
/*   Updated: 2022/02/14 09:03:42 by odessein         ###   ########.fr       */
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

char	*ft_strcat(char *dest, char *src)
{
	int		brows;
	int		len_src;
	int		len_dest;

	len_src = ft_strlen(src);
	len_dest = ft_strlen(dest);
	brows = 0;
	while (brows < len_src)
	{
		dest[len_dest + brows] = src[brows];
		++brows;
	}
	dest[len_dest + brows] = '\0';
	return (dest);
}
