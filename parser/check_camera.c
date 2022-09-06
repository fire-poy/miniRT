/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpons <mpons@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 11:36:31 by mpons             #+#    #+#             */
/*   Updated: 2022/09/05 15:35:18 by mpons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "../libft/libft.h"

int	ft_is_it_int(char *s)
{
	int	i;
	int	j;
	int	point;

	i = 0;
	j = 0;
	point = 0;
	while (ft_is_it_white_space(s[i]))
		i++;
	if (s[i] == '-' || s[i] == '+')
		i++;
	while(ft_isdigit(s[i]))
		i++;
	if (s[i] == '\0' || ft_is_it_white_space(s[i]))
		return (1);
	else
		return (0);
}

// void	check_format_vect(char **obj_info, char *coordonnées, int l_nb)
void	check_coordonees(char **obj_info, char *vector, int l_nb)
{
	char	**tab_coord;
	int		i;
	
	// if (ft_tab_len(tab_coord) != 3)
	if (ft_words_set(vector, ",") != 3)
	{
		free_tab(obj_info);
		print_error_exit("Error\nIl faut 3 infos pour les coordonnées [x,y,z]", l_nb, 1);
	}
	tab_coord = ft_split(vector, ',');
	i = -1;
	while (tab_coord[++i])
	{
		if (!ft_is_it_float(tab_coord[i]))
		{
			free_tab(obj_info);
			free_tab(tab_coord);
			print_error_exit("Error\nFormat numero incorrect", l_nb, 1);
		}
	}
	free_tab(tab_coord);
}

//faire avec int 1 -1??
void	check_vector_orientation(char **obj_info, char *vector, int l_nb)
{
	char	**tab_coord;
	int		i;
	
	// if (ft_tab_len(tab_coord) != 3)
	if (ft_words_set(vector, ",") != 3)
	{
		free_tab(obj_info);
		print_error_exit("Error\nIl faut 3 infos pour les coordonnées [x,y,z]", l_nb, 1);
	}
	tab_coord = ft_split(vector, ',');
	i = -1;
	while (tab_coord[++i])
	{
		if (!ft_is_it_float(tab_coord[i]) || !is_in_range(ft_atof(tab_coord[i]), -1.0f, 1.0f))//
		{
			free_tab(obj_info);
			free_tab(tab_coord);
			print_error_exit("Error\nFormat ou range numero incorrect", l_nb, 1);
		}
	}
	free_tab(tab_coord);
}



void	check_fov(char **obj_info, char *fov, int l_nb)
{
	if (!ft_is_it_int(fov))
	{
		free_tab(obj_info);
		print_error_exit("Error\nInt attendu", l_nb, 1);
	}
	if (ft_atoi(fov) < 0 || ft_atoi(fov) > 180)
	{
		free_tab(obj_info);
		print_error_exit("Error\nFOV dehors range [0,180]", l_nb, 1);
	}
}

void	check_camera(char **obj_info, int *q_c, int l_nb)
{
	if (ft_tab_len(obj_info) != 4)
	{
		free_tab(obj_info);
		print_error_exit("Error\nQuantité des informations ne correspondent pas au type d'objet",l_nb, 1);
	}
	(*q_c)++;
	if (*q_c > 1)// (*q_c)?
		print_error_exit("Error\n1 Camera maximum", l_nb, 1);
	check_coordonees(obj_info, obj_info[1], l_nb);
	check_vector_orientation(obj_info, obj_info[2], l_nb);
	check_fov(obj_info, obj_info[3], l_nb);
}
