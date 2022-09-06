/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpons <mpons@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 16:50:52 by mpons             #+#    #+#             */
/*   Updated: 2022/09/06 15:06:39 by mpons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_q_obj	init_q_objs(void)
{
	t_q_obj	q_obj;

	q_obj.a = 0;
	q_obj.c = 0;
	q_obj.l = 0;
	q_obj.sp = 0;
	q_obj.pl = 0;
	q_obj.cy = 0;
	return (q_obj);
}

void	calloc_scene_obj(t_set *set, t_q_obj *q_obj)
{
	if (q_obj->sp > 0)
		set->sp_list = ft_calloc(q_obj->sp + 1, sizeof(t_sp));
	// if (!sp_list)
	// 	print_error_exit("error malloc scene");
	if (q_obj->pl > 0)
		set->plan_list = ft_calloc(q_obj->pl + 1, sizeof(t_plan));
	if (q_obj->cy > 0)
		set->cyl_list = ft_calloc(q_obj->cy + 1, sizeof(t_cyl));
}

// print_obj(&q_obj);
void	parsing(char *scene_file, t_set *set)
{
	t_q_obj	q_obj;

	check_arg(scene_file);
	q_obj = init_q_objs();
	check_scene(scene_file, &q_obj);
	calloc_scene_obj(set, &q_obj);
	get_scene(scene_file, set);
}
