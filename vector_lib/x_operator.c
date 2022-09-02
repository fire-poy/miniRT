/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   e_operator.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slott <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 14:23:09 by slott             #+#    #+#             */
/*   Updated: 2022/09/01 16:15:53 by slott            ###   ########.fr       */
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
