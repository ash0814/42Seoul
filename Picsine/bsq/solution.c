#include "header.h"

int 	**map_count;

int		**char_to_int_entries(int **nb_entries)
{
	int i;

	i = 0;
	nb_entries = (int **)malloc(sizeof(int*) * g_height);
	while(i < g_height)
	{
		nb_entries[i] = (int *)malloc(sizeof(int) * g_width);
		i++;
	}
	return (nb_entries);
}

void copy_entries(int **nb_entries)
{
	int x;
	int y;
	
	x = 0;
	while (x < g_height)
	{
		y = 0;
		while (y < g_width)
		{
			if (g_entries[x][y] == g_empty)
				nb_entries[x][y] = 1;
			else if (g_entries[x][y] == g_obstacle)
				nb_entries[x][y] = 0;
			y++;
		}
		x++;
	}
}

void	print_square(int x, int y, int max)
{
	int print_x;
	int print_y;
	
	print_x = x - max + 1;
	print_y = y - max + 1;
	while (print_x <= x)
	{
		while (print_y <= y)
		{
			g_entries[print_x][print_y] = g_fill;
			print_y++;
		}
		print_x++;
	}
}

/*
void	init_map_count(int **map_count)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < g_height)
	{
		map_count[i][0] = 0;
		i++;
	}
	while (j < g_width)
	{
		map_count[0][j] = 0;
		j++;
	}
}
*/

void	solution(int **nb_entries) //정사각형 우측 아래 모서리 좌표, 변 크기 계산 알고리즘
{
	int min_max[2]; //[0]이 min이고 [1]가 max
	int i;
	int j;
	int x_y[2];
	
	//map_count = char_to_int_entries(map_count);
	//init_map_count(map_count);

	i = 1;
	while (i < g_height)
	{
		j = 1;
		while (j < g_width)
		{
			if (map_count[i][j] != 0)
			{
				min_max[1] = 0;
				nb_entries[i][j] = compare3(nb_entries[i - 1][j - 1], nb_entries[i - 1][j],
						nb_entries[i][j - 1], min_max[0]) + 1;
			}
			if (nb_entries[i][j] > min_max[1])
			{
				min_max[1] = nb_entries[i][j];
				x_y[0] = i;
				x_y[1] = j;
			}
			j++;
		}
		i++;
	}
	/*
for (int t = 0; t < 10; t++)
{
	for (int k = 0; k < 10; k++)
	{
		printf("%d", nb_entries[t][k]);
	}
printf("\n");
}*/
	print_square(x_y[0], x_y[1], min_max[1]);
}

void trans_nb_entries(void){
	int	**nb_entries;
	int x;
	int y;
	
	nb_entries = char_to_int_entries(nb_entries);
	nb_entries[0][0] = 1;

	copy_entries(nb_entries);
	solution(nb_entries);
	ft_free_int_entries(nb_entries);
}
