/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odessein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 02:58:13 by odessein          #+#    #+#             */
/*   Updated: 2022/02/14 09:53:33 by odessein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#define BASE "0123456789abcdef"

void	ft_print_string(char *string, int size)
{
	char	*buff;
	int		counter;

	buff = string;
	counter = 0;
	write(STDOUT_FILENO, " ", 1);
	while (string < (buff + 16) && counter < size)
	{
		if (*string < 32 || *string > 126)
			write(STDOUT_FILENO, ".", 1);
		else
			write(STDOUT_FILENO, string, 1);
		++string;
		++counter;
	}
}

void	ft_print_rev(unsigned long mem, int size)
{
	int				i;
	unsigned long	array[16];
	unsigned long	buff_mem;

	buff_mem = mem % 16;
	while (i < size)
	{
		array[i] = buff_mem;
		mem /= 16;
		buff_mem = mem % 16;
		++i;
	}
	while (i > 0)
	{
		write(STDOUT_FILENO, (BASE + array[i]), 1);
		--i;
	}
}

void	ft_print_line(char *str)
{
	int	n;

	n = -1;
	while (++n < 8)
	{
		write(STDOUT_FILENO, (BASE + ((unsigned int) *str) / 16), 1);
		write(STDOUT_FILENO, (BASE + ((unsigned int) *str) % 16), 1);
		write(STDOUT_FILENO, (BASE + ((unsigned int) *(str + 1)) / 16), 1);
		write(STDOUT_FILENO, (BASE + ((unsigned int) *(str + 1)) % 16), 1);
		if (*(str + 1) == '\0' && n < 7)
			break ;
		if (n < 7)
			write(STDOUT_FILENO, " ", 1);
		++str;
	}
	while (++n < 8)
		write(STDOUT_FILENO, " ", 1);
}

void	ft_print_mem(unsigned long memory)
{
	int				size;
	int				size_buf;
	unsigned long	buff_mem;

	buff_mem = memory;
	size_buf = 16;
	while (buff_mem > 10)
	{
		buff_mem /= 16;
		--size_buf;
	}
	size = 16 - size_buf;
	while (--size_buf > 0)
		write(STDOUT_FILENO, "0", 1);
	ft_print_rev(memory, size);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	int		counter;
	char	*str;
	void	*buff_addr;

	buff_addr = addr;
	if (size < 1)
		return (addr);
	counter = 0;
	str = addr;
	while (*str && (unsigned int) counter < size)
	{
		ft_print_mem((unsigned long) addr);
		write(STDOUT_FILENO, ": ", 2);
		ft_print_line((char *)addr);
		ft_print_string((char *)addr, (size - counter));
		if ((unsigned int )(counter + 16) > size)
			break ;
		write(STDOUT_FILENO, "\n", 1);
		addr = addr + 16;
		counter += 16;
	}
	addr = buff_addr;
	return (addr);
}
