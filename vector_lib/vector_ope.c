/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_ope.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpons <mpons@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 14:49:18 by slott             #+#    #+#             */
/*   Updated: 2022/10/01 17:38:56 by mpons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRt.h"

// Renvoie la "longeur" du vecteur
float	length(t_vect v)
{
	float	length;

	length = sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
	return (length);
}

//Rendre la distance entre 2 vecteurs
float	vector_distance(t_vect a, t_vect b)
{
	t_vect	sust;
	float	dist;

	sust = moins(2, a, b);
	dist = length(sust);
	return (dist);
}

// Transforme un vecteur en vecteur unitaire
// Unitaire = avec des valeurs comprises entre 0 et 1
t_vect	unit_vector(t_vect v)
{
	return (divis_x(v, length(v)));
}

// Produit scalaire de 2 vecteurs
float	dot(t_vect v1, t_vect v2)
{
	float	res;

	res = v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
	return (res);
}

t_vect	cross(t_vect v1, t_vect v2)
{
	t_vect	res;

	res.x = v1.y * v2.z - v1.z * v2.y;
	res.y = -(v1.x * v2.z - v1.z * v2.x);
	res.z = v1.x * v2.y - v1.y * v2.x;
	return (res);
}
