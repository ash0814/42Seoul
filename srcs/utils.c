/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ash <ash@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 16:26:38 by ash               #+#    #+#             */
/*   Updated: 2021/05/18 00:32:13 by ash              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

void    ft_error(char *s)
{
    write(1, "ERROR : ", 8);
    perror(s);
    exit(1);
}

void    double_free(char **str)
{
    int i;
    int h;
    
    i = 0;
    h = ft_len_2D;
    while (i < h)
    {
        free(str[i]);
        i++;        
    }
    free(str);
}

int     ft_len_2D(char **str)
{
    int h;

    h = 0;
    while (str[h][0])
        h++;
    return (h);
}

void	set_face_normal(t_ray *r, t_hit_record *rec)
{
	// 광선의 방향벡터와 교점의 법선벡터의 내적이 음수이면 광선은 앞면(객체의)에 hit 한 것이다
	rec->front_face = v_dot(r->dir, rec->normal) < 0;
	// 광선의 앞면에 hit 면 그대로 아니면 법선을 반대로 뒤집는다. (항상 광선 방향벡터와 법선 벡터를 반대인 상태로 사용하기위해)
	rec->normal = (rec->front_face) ? rec->normal : vt_mul(rec->normal, -1);
}