/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odessein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 13:11:37 by odessein          #+#    #+#             */
/*   Updated: 2022/02/13 14:39:15 by odessein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h>

void	ft_init(int skyscraper[4][4]);
void	ft_display(int skyscraper[4][4]);
int		ft_split_arg(char *str, int tab[16]);
int		ft_strlen(char *str);
void	ft_obvious(int skyscraper[4][4], int input[16]);
int		ft_check_0(int skyscraper[4][4]);
int		ft_ultimate_check(int tab[4][4], int line, int col, int input[16]);


int	ft_solve(int to_fill[4][4], int line, int column, int tabs[16], int n)
{
	n++;
	//printf("%i \n", line);
	if (ft_check_0(to_fill))
		return (1);
	else if (n == 50)
		return 1;
	else if (line >= 4)
	{
		ft_solve(to_fill, 0, 0, tabs , n);
	}
	else if (column >= 4)
		ft_solve(to_fill, ++line, (column - 4), tabs, n);
	else
	{
		while (ft_ultimate_check(to_fill, line, column, tabs) != 1 && to_fill[line][column] < 6)
		{
//			printf("%i ", to_fill[line][column]);
			++to_fill[line][column];
		}
		if (to_fill[line][column] > 4)
			to_fill[line][column] = 0;
	}
	ft_solve(to_fill, line, ++column, tabs, n);
}

int	main(int argc, char *argv[])
{
	char	*input_str;
	int		skyscraper[4][4];
	int		input[16];

	input_str = argv[1];
	if (argc != 2)
		return (-1);
	ft_init(skyscraper);
	if (ft_split_arg(input_str, input) == 1)
		return (-1);
	ft_obvious(skyscraper, input);
	if (ft_solve(skyscraper, 0, 0, input, 0) == 1)
		ft_display(skyscraper);
	return (0);
}
