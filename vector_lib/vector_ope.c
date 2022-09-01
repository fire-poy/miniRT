/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_ope.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slott <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 14:49:18 by slott             #+#    #+#             */
/*   Updated: 2022/09/01 16:17:10 by slott            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "vector.h"

// Renvoie la "longeur" du vecteur

float	length(t_vect v)
{
	float	length;

	length = sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
	return (length);
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
