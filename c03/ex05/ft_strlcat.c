/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odessein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 13:05:24 by odessein          #+#    #+#             */
/*   Updated: 2022/02/16 10:46:54 by odessein         ###   ########.fr       */
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

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	size_src;
	unsigned int	size_dest;
	unsigned int	brows;
	unsigned int	brows_src;

	brows = 0;
	brows_src = 0;
	size_dest = ft_strlen(dest);
	size_src = ft_strlen(src);
	if (size < 1)
		return (size_src + size);
	while (brows < size_dest || brows < size - 1)
	{
		if (brows >= size_dest)
		{
			dest[brows] = src[brows_src];
			brows_src++;
		}
		brows++;
	}
	if (size > size_dest)
		dest[brows] = '\0';
	if (size_dest > size)
		return (size_src + size);
	return (size_src + size_dest);
}
