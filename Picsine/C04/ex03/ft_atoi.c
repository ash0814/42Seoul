int 	ft_atoi(char *str)
{
	int cnt_m;
	int i;
	int n;

	cnt_m = 0;
	i = 0;
	n = 0;
	while (str[i] < '/' || str[i] > ':' || str[i] == '\n' || str[i] == '\t' ||
			str[i] == '\v' || str[i] == '\t' ||
			str[i] == '\f' || str[i] == '\r') // 숫자를 만날 때까지
	{
		if (str[i] == '-')
			cnt_m++;
		i++;
	}
	while (str[i] > '/' && str[i] < ':' && str[i] != '\0')
	{
		n = n * 10 + str[i] - '0';
		i++;
	}
	if (cnt_m % 2 == 0)
		return (n);
	else
		return (-n);
}

#include <stdio.h>
int main(void)
{
	int n = ft_atoi("  	--\t-+-\n-+123456-7");
	printf("%d", n);
	return 0;
}
