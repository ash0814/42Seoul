int		ft_strncmp(char *s1, char *s2, unsigned int n)
{
	int i;

	i = 0;
	if (n = 0)
		return (0);
	while (i < n)
	{
		if (s1[i] != s2[i])
			break;
		i++;
	}
	return (s1[i] - s2[i]);
}

char *ft_strstr(char *str, char *to_find)
{
	int fi;
	int i;

	i = 0;
	fi = 0;
	while (to_find[fi] != '\0')
		fi++;
	while (str[i] < '\0')
	{
		ft_strncmp(str[i], to_find[fi], fi);
	}
}
