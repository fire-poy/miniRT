/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_lumiere_amb.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpons <mpons@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 14:39:00 by mpons             #+#    #+#             */
/*   Updated: 2022/09/09 18:57:53 by mpons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	check_colors(char **obj_info, char *color, int l_nb)
{
	char	**tab_col;
	int		i;

	tab_col = ft_split(color, ',');
	if (ft_tab_len(tab_col) != 3)
		free_and_error(obj_info, tab_col, ERR_COLOR, l_nb);
	i = -1;
	while (tab_col[++i])
	{
		if (!ft_is_it_float(tab_col[i]))
			free_and_error(obj_info, tab_col, ERR_COLOR_R, l_nb);
		if (!is_in_range(atof(tab_col[i]), 0.0f, 255.0f))
			free_and_error(obj_info, tab_col, ERR_COLOR_R2, l_nb);
	}
	free_tab(tab_col);
}

void	check_lumnosite(char **obj_info, char *lumnosite, int l_nb)
{
	float	n;

	if (ft_is_it_float(lumnosite) == 0)
		free_and_error(obj_info, NULL, ERR_FLOAT, l_nb);
	n = atof(lumnosite);
	if (!is_in_range(n, 0.0f, 1.0f))
		free_and_error(obj_info, NULL, ERR_FLOAT_RANGE, l_nb);
}

void	check_lumiere_ambiente(char **obj_info, int *q_a, int l_nb)
{
	if (ft_tab_len(obj_info) != 3)
		free_and_error(obj_info, NULL, ERR_TYPE, l_nb);
	(*q_a)++;
	if (*q_a > 1)
		free_and_error(obj_info, NULL, ERR_L_AMB_MAX, l_nb);
	check_lumnosite(obj_info, obj_info[1], l_nb);
	check_colors(obj_info, obj_info[2], l_nb);
}
