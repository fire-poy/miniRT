/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpons <mpons@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 13:28:54 by slott             #+#    #+#             */
/*   Updated: 2022/10/01 16:44:32 by mpons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRt.h"

int	is_in_light(t_set *set, t_vect p)
{
	t_ray	r;

	r.pos = p;
	r.dir = moins (2, set->light.pos, p);
	r.pos = point_at(r, 0.001);
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
	t_phong	ph;

	ph.col = divis_x(plus(2, o_col, set->ambiant.rgb), 2);
	ph.ambiant = fois_x(col_scaled(ph.col), set->ambiant.light);
	ph.l = unit_vector(moins(2, set->light.pos, p));
	ph.dotln = dot(ph.l, set->normal);
	ph.dotln = clamp(ph.dotln, 0.0, 1.0);
	ph.diffuse = fois_x(col_scaled(o_col), set->light.light * ph.dotln);
	ph.k_s = 0.6;
	ph.r = reflect(ph.l, set->normal);
	ph.v = unit_vector(moins(2, set->cam.pos, p));
	ph.dotrv = dot(ph.r, ph.v);
	ph.i_s = init_vec(1, 1, 1);
	ph.alpha = 10.0;
	ph.specular = fois_x(ph.i_s, ph.k_s * pow(ph.dotrv, ph.alpha));
	ph.col = ranged(plus(3, ph.ambiant, ph.diffuse, ph.specular));
	return (ph.col);
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
