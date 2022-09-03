/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outils.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpons <mpons@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 20:56:36 by mpons             #+#    #+#             */
/*   Updated: 2022/09/03 22:00:58 by mpons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRt.h"

void    print_error_exit(char *e, int line_err,int exit_status)
{
    ft_putendl_fd(e, 2);
	if (line_err)
	{
    	ft_putendl_fd("\n line", 2);
		ft_putnbr_fd(line_err, 2);
    	ft_putendl_fd("\n", 2);
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
