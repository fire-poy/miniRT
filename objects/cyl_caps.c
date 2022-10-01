/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cyl_caps.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpons <mpons@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 22:16:08 by mpons             #+#    #+#             */
/*   Updated: 2022/10/01 16:50:09 by mpons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRt.h"

int	inside_cyl_cap(t_set *set, t_cyl cyl, t_vect pl_center, t_ray r)
{
	float	d_to_center;

	d_to_center = vector_distance(point_at(r, r.t), pl_center);
	if (d_to_center <= cyl.r)
	{			
		set->obj.dist = r.t;
		if (dot(cyl.dir, r.dir) > 0)
			set->normal = invert_vector(cyl.dir);
		else
			set->normal = cyl.dir;
		return (1);
	}
	return (0);
}

int	check_cap(t_set *set, t_cyl cyl, t_vect cap_pos, t_ray r)
{
	t_vect		polo;
	float		denom;
	float		t;

	denom = dot(r.dir, cyl.dir);
	if (denom != 0)
	{
		polo = moins(2, cap_pos, r.pos);
		t = dot(polo, cyl.dir) / denom;
		if (t < set->obj.dist && t > 0)
		{
			r.t = t;
			if (inside_cyl_cap(set, cyl, cap_pos, r))
				return (1);
		}
	}
	return (0);
}
