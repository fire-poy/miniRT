/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpons <mpons@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 15:26:53 by slott             #+#    #+#             */
/*   Updated: 2022/09/14 14:17:26 by slott            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

// Additionne n vecteurs entre eux
t_vect	plus(int n, ...)
{
	t_vect	next;
	t_vect	final;
	va_list	ptr;
	int		i;

	i = 1;
	va_start(ptr, n);
	final = va_arg(ptr, t_vect);
	while (i < n)
	{
		next = va_arg(ptr, t_vect);
		final.x += next.x;
		final.y += next.y;
		final.z += next.z;
		i++;
	}
	va_end(ptr);
	return (final);
}

// Soustrais n vecteur entre eux
t_vect	moins(int n, ...)
{
	t_vect	final;
	t_vect	next;
	va_list	ptr;
	int		i;

	i = 1;
	va_start(ptr, n);
	final = va_arg(ptr, t_vect);
	while (i < n)
	{
		next = va_arg(ptr, t_vect);
		final.x -= next.x;
		final.y -= next.y;
		final.z -= next.z;
		i++;
	}
	va_end(ptr);
	return (final);
}

// Multiplie n vecteurs entre eux
t_vect	fois(int n, ...)
{
	t_vect	final;
	t_vect	next;
	va_list	ptr;
	int		i;

	i = 1;
	va_start(ptr, n);
	final = va_arg(ptr, t_vect);
	while (i < n)
	{
		next = va_arg(ptr, t_vect);
		final.x *= next.x;
		final.y *= next.y;
		final.z *= next.z;
		i++;
	}
	va_end(ptr);
	return (final);
}

// Divise n vecteur entre eux
t_vect	divis(int n, ...)
{
	t_vect	final;
	t_vect	next;
	va_list	ptr;
	int		i;

	i = 1;
	va_start(ptr, n);
	final = va_arg(ptr, t_vect);
	while (i < n)
	{
		next = va_arg(ptr, t_vect);
		final.x /= next.x;
		final.y /= next.y;
		final.z /= next.z;
		i++;
	}
	va_end(ptr);
	return (final);
}
