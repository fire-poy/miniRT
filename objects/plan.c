/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plan.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpons <mpons@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 15:52:36 by mpons             #+#    #+#             */
/*   Updated: 2022/09/30 21:56:02 by mpons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRt.h"

t_vect    invert_vector(t_vect v)
{
	t_vect	r;
	
	r = fois_x(v, -1); 
	return (r);
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
