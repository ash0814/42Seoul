#include "header.h"

char g_empty;
char g_obstacle;
char g_fill;
int  g_height;
char *g_buf;
int g_width;
unsigned long long g_m;
char **g_entries;

void print_error(int fd)
{
	free(g_buf);
	close(fd);
	write(1, "map error\n", 10);
}

int ft_atoi(char *str, int n)
{
	int i;
	int result;

	i = 0;
	result = 0;
	while(i < n)
	{
		if (!('0' <= str[i] && str[i] <= '9'))
			write(1, "map error\n", 10);
		else
		{
			result = result * 10 +  str[i] - '0';
			i++;
		}
	}
		return (result);
}

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int i;
	unsigned int j;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	while (j < nb && src[j] != '\0')
	{
		dest[i] = src[j];
		j++;
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char  *ft_double_m(unsigned long long m, char *buf)
{
	char *newbuf;

	m = m * 2;
	newbuf = (char *)malloc(sizeof(char) * m);
	ft_strncat(newbuf, buf, m / 2);
	free(buf);
	return (newbuf);
}

void	ft_create_entries(unsigned long long m)
{
	int i;

	i = 0;
	g_entries = (char **)malloc(sizeof(char *) * g_height);
	while (i < g_height)
	{
		g_entries[i] = (char *)malloc(sizeof(char) * m);
		i++;
	}
}

void		ft_width(int fd)
{
	int i;
	int rcheck;

	i = 0;
	while ((rcheck = read(fd, &g_buf[i], 1)))
	{
		if (rcheck == -1)
		{
			print_error(fd);
			return ;
		}
		else if (g_buf[i] == '\n')
		{
			g_width = i;
			return ;
		}
		else if ((unsigned long long)i == g_m - 1)
			g_buf = ft_double_m(g_m, g_buf);
		i++;
	}
}

void	ft_put_entries(int fd)
{
	int c;
	int c_m;
	int malloc_check;

	g_m = 1024;
	malloc_check = 0;
	g_buf = (char *)malloc(sizeof(char) * g_m);
	c = -1;
	while (++c != g_height)
	{
		c_m = 0;
		ft_width(fd);
		if (malloc_check == 0)
		{
			ft_create_entries(g_width);
			malloc_check = 1;
		}		
		while(c_m < g_width)
		{
			g_entries[c][c_m] = g_buf[c_m];
			c_m++;
			//printf("%d ", c_m);
			//printf("%c ", g_buf[c_m]);
		}
	}
	if (read(fd, &g_buf[c_m], 1) != 0)
		print_error(fd);
}

void	ft_put_global(int fd)
{
	int count;
	char buf[1024];
	char c;

	count = 0;
	while (c != '\n')
	{
		read(fd, &c, 1);
		buf[count] = c;
		count++;
	}
	g_fill = buf[count - 2];
	g_obstacle = buf[count - 3];
	g_empty = buf[count - 4];
	g_height = ft_atoi(buf, count - 4);
}

int main(int argc, char *argv[])
{
	int fd;

	(void)argc; // 지금 argc를 안 쓰니까 넣었어. 쓸 때 지우면 댐
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	ft_put_global(fd);
	ft_put_entries(fd);

	trans_nb_entries();

	for (int i = 0; i < g_height; i++)
	{
		for(int j = 0; j < g_width; j++)
		{
			write(1, &g_entries[i][j], 1);
		}
		write(1, "\n", 1);
	}
	free(g_entries);//두번 프리 해야됨
	close(fd);
	return 0;
}
