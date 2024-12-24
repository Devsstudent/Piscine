/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odessein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 16:38:58 by odessein          #+#    #+#             */
/*   Updated: 2022/02/20 21:00:09 by odessein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define BUF_SIZE 4096
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	ft_strlen(char *str);
char	*ft_strstr(char	*str, char *to_find);
void	ft_putstr(char *str);
int	ft_tab_len(char *str);
char	*rev_tab(char *tab, int size);
int	ft_ultimate_check(char *key, char *file, int buff_pos, int pos);
int	ft_check_key(char *key, char *file);
char	*return_line(char *to_find, char *file);
char	*ft_sort_line(char *line);
char	*ft_return_str(int size, char *key);
char	*ft_decomp_hundreds(char *key_mod_3, char *file);
char	*ft_decomp_tens(char *key_mod_3, char *file);
void	char_to_string(char c, char *str);

int	main(int argc, char **argv)
{
	int		fd;
	int		ret;
	char	file[BUF_SIZE];
	char	*buf_input;
	char	*buf_to_decomp;
	char	*buf_buf_input;
	char	*file_name;
	int		i;

	file_name = "numbers.dict";
	buf_input = argv[1];
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
	{
		write(2, "Dict Error", 5);
	}
	ret = read(fd, file, BUF_SIZE);
	while (ft_strlen(buf_input) != 0)
	{
		if (ft_check_key(buf_input, file))
		{
			int b ;
			//implement la list chainee
		}
		else
		{
			//avoir la size de buf_to_decomp
			i = ft_strlen(buf_input);
			buf_to_decomp = ft_return_str(i, buf_input);
			buf_buf_input = malloc(sizeof(*buf_buf_input) * (ft_strlen(buf_input) - ft_strlen(buf_to_decomp)));
			while (i < ft_strlen(buf_input))
			{
				buf_buf_input[i] = buf_input[i];
				i++;
			}
			if (ft_check_key(buf_to_decomp, file))
			{
				printf("%s",ft_sort_line(return_line(buf_to_decomp, file)));
			}
			else
			{
				printf("%s", ft_decomp_hundreds(buf_to_decomp, file));
			//again
				printf("%s", ft_decomp_tens(buf_to_decomp, file));
			//again xd
				char_to_string(buf_to_decomp[0], buf_to_decomp);
				printf("%s", ft_sort_line(return_line(buf_to_decomp, file)));
			}
		}
		buf_input = buf_buf_input;
		free(buf_buf_input);
		//when chained list implemented alors on reduit le bufinput avec
		//malloc etc .. a voir en fonction de la taille combien on va en gere
		// et si le premier et faux 
	}
	return (0);
}
