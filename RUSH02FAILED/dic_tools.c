/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dic_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odessein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 18:18:47 by odessein          #+#    #+#             */
/*   Updated: 2022/02/20 20:41:28 by odessein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define BUF_SIZE 4096
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

char	*ft_strstr(char	*str, char *to_find);
int	ft_strlen(char *str);
int	ft_check_key(char *key, char *file);

int	ft_ultimate_check(char *key, char *file, int buff_pos, int pos)
{
	char	*buff;
	int		i;


	if (buff_pos == -1) 
		return (buff_pos);
	if (ft_check_key(key, file))
		return (buff_pos);
	buff = malloc(sizeof(*buff) * (pos + 1));
	i = 0;
	while (i <= buff_pos)
	{
		buff[i] = key[i];
		i++;
	}
	if (buff_pos != pos)
		free(key);
	while (i <= pos)
	{
		buff[i] = '0';
		i++;
	}
	printf("%s ", buff);
	buff[i] = '\0';
	return (ft_ultimate_check(buff, file, buff_pos - 1, pos));
}

int	ft_check_key(char *key, char *file)
{
	char 	*find;
	int		size;

	size = ft_strlen(key);
	find = ft_strstr(file, key);
	if (find == 0 || find[size + 1] == '0')
		return (0);
	
	return (1);
}

char	*return_line(char *to_find, char *file)
{
	int		i;
	int 	len;
	char	*line;
	char	*part;

	i = 0;	
	part = ft_strstr(file, to_find);
	while (part[i] != '\n')
	{
		i++;
	}
	line = malloc(sizeof(*line)*(i + 1));
	i = 0;
	while (part[i] != '\n')
	{
		line[i] = part[i];
		i++;
	}
	return line;
}

char	*ft_sort_line(char *line)
{
	int		i;
	int		j;
	int 	size;
	int		buff;
	char	*res;

	i = 0;
	j = 0;
	size = 0;
	while (line[i] != ' ')
		i++;
	buff = i;
	while (line[++buff] != '\0')
		size++;
	res = malloc(sizeof(*res) * (size + 1));
	i++;
	while (line[i] != '\0')
	{
		res[j] = line[i];
		i++;
		j++;
	}
	res[j] = '\0';
	return (res);
}

/*
int	main(void)
{
	int fd;
	int i;
	char *input = "12 345 678 949";
	char **tab;
	char buf[BUF_SIZE];
	int j;
	int ret;
	char *rev;
	char *line;
	char *res;

	i = 0;
	j = 0;
	fd = open("numbers.dict", O_RDONLY);
	if (fd == -1)
	{
		write(2, "error", 5);
	}
	ret = read(fd, buf, BUF_SIZE);
//	line = return_line("9", buf);	
//	res = ft_sort_line(line);
//	printf("%i", ft_check_key("10000", buf));
	printf("\n\n%i", ft_ultimate_check("12345678", buf, 7, 7));
	i = 0;
	//buf[ret] = '\0';
} */
