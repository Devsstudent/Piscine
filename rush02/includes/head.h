/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   head.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmathie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 20:17:16 by thmathie          #+#    #+#             */
/*   Updated: 2022/02/20 20:20:25 by thmathie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEAD_H
# define HEAD_H
# include <unistd.h>
# include "struct.h"
# include <stdlib.h>

int			is_dict(t_dict *tab, char *input);
int			get_struct_len(char *file);
int			ft_strcmp(char *s1, char *s2);
int			ft_strlen(char *str);
int			cmplen(int a, int b);
int			cmpchar(char input, char key);
char		*grabnbr(char *file, int i);
char		*grabvalue(char *file, int i);
char		*print(t_dict *tab, char *input, int a);
char		*decompo(char *input, t_dict *tab);
void		ft_putstr(char *str);
t_dict		*split_dict(char *file);
#endif
