/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpons <mpons@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 11:36:31 by mpons             #+#    #+#             */
/*   Updated: 2022/09/09 19:05:31 by mpons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	check_coordonees(char **obj_info, char *vector, int l_nb)
{
	char	**tab_coord;
	int		i;

	if (ft_words_set(vector, ",") != 3)
		free_and_error(obj_info, NULL, ERR_COORD, l_nb);
	tab_coord = ft_split(vector, ',');
	i = -1;
	while (tab_coord[++i])
	{
		if (!ft_is_it_float(tab_coord[i]))
			free_and_error(obj_info, tab_coord, ERR_FORMAT_N, l_nb);
	}
	free_tab(tab_coord);
}

void	check_vector_orientation(char **obj_info, char *vector, int l_nb)
{
	char	**tab_coord;
	int		i;

	if (ft_words_set(vector, ",") != 3)
		free_and_error(obj_info, NULL, ERR_COORD, l_nb);
	tab_coord = ft_split(vector, ',');
	i = -1;
	while (tab_coord[++i])
	{
		if (!ft_is_it_float(tab_coord[i])
			|| !is_in_range(ft_atof(tab_coord[i]), -1.0f, 1.0f))
			free_and_error(obj_info, tab_coord, ERR_F_R_N, l_nb);
	}
	free_tab(tab_coord);
}

void	check_fov(char **obj_info, char *fov, int l_nb)
{
	if (!ft_is_it_int(fov))
		free_and_error(obj_info, NULL, "Error\nInt attendu", l_nb);
	if (ft_atoi(fov) < 0 || ft_atoi(fov) > 180)
		free_and_error(obj_info, NULL, "Error\nFOV dehors range [0,180]", l_nb);
}

void	check_camera(char **obj_info, int *q_c, int l_nb)
{
	if (ft_tab_len(obj_info) != 4)
		free_and_error(obj_info, NULL, ERR_TYPE, l_nb);
	(*q_c)++;
	if (*q_c > 1)
		free_and_error(obj_info, NULL, "Error\n1 Camera maximum", l_nb);
	check_coordonees(obj_info, obj_info[1], l_nb);
	check_vector_orientation(obj_info, obj_info[2], l_nb);
	check_fov(obj_info, obj_info[3], l_nb);
}
