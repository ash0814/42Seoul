#ifndef MINIRT_H
# define MINIRT_H

#include <unistd.h>
#include <mlx.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <math.h>

#include "structures.h"

// vec_utils
t_vec	vec(double x, double y, double z);
t_vec	color(double r, double g, double b);
t_point	point(double x, double y, double z);
t_vec	v_add(t_vec v1, t_vec v2);
t_vec	v_sub(t_vec v1, t_vec v2);
double	v_dot(t_vec v1, t_vec v2);
t_vec	v_cross(t_vec v1, t_vec v2);
t_vec	v_unit(t_vec v);
t_vec	v_min(t_vec vec1, t_vec vec2);
t_vec	vt_mul(t_vec v1, double t);
t_vec	vv_mul(t_vec vec, t_vec vec2);
t_vec	v_div(t_vec v1, double t);
double	v_pow(t_vec v1);
double	v_len(t_vec v1);

// split_utils
size_t	ft_check_len(char const *s, char c);
char	**ft_split(char const *s, char c);
char	**ft_put_r_wsp(const char *s, size_t h, size_t len);
size_t	ft_check_len_wsp(char const *s);
char	**ft_split_wsp(char const *s);
int		ft_strlen(char *s);
void	*ft_calloc(size_t count, size_t size);
char	**ft_malloc_r(char **r, size_t h, size_t len);
char	**ft_put_r(const char *s, char c, size_t h, size_t len);
int		ft_split_len(char *s, char c);

//init
t_scene		*scene_init(void);

// parse
void	parse(char *argv, t_scene *scene);

#endif