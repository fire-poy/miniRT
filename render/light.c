/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slott <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 13:28:54 by slott             #+#    #+#             */
/*   Updated: 2022/09/14 14:08:56 by slott            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRt.h"

t_vect	is_in_light(t_set *set, t_vect p, t_vect o_col)
{
	t_ray	r;
	t_vect	col;
	t_sp	sp;

	r.pos = p;
	r.dir = moins (2, set->light.pos, p);
	sp = get_closest_sp(set, r, set->current_id, 1);
	if (sp.r != 0)
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

// Exclure la sphere touchee de la liste du second rayon
