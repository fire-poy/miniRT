#include "../miniRt.h"

// Calcule si un rayon "ray" traverse ou non la sphere "sp"git 
// Renvoie la ou les valeurs 't' pour lesquels le rayon touche la sphere
// float	hit_cyl(t_cyl cyl, t_ray ray)
// {
// 	t_equation	eq;

// 	eq.oc = moins(2, ray.pos, cyl.c);
// 	eq.a = dot(ray.dir, ray.dir);
// 	eq.b = 2.0 * dot(ray.dir, eq.oc);
// 	eq.c = dot(eq.oc, eq.oc) - (cyl.r * cyl.r);
// 	eq.delta = (eq.b * eq.b) - (4.0 * eq.a * eq.c);
// 	if (eq.delta < 0)
// 		return (0);
// 	else
// 	{
// 		eq.t = (-eq.b - sqrt(eq.delta)) / (2 * eq.a);
// 		if (eq.t <= 0)
// 			eq.t = (-eq.b + sqrt(eq.delta)) / (2 * eq.a);
// 		return (eq.t);
// 	}
// }
