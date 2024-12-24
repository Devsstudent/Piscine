/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odessein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 13:55:57 by odessein          #+#    #+#             */
/*   Updated: 2022/02/22 18:53:26 by odessein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int	ft_read(char *filename, char **arguments, char ***map);
void	ft_print(char **map);

int	main(int argc, char **argv)
{
	int		i;
	char	**map;	
	char	*arguments;

	i = 1;
	while (argv[i])
	{
		if (i > 1)
			free(arguments);
		if (ft_read(argv[i], &arguments, &map))
		{
			ft_print(map);
		}
		else
			return (0);
		i++;
	}
//	free(arguments);
	return (0);
}

void	ft_print(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (i < 9)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			printf("%c", map[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}
