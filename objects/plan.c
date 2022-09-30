/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plan.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpons <mpons@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 15:52:36 by mpons             #+#    #+#             */
/*   Updated: 2022/09/30 20:40:26 by mpons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRt.h"

t_vect    invert_vector(t_vect v)
{
	v = fois_x(v, -1); 
	return (v);
}

float	hit_plan(t_plan pl, t_ray r)
{
	t_vect		polo;
	float		denom;
	float		t;

	denom = dot(r.dir, pl.dir);
	if (denom != 0)
	{ 
		polo = moins(2, pl.pos,r.pos);
        t = dot(polo, pl.dir) / denom; 
		if (t > 0.0)
			return (t);
    } 
	return (-1);
}
