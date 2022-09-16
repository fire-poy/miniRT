/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plan.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpons <mpons@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 15:52:36 by mpons             #+#    #+#             */
/*   Updated: 2022/09/16 21:43:37 by mpons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRt.h"

// int	inter_plane(t_ray d, t_plane plane, t_ret_ray *ret)
// {
//     double        a;
//     double        t;
//     t_vector    oc;
//     t_vector    plane_ori_norm;
//     t_vector    plane_pos_norm;

//     plane_pos_norm = plane.pos;
//     normalize(&plane_pos_norm);
//     plane_ori_norm = plane.orientation;
//     normalize(&plane_ori_norm);
//     a = op_dot(d.d, plane_ori_norm);
//     if (a != 0.0)
//     {
//         oc = op_minus(plane.pos, d.o);
//         t = op_dot(oc, plane_ori_norm) / a;
//         if (t > 0.0)
//         {
//             ret->t = t;
//             ret->p = op_plus(d.o, op_mult(ret->t, d.d));
//              ret->n = plane.orientation;
//            return (1);
//         }
//     }
//     return (0);
// } 

// Calcule si un rayon "ray" traverse ou non la sphere "sp"
// Renvoie la ou les valeurs 't' pour lesquels le rayon touche la sphere
// typedef struct s_plan
// {
// 	t_vect	pos;
// 	t_vect	dir;
// 	t_vect	rgb;
// }					t_plan;

// float	hit_plan(t_set *set, t_plan pl, t_ray ray)
// {
// 	t_vect		po = pl.pos;
// 	t_vect		n = pl.dir;
// 	t_vect		lo;//pos camera
// 	t_vect		l; //set->cam.dir ->vector unitaire por direc de pixel
// 	t_vect		polo;
// 	float		denom;
// 	float		t;

// 	lo = set->cam.pos;
// 	l = unit_vector(ray.dir);
// 	// l = set->cam.dir;
// 	denom = dot(n, l);
// 	if (denom > 1e-6)
// 	//when the denominator is lower than a very small value 
// 	//we return false (no intersection was found)
// 	{ 
// 		polo = moins(2, po,lo);
//         t = dot(polo, n) / denom; 
// 		if (t >= 0)
// 		{
// 			// ft_putendl_fd("patate\n", 1);
// 			return (t);
// 		}
// 		else
// 			return (-1);
//     } 
// 	return (-1);
// } 

// t_vect	color2(t_set *set, t_ray r)
// {
// 	t_vect	col;
// 	t_vect	v1;
// 	t_sp	sp;
// 	float	t;
	
// 	t = hit_plan(set, set->plan_list[0], r);
// 	if (t != -1)
// 	{
// 		v1 = point_at(r, t);
// 		col = blend_light(set, v1, sp.rgb);
// 		return (col);
// 	}
// 	col = fois_x(set->ambiant.rgb, set->ambiant.light);
// 	return (col);
// }
