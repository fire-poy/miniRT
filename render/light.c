/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpons <mpons@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 13:28:54 by slott             #+#    #+#             */
/*   Updated: 2022/09/16 21:53:55 by mpons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRt.h"

// t_vect	is_in_light(t_set *set, t_vect p, t_vect o_col)
// {
// 	t_ray	r;
// 	t_vect	col;
// 	t_sp	sp;

// 	r.pos = p;
// 	r.dir = moins (2, set->light.pos, p);
// 	sp = get_closest_sp(set, r, set->current_id, 1);
// 	if (sp.r != 0)
// 	{
// 		col = divis_x(o_col, 2);
// 		return (col);
// 	}
// 	else
// 	{
// 		col = divis_x(plus(2, o_col, fois_x(o_col, set->light.light)), 2);
// 		return (col);
// 	}
// }

t_vect	is_in_light_x(t_set *set, t_vect p, t_vect o_col)
{
	t_ray	r;
	t_vect	col;

	r.pos = p;
	r.dir = moins (2, set->light.pos, p);
	if (get_closest(set, r) != -1)
	{
		col = divis_x(o_col, 2);
		return (col);
	}
	else
	{
		col = divis_x(plus(2, o_col, fois_x(o_col, set->light.light)), 2);
		return (col);
	}
}

t_vect	blend_light(t_set *set, t_vect p, t_vect o_col)
{
	t_vect	col;
	t_vect	amb_l;

	col = is_in_light_x(set, p, o_col);
	amb_l = fois_x(set->ambiant.rgb, set->ambiant.light);
	col = plus(2, col, amb_l);
	col = divis_x(col, 2);
	return (col);
}	
