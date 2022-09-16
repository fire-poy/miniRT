/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_closest.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpons <mpons@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 15:46:21 by slott             #+#    #+#             */
/*   Updated: 2022/09/16 23:11:12 by mpons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRt.h"

void	get_closest_sp(t_set *set, t_ray r)
{
	int		i;
	float	t;

	i = 0;
	while (set->sp_list[i].r != 0)
	{
		t = hit_sp(set->sp_list[i], r);
		if (t < set->obj.dist && t > 0)
		{
			set->obj.dist = t;
			set->obj.idx = i;
			set->obj.type = SPHERE;
			set->obj.col = set->sp_list[i].rgb;
		}
		i++;
	}
}

t_obj	init_obj(void)
{
	t_obj	obj;
	
	obj.col = init_vec(0, 0, 0);
	obj.dist = 1e+14;
	obj.idx = -1;
	obj.type = -1;
	return (obj);
}

// doit rendre le type d'objet et l'index
// arbre de if (type == SPHERE) -> draw_sphere
int	get_closest(t_set *set, t_ray r)
{
	int	i;

	i = 0;
	set->obj = init_obj();
	get_closest_sp(set, r);
	// get_closest_plane(set, r); 
	// get_closest_cyl(set, r);
	if (set->obj.type == -1)
		return (-1);
	return (0);
}

t_vect	color_x(t_set *set, t_ray r)
{
	t_vect	col;
	t_vect	v1;

	if (get_closest(set, r) != -1)
	{
		if (set->obj.type == SPHERE)
			v1 = point_at(r, hit_sp(set->sp_list[set->obj.idx], r));
		// else if (set->obj.type == PLAN)
		// 	v1 = point_at(r, hit_plane(set->sp_list[set->obj.idx], r));
		// else if (set->obj.type == CYLINDRE)
		// 	v1 = point_at(r, hit_cylindre(set->sp_list[set->obj.idx], r));
		else
			v1 = init_vec(0, 0, 0);
		col = blend_light(set, v1, set->obj.col);
		return (col);
	}
	col = fois_x(set->ambiant.rgb, set->ambiant.light);
	return (col);
}
