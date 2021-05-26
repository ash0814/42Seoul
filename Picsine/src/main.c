#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

char g_empty;
char g_obstacle;
char g_fill;
int  g_height;

void print_error(void)
{
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
			print_error();
		else
		{
			result = result * 10 +  str[i] - '0';
			i++;
		}
	}
		return (result);
}

int main(int argc, char *argv[])
{
	int fd;
	char c;
	int count;
	char buf[1024];

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		printf("Error\n");
	count = 0;
	while (c != '\n')
	{
		read(fd, &c, 1);
		buf[count] = c;
		count++;
	}
	//buf[count] = 0;

	printf("%s", buf);

	g_fill = buf[count - 2];
	g_obstacle = buf[count - 3];
	g_empty = buf[count - 4];

	printf("%c, %c, %c\n", g_fill, g_obstacle, g_empty);
	g_height = ft_atoi(buf, count - 4);
	printf("%d ", g_height);
	close(fd);
	return 0;
}