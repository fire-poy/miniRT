/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_lumiere_amb.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpons <mpons@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 14:39:00 by mpons             #+#    #+#             */
/*   Updated: 2022/09/06 15:23:26 by mpons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	is_it_empty_line(char **line, int fd)
{
	if (*line[0] == '\n')
	{
		free(*line);
		*line = get_next_line(fd);
		return (1);
	}
	return (0);
}

int	is_in_range(float n, float min, float max)
{
	if (n < min || n > max)
		return (0);
	return (1);
}

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
	{
		free_tab(obj_info);
		print_error_exit("Error\nNumero n'est pas un float", l_nb, 1);
	}
	n = atof(lumnosite);
	if (!is_in_range(n, 0.0f, 1.0f))
		print_error_exit("Error\nFloat dehors range [0.0,1.0]", l_nb, 1);
}

void	check_lumiere_ambiente(char **obj_info, int *q_a, int l_nb)
{
	if (ft_tab_len(obj_info) != 3)
	{
		free_tab(obj_info);
		print_error_exit(ERR_TYPE, l_nb, 1);
	}
	(*q_a)++;
	if (*q_a > 1)
		print_error_exit("Error\n1 Lumière ambiente maximum", l_nb, 1);
	check_lumnosite(obj_info, obj_info[1], l_nb);
	check_colors(obj_info, obj_info[2], l_nb);
}
