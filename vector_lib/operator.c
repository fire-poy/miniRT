/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slott <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 15:26:53 by slott             #+#    #+#             */
/*   Updated: 2022/08/29 18:57:06 by slott            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "vector.h"

t_vect	plus(int n, ...)
{
	t_vect	next;
	t_vect	final;
	va_list	ptr;
	int		i;

	i = 0;
	final = init_vec(0, 0, 0);
	va_start(ptr, n);
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

t_vect	moins(int n, ...)
{
	t_vect	final;
	t_vect	next;
	va_list	ptr;
	int	i;

	i = 0;
	final = init_vec(0, 0, 0);
	va_start(ptr, n);
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

t_vect	fois(int n, ...)
{
	t_vect	final;
	t_vect	next;
	va_list	ptr;
	int		i;

	i = 0;
	final = init_vec(0, 0, 0);
	va_start(ptr, n);
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

t_vect	divis(int n, ...)
{
	t_vect	final;
	t_vect	next;
	va_list	ptr;
	int		i;

	i = 0;
	final = init_vec(0, 0, 0);
	va_start(ptr, n);
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
