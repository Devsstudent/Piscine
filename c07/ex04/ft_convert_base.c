/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odessein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 16:55:43 by odessein          #+#    #+#             */
/*   Updated: 2022/02/24 12:19:40 by odessein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int		ft_strlen(char *str);
void	ft_to(long int value, char *base, char **final_nbr, int *neg_sign);
int		ft_convert_from(char *str, char *base);
int		ft_bases(char *base_from, char *base_to, char *nbr, int *neg_sign);
int		ft_check_base(char *base);
void	ft_check_nbr(char *str, char *base_from, int *neg_sign);
int	long	ft_power(int long nb, int long power);
int		ft_size_value_base(long int value, int size_base);

void	ft_fill(char *final_nbr, long int value, int size_base, char *base)
{
	int			count;
	int long	pow;
	int			i;
	int			size;

	i = 0;
	if (final_nbr[0] == '-')
		i = 1;
	size = ft_size_value_base(value, size_base) - 1;
	while (size >= 0)
	{
		count = 0;
		pow = ft_power(size_base, size);
		while ((value - pow) >= 0)
		{
			value = value - pow;
			count++;
		}
		final_nbr[i] = base[count];
		size--;
		i++;
	}
	final_nbr[i] = '\0';
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	long int	str_frombase;
	char		*nbr_in_base_to;
	char		*nbr_cp;
	int			neg_sign;
	int			i;

	nbr_cp = NULL;
	if (nbr == 0 || base_from == 0 || base_to == 0)
		return (NULL);
	i = 0;
	nbr_in_base_to = NULL;
	nbr_cp = malloc(sizeof(*nbr_cp) * (ft_strlen(nbr_cp) + 1));
	if (!nbr_cp)
		return (NULL);
	while (i <= ft_strlen(nbr_cp))
	{
		nbr_cp[i] = nbr[i];
		i++;
	}
	if (ft_bases(base_from, base_to, nbr_cp, &neg_sign) != 1)
		return (nbr_in_base_to);
	str_frombase = ft_convert_from(nbr_cp, base_from);
	ft_to(str_frombase, base_to, &nbr_in_base_to, &neg_sign);
	return (nbr_in_base_to);
}

int	ft_bases(char *base_from, char *base_to, char *nbr, int *neg_sign)
{
	*neg_sign = 1;
	if (ft_check_base(base_from) != 1)
		return (0);
	if (ft_check_base(base_to) != 1)
		return (0);
	ft_check_nbr(nbr, base_from, neg_sign);
	if (nbr[ft_strlen(nbr) - 1] == '+' || nbr[ft_strlen(nbr) - 1] == '-')
		return (0);
	return (1);
}

int	ft_check_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i] != '\0')
	{
		j = 0;
		if ((base[i] < 14 && base[i] > 8) || base[i] == ' ')
			return (0);
		if (base[i] == '+' || base[i] == '-')
			return (0);
		while (base[j] != '\0')
		{
			if (base[j] == base[i] && i != j)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_check_nbr(char *nbr, char *base_from, int *neg_sign)
{
	int	i;
	int	j;

	i = 0;
	while ((nbr[i] < 14 && nbr[i] > 8) || nbr[i] == ' ')
		i++;
	while (nbr[i] == '+' || nbr[i] == '-')
	{
		if (nbr[i] == '-')
			*neg_sign = *neg_sign * (-1);
		i++;
	}
	while (nbr[i] != '\0')
	{
		j = 0;
		while (base_from[j] != '\0')
		{
			if (nbr[i] == base_from[j])
				break ;
			j++;
		}
		if (base_from[j] == '\0')
			nbr[i] = '\0';
		i++;
	}
}
