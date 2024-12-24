#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define BUF_SIZE 4096
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
		write(1, &str[i++], 1);
}

int	ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_tab_len(char *str)
{
	return ((ft_strlen(str) / 3 + ft_strlen(str) % 3));
}

char	**alloc_tab(char *str)
{
	int i;
	int len;
	char **tab;

	i = 0;
	len = ft_tab_len(str);
	//alloc le tab, size de l'input / 3 + mod 3 si jamais un chiffre est pas dans un groupe de 3
	tab = (char **)malloc(sizeof(char *) * len);
	while (i < len)
	{
		//alloc de chaque case 3 + 1 pour le \0
		tab[i] = (char *)malloc(sizeof(char) * 4);
		i++;
	}
	return (tab);
}

char	*rev_tab(char *tab, int size)
{
	int i;
	char tmp;
	char *res;
	int j;

	res = malloc(sizeof(*tab)*(size + 1));
	i = size - 1;
	j = 0;
	while(i > -1)
	{
		res[j] = tab[i];
		j++;
		i--;
	}
	res[j] = '\0';
	return res;
}


char	**ft_split(char *str) //split notre input en groupe de 3
{
	int i;
	int j;
	int c;
	int end;
	char **tab;

	i = 0;
	j = 0;
	c = 0;
	end = ft_strlen(str) - 1;
	tab = alloc_tab(str);

	if (ft_strlen(str) % 3 != 0)
	{
		tab[0][ft_strlen(str) % 3] == 'b';
	}
	while(end != -2)
	{
		tab[i][j] = str[end];
		c++;
		j++;
		end--;
		if (c == 3 || tab[i][j+1] == 'b')
		{
			i++;
			j = 0;
			c = 0;
		}

	}	
	return (tab);
}

void sort(char **tab, int size)
{
	int i;
	int j;
	char tmp;
	int size_str;

	i = 0;
	j = 0;
	while (tab[i])
	{
		size_str = ft_strlen(tab[i]);
		if (size_str == 3)
		{
			tmp = tab[i][0];
			tab[i][0] = tab[i][2];
			tab[i][2] = tmp;
		}
		if (size_str == 2)
		{
			tmp = tab[i][0];
			tab[i][0] = tab[i][1];
			tab[i][1] = tmp;
		}
		i++;
	}
}

/*char	**sort_tab_of_tab(char **tab, int size)
{
	int i;
	int j;
	char *tmp;

	i = 0;
	j = size - 3;
	//printf("%d\n", j);
	while (i < size / 2)
	{
		tmp = tab[i];
		printf("i = %i j = %i\n",i, j);
		tab[i] = tab[j];
		tab[j] = tmp;
		j--;
		i++;
	}
	i = 0;
	while (tab[i] != 0)
        {
                printf("%s\n", tab[i]);
                i++;
        }
	return (tab);
		
}
*/
//12 345 678
int main()
{
	int fd;
	int i;
	char *input = "12345678911";
	char **tab;
	char buf[BUF_SIZE];
	int ret;

	i = 0;
/*	fd = open("numbers.dict", O_RDONLY);
	if (fd == -1)
	{
		write(2, "error", 5);
	}
	ret = read(fd, buf, BUF_SIZE);
	ft_putstr(buf);

	i = 0;
	while (buf[i] != input)
	{
		i++;
	}
	while (buf[i] != '\n')
	{
		write(1, &buf[i], 1);
		i++;
	}
	buf[ret] = '\0';
*/
	char *str;
	
	tab = ft_split(input);
	sort(tab, ft_tab_len(input));
	while (i < ft_tab_len(input));
        {
                printf("%s\n", tab[i]);
                i++;
        }

}
