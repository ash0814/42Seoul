/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehyan <sehyan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 01:52:01 by ash               #+#    #+#             */
/*   Updated: 2021/05/27 10:28:35 by sehyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <unistd.h>
# include <mlx.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h>

# include "structures.h"

t_vec		vec(double x, double y, double z);
t_color		color(double r, double g, double b);
t_point		point(double x, double y, double z);
t_vec		v_add(t_vec v1, t_vec v2);
t_vec		v_sub(t_vec v1, t_vec v2);
double		v_dot(t_vec v1, t_vec v2);
t_vec		v_cross(t_vec v1, t_vec v2);
t_vec		v_unit(t_vec v);
t_vec		v_min(t_vec vec1, t_vec vec2);
t_vec		vt_mul(t_vec v1, double t);
t_vec		vv_mul(t_vec vec, t_vec vec2);
t_vec		v_div(t_vec v1, double t);
double		v_pow(t_vec v1);
double		v_len(t_vec v1);

int			ft_check_len(char const *s, char c);
char		**ft_split(char const *s, char c);
char		**ft_put_r_wsp(const char *s, int h, int len);
int			ft_check_len_wsp(char const *s);
char		**ft_split_wsp(char const *s);
int			ft_strlen(char *s);
void		*ft_calloc(int count, int size);
char		**ft_malloc_r(char **r, int h, int len);
char		**ft_put_r(const char *s, char c, int h, int len);
int			ft_split_len(char *s, char c);

t_vec		ray_at(t_ray *ray, double t);
t_color		ray_color(t_scene *scene);
t_ray		ray_primary(t_camera *cam, double u, double v);
t_ray		ray(t_point origin, t_vec dir);

t_color		phong_lighting(t_scene *scene);
t_vec		reflect(t_vec v, t_vec n);
t_bool		in_shadow(t_object *objs, t_ray light_ray, double light_len);
t_color		point_light_get(t_scene *scene, t_light *light);

t_bool		hit(t_object *world, t_ray *ray, t_hit_record *rec);
t_bool		hit_obj(t_object *world, t_ray *ray, t_hit_record *rec);

t_bool		hit_sphere(t_object *sp_obj, t_ray *ray, t_hit_record *rec);
t_bool		hit_plane(t_object *plane_obj, t_ray *ray, t_hit_record *rec);
t_bool		hit_square(t_ray *r, t_object *obj, t_hit_record *rec);
t_bool		hit_triangle(t_ray *r, t_object *obj, t_hit_record *rec);
t_bool		hit_cylinder(t_ray *r, t_object *obj, t_hit_record *rec);
t_bool		check_tr(t_vec a, t_vec b, t_vec c, t_vec h);
t_bool		is_inside(t_point p1, t_point p2, t_point p3, t_point p);

int			key_hook(int keycode, t_vars *vars);
int			exit_hook(void);

t_scene		*scene_init(char *argv, int w, int h);

void		parse(char *argv, t_scene *scene);
void		check_file(char *str, t_scene *scene, int flag);

void		parse_r(char **words, t_scene *scene);
void		parse_a(char **words, t_scene *scene);
void		parse_l(char **words, t_scene *scene);
void		parse_c(char **words, t_scene *scene, int flag);
void		parse_cy(char **words, t_scene *scene);
void		parse_tr(char **words, t_scene *scene);
void		parse_sp(char **words, t_scene *scene);
void		parse_sq(char **words, t_scene *scene);
void		parse_pl(char **words, t_scene *scene);

t_canvas	canvas(int	width, int height);
t_camera	*camera(t_canvas canvas, t_point orig, t_vec nor, double fov);
t_object	*cam_onext(t_object *list);

t_sphere	*sphere(t_point center, double radius, t_color color);
t_plane		*plane(t_point point, t_vec normal, t_color color);
t_triangle	*triangle(t_point p1, t_point p2, t_point p3, t_color color);
t_square	*square(t_point point, t_vec normal, double len, t_color color);
t_cylinder	*cylinder(t_point point, t_vec normal, double *num, t_color color);

t_object	*object(t_object_type type, void *element);
void		oadd(t_object **list, t_object *new);
t_object	*olast(t_object *list);
t_light		*light_point(t_point l_org, t_color l_color, double bright_ratio);
void		obj_add_back(t_object **list, t_object *new);

void		ft_error(char *s);
void		check_color(char **tmp);
void		check_three_nor(char **tmp);
void		double_free(char **str);
int			len_spl(char **str);
void		set_face_normal(t_ray *r, t_hit_record *rec);
void		check_zero_to_one(char **tmp);
int			check_max_w(t_scene *scene, int a);
int			check_max_h(t_scene *scene, int b);

int			i_atoi(const char *str);
int			ft_atoi(const char *str);
double		ft_power(double a, int b);
double		ft_atof(const char *str);

t_data		print_image(t_vars *vars);
int			write_color(int t, t_color *pixel_color);
void		check_window_size(t_vars *vars);
void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
t_bool		check_rt(char *s);

void		save_image(t_scene *scene);
t_bmp		set_bmp_h(t_scene *scene);

#endif
