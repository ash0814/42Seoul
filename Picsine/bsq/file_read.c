#include "header.h"

int compare3(int a, int b, int c, int min_max)
{
	if (a < b && a < c)
		min_max = a;
	else if (b < a && b < c)
		min_max = b;
	else
		min_max = c;
	return (min_max);
}
