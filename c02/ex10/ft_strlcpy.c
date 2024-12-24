/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odessein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 19:39:49 by odessein          #+#    #+#             */
/*   Updated: 2022/02/10 13:51:44 by odessein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	int	check_size;
	int	counter;

	check_size = 0;
	counter = 0;
	while (src[check_size] != '\0')
		++check_size;
	if (size < 1)
		return (check_size);
	while ((unsigned int) counter < (size - 1))
	{
		dest[counter] = src[counter];
		++counter;
	}
	dest[counter] = '\0';
	return (check_size);
}
