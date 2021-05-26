#ifndef MAPHEADER
# define MAPHEADER

// infornmation of map, in file's fist line
typedef struct s_info
{
	char empty;
	char obstacle;
	char fill;
	int height;
}				t_info
/*
typedef struct name {
	var a;
	var b;
	var c;
} 				t_n;

t_s *name;
name.a = name이 pointer x
*name.a pointer
*/


/* typedef struct entries {
	
}

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

//ft_string.c
int ft_strlen(char *str);
#define MAPHEADER

