/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ash <ash@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 01:52:01 by ash               #+#    #+#             */
/*   Updated: 2021/05/18 01:14:51 by ash              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
t_color	color(double r, double g, double b);
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
int     ft_check_len(char const *s, char c);
char	**ft_split(char const *s, char c);
char	**ft_put_r_wsp(const char *s, int h, int len);
int     ft_check_len_wsp(char const *s);
char	**ft_split_wsp(char const *s);
int		ft_strlen(char *s);
void	*ft_calloc(int count, int size);
char	**ft_malloc_r(char **r, int h, int len);
char	**ft_put_r(const char *s, char c, int h, int len);
int		ft_split_len(char *s, char c);

//ray
t_vec		ray_at(t_ray *ray, double t);
t_color		ray_color(t_scene *scene);
t_ray		ray_primary(t_camera *cam, double u, double v);
t_ray		ray(t_point origin, t_vec dir);

// phong
t_color			phong_lighting(t_scene *scene);
t_color			diffuse_light(t_scene *scene, t_light *light);
t_color			specular_light(t_scene *scene, t_light *light);
t_bool				in_shadow(t_light *light, t_scene *scene);
t_vec				reflect(t_vec v, t_vec n);

// hit
t_bool		hit(t_object *world, t_ray *ray, t_hit_record *rec);
t_bool		hit_obj(t_object *world, t_ray *ray, t_hit_record *rec);

//hit_obj
t_bool		hit_sphere(t_object *sp_obj, t_ray *ray, t_hit_record *rec);
t_bool		hit_plane(t_object *plane_obj, t_ray *ray, t_hit_record *rec);
t_bool			hit_square(t_ray *r, t_object *obj, t_hit_record *rec);
t_bool			hit_triangle(t_ray *r, t_object *obj, t_hit_record *rec);
t_bool			hit_cylinder(t_ray *r, t_object *obj, t_hit_record *rec);
t_bool			check_tr(t_vec a, t_vec b, t_vec c, t_vec h);
t_bool			is_inside(t_point p1, t_point p2, t_point p3, t_point p);



//hook
int			key_hook(int keycode, t_vars *vars);
int			exit_hook();

//init
t_scene		*scene_init(void);
t_color			diffuse_light(t_scene *scene, t_light *light);
t_color			specular_light(t_scene *scene, t_light *light);
t_bool				in_shadow(t_light *light, t_scene *scene);
t_vec				reflect(t_vec v, t_vec n);

// parse
void	parse(char *argv, t_scene *scene);
void    check_file(char *str, t_scene *scene);

// parse_object
void	parse_r(char **words, t_scene *scene);
void	parse_a(char **words, t_scene *scene);
void	parse_l(char **words, t_scene *scene);
void	parse_cy(char **words, t_scene *scene);
void	parse_tr(char **words, t_scene *scene);
void	parse_sp(char **words, t_scene *scene);
void	parse_sq(char **words, t_scene *scene);
void	parse_pl(char **words, t_scene *scene)

//canvas
t_canvas	canvas(int	width, int height);


//camera
t_camera	*camera(t_canvas canvas, t_point orig);

// objects
t_sphere    *sphere(t_point center, double radius, t_color color);
t_plane	    *plane(t_point point, t_vec normal);
t_triangle  *triangle(t_point p1, t_point p2, t_point p3);
t_square    *square(t_point point, t_vec normal, double len);
t_cylinder  *cylinder(t_point point, t_vec normal, double radius, double heignt, t_color color);

// object_create
t_object    *object(t_object_type type, void *element);
t_object    *oadd(t_object **list, t_object *new);
t_object    *olast(t_object *list);
t_light     *light_point(t_point l_org, t_color l_color, double bright_ratio);

//utils
void    ft_error(char *s);
void    check_three_double(char **tmp);
void    check_three_nor(char **tmp);
void    double_free(char **str);
int     ft_len_2D(char **str);
void	set_face_normal(t_ray *r, t_hit_record *rec);
void    check_zero_to_one(char **tmp);

//ft_atoif
int			i_atoi(const char *str);
int			ft_atoi(const char *str);
double		ft_power(double a, int b);
double		ft_atof(const char *str);


#endif