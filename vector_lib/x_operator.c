/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_operator.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpons <mpons@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 14:23:09 by slott             #+#    #+#             */
/*   Updated: 2022/10/01 16:20:27 by mpons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

// Ajoute 't' a chaque valeur de v1
t_vect	plus_x(t_vect v1, float t)
{
	t_vect	final;

	final.x = v1.x + t;
	final.y = v1.y + t;
	final.z = v1.z + t;
	return (final);
}

// Enleve 't' a chaque valeur de v1
t_vect	moins_x(t_vect v1, float t)
{
	t_vect	final;

	final.x = v1.x - t;
	final.y = v1.y - t;
	final.z = v1.z - t;
	return (final);
}

// Multiplie par 't' chaque valeur de v1
t_vect	fois_x(t_vect v1, float t)
{
	t_vect	final;

	final.x = v1.x * t;
	final.y = v1.y * t;
	final.z = v1.z * t;
	return (final);
}

// Divise par 't' chaque valeur de v1
t_vect	divis_x(t_vect v1, float t)
{
	t_vect	final;

	final.x = v1.x / t;
	final.y = v1.y / t;
	final.z = v1.z / t;
	return (final);
}

t_vect	invert_vector(t_vect v)
{
	t_vect	r;

	r = fois_x(v, -1);
	return (r);
}
