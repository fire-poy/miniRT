/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpons <mpons@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 10:34:30 by mpons             #+#    #+#             */
/*   Updated: 2022/09/06 15:20:59 by mpons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	print_tab(char **tab)
{
	int	i;

	i = -1;
	while (tab[++i])
	{
		printf("%s", tab[i]);
		printf("\n");
	}
	printf("fiiiiiiiiin\n");
}

void	print_obj(t_q_obj *q_obj)
{
	printf("obj c = %d\n", q_obj->c);
	printf("obj l = %d\n", q_obj->l);
	printf("obj a = %d\n", q_obj->a);
	printf("obj sp = %d\n", q_obj->sp);
	printf("obj pl = %d\n", q_obj->pl);
	printf("obj cy = %d\n", q_obj->cy);
}

void	free_and_error(char **obj_info, char **tab_col, char *err, int l_nb)
{
	if (obj_info)
		free_tab(obj_info);
	if (tab_col)
		free_tab(tab_col);
	print_error_exit(err, l_nb, 1);
}
//ajoute pointeur foncion sur free fonction
// ajouter Error: au debut??
//print error and line?
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

// Si vous rencontrez un quelconque problème de configuration dans le fichier, 
// votre programme doit se fermer correctement et renvoyer "Error\n" suivi 
// d’un message explicite de votre choix.
void	check_arg(const char *scene)
{
	if (ft_strlen(scene) < 4 || (!ft_strchr(scene, '.')))
		print_error_exit("Error\nArgument invalid", 0, 1);
	if (ft_strcmp(ft_strrchr(scene, '.'), ".rt") != 0)
		print_error_exit("Error\nType de scene invalide (.rt)", 0, 1);
}
