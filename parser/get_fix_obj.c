/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_fix_obj.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpons <mpons@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 14:39:00 by mpons             #+#    #+#             */
/*   Updated: 2022/10/03 12:44:19 by mpons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_vect	get_vector_from_string(char *vector)
{
	char	**tab;
	t_vect	v;

	tab = ft_split(vector, ',');
	v = init_vec(atof(tab[0]), atof(tab[1]), atof(tab[2]));
	free_tab(tab);
	return (v);
}

void	get_lumiere_ambiente(t_set *set, char **obj_info)
{
	set->ambiant.light = atof(obj_info[1]);
	set->ambiant.rgb = get_vector_from_string(obj_info[2]);
}

void	get_camera(t_set *set, char **obj_info)
{
	set->cam.pos = get_vector_from_string(obj_info[1]);
	set->cam.dir = get_vector_from_string(obj_info[2]);
	set->cam.dir = invert_vector(set->cam.dir);
	set->cam.fov = ft_atoi(obj_info[3]);
	fov(set);
}

void	get_lumiere(t_set *set, char **obj_info)
{
	set->light.pos = get_vector_from_string(obj_info[1]);
	set->light.light = atof(obj_info[2]);
}
