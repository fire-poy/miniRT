/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpons <mpons@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 16:50:52 by mpons             #+#    #+#             */
/*   Updated: 2022/09/30 20:19:25 by mpons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	check_arg(const char *scene)
{
	if (ft_strlen(scene) < 4 || (!ft_strchr(scene, '.')))
		print_error_exit("Error\nArgument invalid", 0, 1);
	if (ft_strcmp(ft_strrchr(scene, '.'), ".rt") != 0)
		print_error_exit("Error\nType de scene invalide (.rt)", 0, 1);
}

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
	if (q_obj->pl > 0)
		set->plan_list = ft_calloc(q_obj->pl + 1, sizeof(t_plan));
	if (q_obj->cy > 0)
		set->cyl_list = ft_calloc(q_obj->cy + 1, sizeof(t_cyl));
}

t_q_obj	parsing(char *scene_file, t_set *set)
{
	t_q_obj	q_obj;

	check_arg(scene_file);
	q_obj = init_q_objs();
	check_scene(scene_file, &q_obj);
	calloc_scene_obj(set, &q_obj);
	get_scene(scene_file, set);
	return (q_obj);
}
