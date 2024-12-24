/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mduleme <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 12:15:25 by mduleme           #+#    #+#             */
/*   Updated: 2022/02/13 13:02:37 by mduleme          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	ft_nb_args(char *str, int tab[16])
{
	int	len_str;
	int	len_tab;

	len_str = 0;
	len_tab = 0;
	while (str[len_str])
		len_str++;
	while ((tab[len_tab] >= 1) && (tab[len_tab] <= 4))
		len_tab++; 
	if ((len_str == 31) && (len_tab == 16))
		return (1);
	else
		return (0);
}

int	ft_test_arg(int tab[16],int brows,int brows2)
{
	if (tab[brows] == 4)
	{
		if (tab[brows2] != 1)
			return (0);
	}
	else if (tab[brows] == 3)
	{
		if (tab[brows2] == 4 || tab[brows2] == 3)
			return (0);
	}	
	else if (tab[brows] == 2)
	{
		if	(tab[brows2] == 4)
			return (0);
	}
	else if (tab[brows] == 1)
	{
		if (tab[brows2] == 1)
			return (0);
	}
	return (1);
}

int	ft_args(int tab[16])
{
	int	brows;
	int	ret;

	brows = 0;
	while (brows < 16)
	{
		if (brows < 4 || (brows > 7 && brows < 12))
			ret = ft_test_arg(tab, brows, brows + 4);
				if (ret == 0)
				{
					return(ret);
				}
		if ((brows < 8 && brows > 3) || (brows > 11))
			ret = ft_test_arg(tab, brows, brows - 4);
				if (ret == 0)
				{
					return(ret);
				}
		brows++;
		return (1);
	}
}

int ft_no_sol(int val_solve)
{
	// to do, si pas e solution renvoie 0
}

int	ft_error(int tab[16], char *str, int val)
{
	if (ft_args(tab) == 0 || ft_no_sol(val) == 0 || ft_nb_args(str, tab)  == 0)
	{		
		write(2, "Error", 5)
		return(0);
	}
	return (1)
}
