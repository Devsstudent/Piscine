/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odessein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 16:08:22 by odessein          #+#    #+#             */
/*   Updated: 2022/02/15 16:09:24 by odessein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int	size;
	int	i;

	size = 0;
	i = 0;
	while (str[i] != '\0')
	{
		size++;
		i++;
	}
	return (size);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		++i;
	if (s1[i] != s2[i])
		return (s1[i] - s2[i]);
	return (0);
}

int	ft_check_order(char **argv, int size)
{
	int	i;

	i = 1;
	while (i < size - 1)
	{
		if (ft_strcmp(argv[i], argv[i + 1]) > 0)
			return (0);
		i += 1;
	}
	return (1);
}

char	**ft_sort_argv(char **argv, int argc)
{
	int		i;
	char	*buffer;

	while (ft_check_order(argv, argc) != 1)
	{
		i = 1;
		while (i < argc - 1)
		{
			if (ft_strcmp(argv[i], argv[i + 1]) > 0)
			{
				buffer = argv[i];
				argv[i] = argv[i + 1];
				argv[i + 1] = buffer;
			}
			i += 1;
		}
	}
	return (argv);
}

int	main(int argc, char *argv[])
{
	int	i;
	int	j;

	i = 1;
	ft_sort_argv(argv, argc);
	while (i < argc)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			write(STDOUT_FILENO, &argv[i][j], 1);
			j += 1;
		}
		write(STDOUT_FILENO, "\n", 1);
		i += 1;
	}
	return (0);
}
