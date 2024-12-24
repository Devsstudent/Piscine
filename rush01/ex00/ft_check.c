/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odessein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 12:14:46 by odessein          #+#    #+#             */
/*   Updated: 2022/02/13 14:30:17 by odessein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
int	ft_chk_raw_l_val(int skyscraper[4][4], int line, int input[16])
{
	int	buf_input;
	int	tall;
	int	count;
	int	i;

	i = -1;
	tall = 0;
	count = 0;
	buf_input = input[8 + line]; //value inputed pour la line actuel a gauche
//	printf("%i ", buf_input);	
	if (buf_input == 1 || buf_input == 4)
		return (1);
	while (++i < 4)
	{
		//printf("%i ", skyscraper[line][i]);
		if (skyscraper[line][i] == 0)
			continue ;
		if (skyscraper[line][i] > tall)
		{
			count++;
			tall = skyscraper[line][i];
		}
	}
	if (count == buf_input)
		return (1);
	return (0);
}

int	ft_chk_raw_r_val(int skyscraper[4][4], int line, int input[16])
{
	int	buf_input;
	int	tall;
	int	count;
	int	i;

	i = 4;
	tall = 0;
	count = 0;
	buf_input = input[12 + line]; //value inputed pour la line actuel a droite
	if (buf_input == 1 || buf_input == 4)
	{
		return (1);
	}
	while (--i > -1)
	{
		if (skyscraper[line][i] == 0)
			continue ;
		if (skyscraper[line][i] > tall)
		{
			count++;
			tall = skyscraper[line][i];
		}
	}
	if (count == buf_input)
		return (1);
	return (0);
}

int	ft_chk_col_u_val(int skyscraper[4][4], int col, int input[16])
{
	int	buf_input;
	int	tall;
	int	count;
	int	i;

	i = -1;
	tall = 0;
	count = 0;
	buf_input = input[col]; //value inputed pour la column actuel en haut 
	if (buf_input == 1 || buf_input == 4)
		return (1);
	while (++i < 4)
	{
		if (skyscraper[i][col] == 0)
			continue ;
		if (skyscraper[i][col] > tall)
		{
			count++;
			tall = skyscraper[i][col];
		}
	}
	if (count == buf_input)
		return (1);
	return (0);
}

int	ft_chk_col_d_val(int skyscraper[4][4], int col, int input[16])
{
	int	buf_input;
	int	tall;
	int	count;
	int	i;

	i = 4;
	tall = 0;
	count = 0;
	buf_input = input[4 + col]; //value inputed pour la col actuel en bas 
	if (buf_input == 1 || buf_input == 4)
		return (1);
	while (--i > -1)
	{
		if (skyscraper[i][col] == 0)
			continue ;
		if (skyscraper[i][col] > tall)
		{
			count++;
			tall = skyscraper[i][col];
		}
	}
	if (count == buf_input)
		return (1);
	return (0);
}

int	ft_check_0(int skyscraper[4][4])
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (skyscraper[i][j] == 0)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
