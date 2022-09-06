/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_lumiere_amb.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpons <mpons@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 14:39:00 by mpons             #+#    #+#             */
/*   Updated: 2022/09/05 15:18:06 by mpons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	is_it_empty_line(char **line, int fd)
{
	if (*line[0] == '\n')// && *line[1] == '\0')
	{
		free(*line);
		*line = get_next_line(fd);
		return (1);
	}
	return (0);
}

int is_in_range(float n, float min, float max)
{
	if (n < min || n > max)
		return (0);
	return (1);
}

//?chercher dans obj_info [1 2 ou 3digit,3digit,3digit] si ce nest pas le cas error format
// if (!ft_is_digit(tab_col[i][j]))
void	check_colors(char **obj_info, char *color, int l_nb)
{
	char	**tab_col;
	int		i;
	float	n;
	
	tab_col = ft_split(color, ',');
	if (ft_tab_len(tab_col) != 3)
	{
		free_tab(obj_info);
		print_error_exit("Error\nIl faut 3 infos pour la couleur [R,G,B]", l_nb, 1);
	}
	i = -1;
	while (tab_col[++i])
	{
		if (!ft_is_it_float(tab_col[i]))
		{
			free_tab(obj_info);
			free_tab(tab_col);
			print_error_exit("Error\nCe n'est pas un numero [0,255]", l_nb, 1);
		}
		n = atof(tab_col[i]);
		if (!is_in_range(n, 0.0f, 255.0f))
		{
			free_tab(obj_info);
			free_tab(tab_col);
			print_error_exit("Error\nCouleurs R,G,B doivent être dans le range [0,255]", l_nb, 1);
		}								
	}
}

void	check_lumnosité(char **obj_info, char *lumnosité, int l_nb)
{
	float	n;

	if (ft_is_it_float(lumnosité) == 0)
	{
		free_tab(obj_info);
		print_error_exit("Error\nNumero n'est pas un float", l_nb, 1); //ajoute pointeur foncion sur free fonction
	}
	n = atof(lumnosité);
	if (!is_in_range(n, 0.0f, 1.0f))
		print_error_exit("Error\nFloat dehors range [0.0,1.0]", l_nb, 1); //ajoute pointeur foncion sur free fonction
}

void	check_lumiere_ambiente(char **obj_info, int *q_a, int l_nb)
{
	if (ft_tab_len(obj_info) != 3)
	{
		free_tab(obj_info);
		print_error_exit("Error\nQuantité des informations ne correspondent pas au type d'objet", l_nb, 1);
	}
	(*q_a)++;
	if (*q_a > 1)
		print_error_exit("Error\n1 Lumière ambiente maximum", l_nb, 1);
	check_lumnosité(obj_info, obj_info[1], l_nb);
	check_colors(obj_info, obj_info[2], l_nb);
}





















// check_color_2
	// int chifre = 0;
	// int color = 0;
	// while (s[i])
	// {   123,465,3
	// 	if (!ft_is_digit(s[i]))
	// 		print_error_exit("Error\nFormat des couleurs [0-255,0-255,0-255]", l_nb, 1); //ajoute pointeur foncion sur free fonction
	// 	if (s[i + 1] == ',')
	// 	i++;
	// 	chifre++;
	// 	color++;
	// 	if (j > 3 && s[i + 1] == ',')
	// 	if (j == 3)	
// 	}
// if (ft_atoi(tab_col[0]) < 0 || ft_atoi(tab_col[0] > 255)
// || (ft_atoi(tab_col[1]) < 0 || ft_atoi(tab_col[1] > 255)
	// || (ft_atoi(tab_col[2]) < 0 || ft_atoi(tab_col[2] > 255))
		// if (!strncmp(obj_inf[1], "[0.0,1.0]")
		// if ((obj_inf[1][0] == '0' || obj_inf[1][0] == '1') && obj_inf[1][1] == '.' && obj_inf[1][2])
		// else if (!ft_strncmp(obj_info[1], , 1)
		// if (!ft_strncmp(obj_info[1], , 1)
		// }
