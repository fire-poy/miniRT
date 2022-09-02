/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpons <mpons@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 16:50:52 by mpons             #+#    #+#             */
/*   Updated: 2022/09/02 15:22:47 by mpons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	ft_putnbr(int nb, int fd)
{
	int				count;
	unsigned int	nbr;

	count = 0;
	if (nb < 0)
	{
		count += ft_putchar_fd('-', fd);
		nbr = (unsigned int)(nb * -1);
	}
	else
		nbr = (unsigned int)nb;
	if (nbr >= 10)
	{
		count += ft_putnbr(nbr / 10);
		nbr = nbr % 10;
	}
	if (nbr < 10)
	{
		count += ft_putchar_fd(nbr + 48, fd);
	}
	return (count);
}

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

void	check_arg(char *scene)
{
	if (ft_strlen(scene) < 4 || (!ft_strchr(scene, '.')))
		print_error_exit("Error\nArgument invalid", 1);
	if (ft_ft_strcmp(ft_strrchr(av[1], '.'), ".rt", 3) != 0)
		print_error_exit("Error\nType de scene invalide (.rt), 1");
}
// - Couleurs R,G,B dans le range [0-255] : 10, 0, 255
// check_colors
//get colors

t_objs	init_q_objs(void)
{
	t_q_obj q_obj;
	
	q_obj.a = 0; //ambiant
	q_obj.c = 0; //camera
	q_obj.l = 0; //light
	q_obj.sp = 0; //sphere
	q_obj.pl = 0; //plan
	q_obj.cy = 0; //cylindre
	return (q_obj);
}

// • Votre programme doit prendre en premier argument une description de scène avec un fichier .rt.
// ◦ Chaque type d’élément est séparé par un ou plusieurs retour(s) à la ligne.
// ◦ Chaque type d’information d’un élément peut être séparé par un ou plusieurs
// espace(s).
// ◦ Les élements peuvent être mis dans n’importe quel ordre dans le fichier.
// ◦ Les éléments qui commencent par une lettre majuscule ne peuvent être déclarés qu’une seule fois dans la scène.
t_set	*parsing(char *scene)
{
	int		fd;
	int		l_nb;
	char *	line;
	t_q_obj q_obj;
	int		i = 2;
	char **	obj_info;

	check_arg(scene);
	q_obj = init_q_objs();
	while (i-- > 0)
	{
		fd = open(scene, O_RDONLY);
		if (fd == -1)
			print_error_exit("Error\nPendant l'ouverture de fichier");
		l_nb = 0;
		line = get_next_line(fd);
		// checkmap;
		while (line)
		{
			l_nb++;
			if (line[0] == '\n')//ligne vide
			{
				free(line);
				line = get_next_line(fd);
				continue ;
			}
			obj_info = ft_split_set(line, " \t")
			// if (!ft_strcmp(line[i], "A"))
			if (!ft_strcmp(obj_info[0], "A"))
			{
				if (ft_tab_len(obj_info) != 3)
				{
					free_tab(obj_info);
					print_error_exit("Error\nQuantité des informations ne correspondent pas au type d'objet", l_nb, 1);
				}
				q_obj.a++
				if (q_obj.a > 1)
					print_error_exit("Error\n1 Lumière ambiente maximum", l_nb, 1);
				check_range_ambiante(obj_info[1])
				check_colors(obj_info[2])
					{
						tab_col = ft_split(obj_info[2], ',')
						if (ft_tab_len(tab_col) != 3)
							print_error_exit("Error\nIl faut 3 infos pour la couleur [0,255]", l_nb, 1);
						if (atoi(tab_col[0]) < 0 || atoi(tab_col[0] > 255)
						|| (atoi(tab_col[1]) < 0 || atoi(tab_col[1] > 255)
						|| (atoi(tab_col[2]) < 0 || atoi(tab_col[2] > 255))
						print_error_exit("Error\nCouleurs R,G,B doivent être dans le range [0,255]", l_nb, 1);
					}
					free (tab_col)
				// check_range()
				// if (!strncmp(obj_inf[1], "[0.0,1.0]")
				// if ((obj_inf[1][0] == '0' || obj_inf[1][0] == '1') && obj_inf[1][1] == '.' && obj_inf[1][2])
				// else if (!ft_strncmp(obj_info[1], , 1)
				// if (!ft_strncmp(obj_info[1], , 1)
			}
//CAMERA
			if (!ft_strcmp(line[i], "C"))
			{
				if (ft_words(line) != 4)
					print_error_exit("Error\nQuantité des informations ne correspondent pas au type d'objet", , l_nb, 1);
				q_obj.c++
				if (q_obj.c > 1)
					print_error_exit("Error\n1 Camera maximum", l_nb, 1);
				// check_vec_orientation(obj_info[2]) //-1 ,1 (0.0, 0.0, 0.5)
				// check_fov(obj_info[3]) //0,180
				check_coordonees(obj_info)
			}
			if (!ft_strcmp(line[i], "L"))
			{
				if (ft_words(line) != 4)
					print_error_exit("Error\nQuantité des informations ne correspondent pas au type d'objet", , l_nb, 1);
				q_obj.l++
				if (q_obj.l > 1)
					print_error_exit("Error\n1 Lumière maximum", l_nb, 1);
			}
			if (!ft_strcmp(line[i], "sp"))
			{
				if (ft_words(line) != 4)
					print_error_exit("Error\nQuantité des informations ne correspondent pas à la Sphere", , l_nb, 1);
			}
			if (!ft_strcmp(line[i], "pl"))
			{
				if (ft_words(line) != 4)
					print_error_exit("Error\nQuantité des informations ne correspondent pas au Plan", , l_nb, 1);
				q_obj.pl++
			}
			if (!ft_strcmp(line[i], "cy"))
			{
				if (ft_words(line) != 6)
					print_error_exit("Error\nQuantité des informations ne correspondent pas au Cylindre", , l_nb, 1);
				q_obj.cy++
			}
			free (line);
			line = get_next_line(fd);
		}
	close (fd);
	}
	
	
// void	ft_read_map(t_map *m)
// {
// 	char	*line;
// 	char	all_char[862];

// 	m->fd = open(m->name, O_RDONLY);
// 	if (m->fd == -1)
// 		fd_error();
// 	line = get_next_line(m->fd);
// 	check_wall(line);
// 	m->len_line = (int)ft_strlen(line) - 1;
// 	while (line)
// 	{
// 		if (line[0] != '1' || line[m->len_line - 1] != '1')
// 			print_error_exit("Error\nmidwall is not closed");
// 		ft_strcat(all_char, line);
// 		m->q_line++;
// 		free(line);
// 		line = get_next_line(m->fd);
// 		if (line && (int)ft_strlen(line) - 1 != m->len_line)
// 			print_error_exit("Error\ndiferents len line");
// 	}
// 	m->map = ft_split(all_char, '\n');
// 	m->fd = close(m->fd);
// 	max_taille(m);
// }	

// //free s == content
// char	**ft_split_from_charset(char *s, char *set)
// {
// 	int		i;
// 	char	**tab_ch;

// 	i = 0;
// 	if (ft_space_out_quotes_found(s, &i, set))
// 	{
// 		tab_ch = malloc(3 * sizeof(char *));
// 		tab_ch[0] = ft_substr(s, 0, i);
// 		while (s[i] == ' ' || s[i] == '\t')
// 			i++;
// 		tab_ch[1] = ft_substr(s, i, (int)ft_strlen - i);
// 		tab_ch[2] = NULL;
// 		free (s);
// 		return (tab_ch);
// 	}
// 	else
// 		return (NULL);
// }


// int	set_type(char *s, int i, char c)
// {
// 	int	type;

// 	if (c == '<')
// 		type = IN_FILE;
// 	if (c == '<' && s[i + 1] == '<')
// 		type = HEREDOC;
// 	if (c == '>')
// 		type = OUT_FILE;
// 	if (c == '>' && s[i + 1] == '>')
// 		type = APPEND;
// 	if (c == '|')
// 		type = PIPE;
// 	return (type);
// }
