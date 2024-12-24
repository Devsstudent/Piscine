/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decomp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odessein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 01:14:21 by odessein          #+#    #+#             */
/*   Updated: 2022/02/20 20:40:43 by odessein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */ 
#include <stdlib.h> 

int	ft_check_key(char *key, char *file);
//search by size aussi ducoup
/*t_dict	decompo(char *str, int size, char *file)
{
	//mettre a null si on trouve sinon cree les chars //malloc ? // t_dict res; char	*diz;
	char	*cent; char	*unit; char	*buff;

	if (ft_check_key(str, file) == 1)
	{
		res.cent = str;
		return res;
	}
	else
	{
		buff = {str[0], '\0'};
		if (ft_check_key(buff) == 1)
		{
			res.cent = buff;
		}
		buff = {str[1], str[2], '\0'};
		if (ft_check_key(buff) == 1)
		{
			res.diz = buff;
		}
		else
		{
			buff = {str[1], '0', '\0'};
			res.diz = buff;
			res.unit = {str[0], '\0'};
		}
	}
}
*/

void	ft_alloc(char *str, char *str2, int size, int zero)
{
	int i;

	i = 0;
	str = malloc(sizeof(str) * (size + 1 + zero));
	while (i < size)
	{
		str[i] = str2[i];
		i++;
	}
	while (zero > 0)
	{
		str[i] = '0';
		i++;
		zero--;
	}
	str[i] = '\0';
}

char	*ft_decomp_tens(char *key_mod_3, char *file)
{
	char	*buf;

	ft_alloc(buf, key_mod_3, 2, 0);
	if (ft_check_key(buf, file))
		return (buf);
	else 
	{
		free(buf);
		ft_alloc(buf, key_mod_3, 1, 1);
		if (ft_check_key(buf, file))	
			return (buf);
	}
}


char	*ft_decomp_hundreds(char *key_mod_3, char *file)
{
	char	*buf;
	int		i;

	ft_alloc(buf, key_mod_3, 1, 0);
	i = 0;
	if (ft_check_key(buf, file))
	{
			free(buf);
			ft_alloc(buf, key_mod_3, 1, 2);
	}
	return (buf);
}

char	*ft_return_str(int size, char *key)
{
	int		i;
	char	*res;

	i = 0;
	size = size % 3;
	res = malloc(sizeof(*res) * (size + 1));
	while (i < 3 && size == 0)
	{
		res[i] = key[i];
		i++;
	}
	while (i < 2 && size == 2)
	{
		res[i] = key[i];
		i++;
	}
	if (i == 1)
	{
		res[0] = key[0];
		i++;
	}
	res[i] = '\0';
	return (res);
}
