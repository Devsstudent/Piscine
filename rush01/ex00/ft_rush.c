/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rush.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odessein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 15:41:17 by odessein          #+#    #+#             */
/*   Updated: 2022/02/12 21:56:28 by odessein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
void	ft_ultimate_obvious(int skyscraper[4][4], int browser)
{
	int	j;

	if (browser < 4 || (browser < 12 && browser > 7))
		j = 1;
	else
		j = 4;
	while (j < 5)
	{
		if (browser < 4)
			skyscraper[j - 1][browser] = j;
		else if (browser > 7 && browser < 12)
			skyscraper[browser % 4][j - 1] = j;
		j++;
	}
	while (j > 0)
	{
		if (browser < 8 && browser > 3)
			skyscraper[j - 1][browser % 4] = j;
		else if (browser < 16 && browser > 11)
			skyscraper[browser % 4][j - 1] = j;
		j--;
	}
}

void	ft_ultimate_obvious1(int skyscraper[4][4], int browser)
{
	if (browser < 4)
		skyscraper[0][browser] = 4;
	if (browser > 7 && browser < 12)
		skyscraper[browser % 4][0] = 4;
	if (browser < 8 && browser > 3)
		skyscraper[3][browser % 4] = 4;
	if (browser > 11)
		skyscraper[browser % 4][3] = 4;
}

void	ft_ultimate_obvious2(int skyscraper[4][4], int browser)
{
	if (browser < 4)
		skyscraper[2][browser] = 4;
	if (browser > 7 && browser < 12)
		skyscraper[browser % 4][2] = 4;
	if (browser < 8 && browser > 3)
		skyscraper[1][browser % 4] = 4;
	if (browser > 11)
		skyscraper[browser % 4][1] = 4;
}

void	ft_obvious(int skyscraper[4][4], int input[16])
{
	int	brows;

	brows = 0;
	while (brows < 16)
	{
		if (input[brows] == 1)
			ft_ultimate_obvious1(skyscraper, brows);
		if (input[brows] == 4)
			ft_ultimate_obvious(skyscraper, brows);
		if (input[brows] == 3)
		{
			if (brows < 4 || (brows > 7 && brows < 12))
			{
				if (input[brows + 4] == 2)
					ft_ultimate_obvious2(skyscraper, brows);
			}
			else if (input[brows - 4] == 2)
				ft_ultimate_obvious2(skyscraper, brows);
		}
		brows++;
	}	
}
