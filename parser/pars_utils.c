/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpons <mpons@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 10:34:30 by mpons             #+#    #+#             */
/*   Updated: 2022/09/09 18:54:20 by mpons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

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
	while (ft_isdigit(s[i]))
		i++;
	if (s[i] == '\0' || ft_is_it_white_space(s[i]))
		return (1);
	else
		return (0);
}

int	is_in_range(float n, float min, float max)
{
	if (n < min || n > max)
		return (0);
	return (1);
}

//Si obj_info != NULL free_tab, la meme chose pour tab_col,
// apres print err suivi de nro ligne et exit(1)
void	free_and_error(char **obj_info, char **tab_col, char *err, int l_nb)
{
	if (obj_info)
		free_tab(obj_info);
	if (tab_col)
		free_tab(tab_col);
	print_error_exit(err, l_nb, 1);
}

// Si vous rencontrez un quelconque problème de configuration dans le fichier, 
// votre programme doit se fermer correctement et renvoyer "Error\n" suivi 
// d’un message explicite de votre choix.
//print error and line
void	print_error_exit(char *e, int line_err, int exit_status)
{
	ft_putendl_fd(e, 2);
	if (line_err)
	{
		ft_putstr_fd("line ", 2);
		ft_putnbr_fd(line_err, 2);
		ft_putendl_fd("", 2);
	}
	exit (exit_status);
}
