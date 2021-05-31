#ifndef MAPHEADER
# define MAPHEADER

#include <stdio.h> //삭제
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

extern char g_empty;
extern char g_obstacle;
extern char g_fill;
extern int	g_height;
extern int	g_width;
extern char **g_entries;

//ft_string.c
int ft_strlen(char *str);

//file_read.c
void clear_global(void);
int compare3(int a, int b, int c, int min_max);

//validate
int	input_map_info(void);
	
int info_validate(void);
	
int	map_validate(void);
	
int is_printable(char str);
int	is_right_char(char str);

int check_validation(void);

//solution
void copy_entries(int **nb_entries);
void print_square(int x, int y, int max);
void solution(int **nb_entries);
void trans_nb_entries(void);
//solution help
int **char_to_int_entries(int **nb_entries);
void ft_free_int_entries(int **nb_entries);

//basefunction
int is_printable(char str);
void ft_putstr(char *str);


//main
void print_error(int fd);
int ft_atoi(char *str, int n);
char *ft_strncat(char *dest, char *src, unsigned int nb);
char *ft_double_m(unsigned long long m, char *buf);
void ft_create_entries(unsigned long long m);
void ft_put_entries(int fd);
void ft_width(int fd);
void ft_put_global(int fd);
#endif
