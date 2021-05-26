#include "header.h"

void	ft_free_int_entries(int **nb_entries)
{
	int i;
	
	i = 0;
	while (i < g_height)
	{
		free(nb_entries[i]);
		i++;
	}
	free(nb_entries);
}
