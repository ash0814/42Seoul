#include <iostream>

int ft_toupper(int c)
{
	if ('a' <= c && c <= 'z')
		c -=32;
	return c;
}

int ft_strlen(char *s)
{
	int i = 0;
	while (s[i])
		i++;
	return i;
}

int main(int argc, char **argv)
{
	char c;
	if (argc != 1)
	{
		for (int i = 1; i < argc; i++) {
			for (int j = 0; j < (int)strlen(argv[i]); j++){
				c = ft_toupper(argv[i][j]);
				std::cout << c;
			}
			std::cout << " ";
		}
		std::cout << "\n";
	}
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
	return (0);
}
