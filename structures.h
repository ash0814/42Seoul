/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehyan <sehyan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 01:51:53 by ash               #+#    #+#             */
/*   Updated: 2021/05/23 12:44:51 by sehyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

# include "minirt.h"

# define SP 0
# define PLN 1
# define TRI 2
# define SQU 3
# define CYL 4
# define FALSE 0
# define TRUE 1
# define LIGHT_POINT 5
# define CAM 6
# define EPSILON 1e-6

typedef int		t_bool;
typedef struct	s_vec t_vec;
typedef struct	s_vec t_color;
typedef struct	s_vec t_point;
typedef int		t_object_type;


struct	s_vec
{
	double x;
	double y;
	double z;
};

typedef struct	s_ray
{
	t_point	origin;
	t_vec	dir;
}				t_ray;

typedef struct s_data
{
	void 	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct	s_object
{
	t_object_type	type;
	void			*element;
	void			*next;
}				t_object;

typedef struct		s_camera
{
    t_point			org;
    double			viewport_h;
    double			viewport_w;
    t_vec			hrzt;
    t_vec			vrtc;
    double			focal_len;
    t_point			left_bottom;
	double			fov;
	t_vec			normal;
	t_data			image;
}               	t_camera;

typedef struct		s_light
{
	t_point		origin;
	t_color		light_color;
	double		bright_ratio;
}					t_light;

typedef struct s_canvas
{
    int     width;
    int     height;
    double  aspect_ratio;
}               t_canvas;

typedef struct	s_hit_record
{
	t_point		p;	//교점의 좌표
	t_vec		normal;	//교점에서의 법선
	double		tmin;
	double		tmax;
	double		t;
	t_bool		front_face;
	t_color		albedo;
	double		t2;
}				t_hit_record;

typedef struct	s_scene
{
	t_canvas		canvas;
	t_object		*camera;
	t_object		*world;
	t_object		*light;
	t_color			ambient; // 8.4에서 설명할 요소
	t_ray			ray;
	t_hit_record	rec;
	t_object		*head_cam;
	int				h;
	int				w;
}				t_scene;

typedef struct	s_vars 
{
	void		*mlx;
	void		*win;
	t_scene		*scene;
}				t_vars;

typedef struct	s_sphere
{
	t_point		center;
	double		radius;
	double		radius2;
	t_color		color;
}				t_sphere;

typedef struct s_plane
{
	t_point		point;
	t_vec		normal;
	t_color		color;
}				t_plane;

typedef struct	s_square
{
	t_point		point;
	t_vec		normal;
	double		len;
	t_color		color;
}				t_square;

typedef struct s_triangle
{
	t_point		p1;
	t_point		p2;
	t_point		p3;
	t_vec		normal;
	t_color		color;
}				t_triangle;

typedef struct s_cylinder
{
	t_point		point;
	t_vec		normal;
	double		radius;
	double		height;
	t_color		color;
}				t_cylinder;

# pragma pack(push, 1)

typedef	struct	s_color2
{
	unsigned char	z;
	unsigned char	y;
	unsigned char	x;
}				t_color2;

typedef	struct	s_fileheader
{
	unsigned char	sign1;
	unsigned char	sign2;
	unsigned int	file_size;
	unsigned short	reserved1;
	unsigned short	reserved2;
	unsigned int	start_bmp;
}				t_fileheader;

typedef	struct	s_infoheader
{
	unsigned int	size;
	unsigned int	width;
	unsigned int	height;
	unsigned short	planes;
	unsigned short	bitcount;
	unsigned int	compression;
	unsigned int	sizeimage;
	unsigned int	x_pelspermeter;
	unsigned int	y_pelspermeter;
	unsigned int	color_used;
	unsigned int	color_important;
}				t_infoheader;

typedef	struct	s_bmp
{
	t_fileheader	file_h;
	t_infoheader	info_h;
}				t_bmp;

# pragma pack(pop)

#endif