/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpons <mpons@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 13:28:54 by slott             #+#    #+#             */
/*   Updated: 2022/09/23 16:59:32 by mpons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRt.h"

int	is_in_light(t_set *set, t_vect p)
{
	t_ray	r;

	r.pos = p;
	r.dir = moins (2, set->light.pos, p);
	r.pos = point_at(r, 0.0001);
	if (get_closest(set, r, 1) != -1)
		return (0);
	else
		return (1);
}

t_vect	reflect(t_vect l_dir, t_vect norm)
{
	t_vect	reflect;

	reflect = fois_x(norm, 2 * dot(l_dir, norm));
	reflect = moins(2, reflect, l_dir);
	return (reflect);
}

t_vect	phong(t_set *set, t_vect p, t_vect o_col)
{
	t_vect	ambiant;
	t_vect	diffuse;
	t_vect	specular;
	t_vect	col;
	t_vect	i_s;
	t_vect	L;
	t_vect	R;
	t_vect	V;
	float	k_s;
	float	dotLN;
	float	dotRV;
	float	alpha;

	col = divis_x(plus(2, o_col, set->ambiant.rgb), 2);
	ambiant = fois_x(col_scaled(col), set->ambiant.light);
	L = unit_vector(moins(2, set->light.pos, p));
	dotLN = dot(L, set->normal);
	dotLN = clamp(dotLN, 0.0, 1.0);
	diffuse = fois_x(col_scaled(o_col), set->light.light * dotLN);
	k_s = 0.6;
	R = reflect(L, set->normal);
	V = unit_vector(moins(2, set->cam.pos, p));
	dotRV = dot(R, V);
	i_s = init_vec(1, 1, 1);
	alpha = 10.0;
	specular = fois_x(i_s, k_s * pow(dotRV, alpha));
	// col = ranged(plus(2, ambiant, diffuse));
	col = ranged(plus(3, ambiant, diffuse, specular));
	return (col);
}

t_vect	blend_light(t_set *set, t_vect p)
{
	t_vect	col;
	t_vect	o_col;

	o_col = set->obj.col;
	if (is_in_light(set, p))
		col = phong(set, p, o_col);
	else
	{
		col = divis_x(plus(2, o_col, set->ambiant.rgb), 2);
		col = fois_x(col_scaled(col), set->ambiant.light);
	}
	return (col);
}	
