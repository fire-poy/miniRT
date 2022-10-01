/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_var_obj.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpons <mpons@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 11:36:31 by mpons             #+#    #+#             */
/*   Updated: 2022/10/01 14:08:03 by mpons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "../libft/libft.h"

void	get_sphere(t_set *set, char **obj_info)
{
	static int	i = 0;

	set->sp_list[i].c = get_vector_from_string(obj_info[1]);
	set->sp_list[i].r = atof(obj_info[2]) / 2.0f;
	set->sp_list[i].rgb = get_vector_from_string(obj_info[3]);
	i++;
}

void	get_plane(t_set *set, char **obj_info)
{
	static int	i = 0;

	set->plan_list[i].pos = get_vector_from_string(obj_info[1]);
	set->plan_list[i].dir = get_vector_from_string(obj_info[2]);
	set->plan_list[i].rgb = get_vector_from_string(obj_info[3]);
	i++;
}

// normalize
void	get_cyl_centers(t_cyl *cyl)
{
	cyl->top_center = fois_x(unit_vector(cyl->dir), cyl->len * 0.5);
	printf("cyl->top_center \n");
	// print_vec(cyl->top_center);
	cyl->top_center = plus(2, cyl->top_center, cyl->pos);
	print_vec(cyl->top_center);
	cyl->bot_center = fois_x(unit_vector(cyl->dir), cyl->len * -0.5);
	printf("cyl->bot_center \n");
	// print_vec(cyl->bot_center);
	cyl->bot_center = plus(2, cyl->bot_center, cyl->pos);
	print_vec(cyl->bot_center);
}

void	get_cylindre(t_set *set, char **obj_info)
{
	static int	i = 0;
	float	d = 0;

	set->cyl_list[i].pos = get_vector_from_string(obj_info[1]);
	set->cyl_list[i].dir = get_vector_from_string(obj_info[2]);
	set->cyl_list[i].r = atof(obj_info[3]) / 2.0f;
	set->cyl_list[i].len = atof(obj_info[4]);
	set->cyl_list[i].rgb = get_vector_from_string(obj_info[5]);
	get_cyl_centers(&set->cyl_list[i]);
	d = vector_distance(set->cyl_list[i].top_center , set->cyl_list[i].bot_center);
	printf("dist bot top = %f", d);
	i++;
}
