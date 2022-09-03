/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpons <mpons@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 16:50:52 by mpons             #+#    #+#             */
/*   Updated: 2022/09/03 23:27:32 by mpons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRt.h"

// - Couleurs R,G,B dans le range [0-255] : 10, 0, 255
// check_colors
//get colors
t_q_obj	init_q_objs(void)
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
			print_error_exit("Error\nPendant l'ouverture de fichier", 0, 1);
		l_nb = 0;
		line = get_next_line(fd);
//❗️ checkmap
		while (line)
		{
			l_nb++;
			if (line[0] == '\n' && line[1] == '\0')//ligne vide
			{
				free(line);
				line = get_next_line(fd);
				continue ;
			}
			obj_info = ft_split_set(line, " \t\v\f\r");
			if (!ft_strcmp(obj_info[0], "A"))
			// check_lumiere
			{
				if (ft_tab_len(obj_info) != 3)
				{
					free_tab(obj_info);
					print_error_exit("Error\nQuantité des informations ne correspondent pas au type d'objet", l_nb, 1);
				}
				q_obj.a++;
				if (q_obj.a > 1)
					print_error_exit("Error\n1 Lumière ambiente maximum", l_nb, 1);
				check_range_ambiante(obj_info[1])
				{
				if (ft_is_it_float(obj_info[1]) == 0)
				{
					free_tab(obj_info);
					print_error_exit("Error\nNumero n'est pas un float", l_nb, 1); //ajoute pointeur foncion sur free fonction
				}
				n = atof(obj_info[1])
				if (in_range(n, 0.0f, 1.0f))
					{
						if (n < min|| n > max);
							return (0);
						return (1);
					}
					print_error_exit("Error\nFloat dehors range [0.0,1.0]", l_nb, 1); //ajoute pointeur foncion sur free fonction
				check_colors(obj_info[2])
				{
					// int i = 0;
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
					tab_col = ft_split(obj_info[2], ',')
					if (ft_tab_len(tab_col) != 3)
						print_error_exit("Error\nIl faut 3 infos pour la couleur [R,G,B]", l_nb, 1);
						while (tab_col[i])
						{
							//chercher dans obj_info [1 2 ou 3digit,3digit,3digit] si ce nest pas le cas error format
							// if (!ft_is_digit(tab_col[i][j]))
							if (ft_is_it_float(tab_col) == 0)
							{
								free_tab(tab_col);
								print_error_exit("Error\nCe n'est pas un numero [0,255]", l_nb, 1);
							}
							else 
							if (!in_range(n, 0.0f, 255.0f))
							{
								free_tab(tab_col);
								print_error_exit("Error\nCouleurs R,G,B doivent être dans le range [0,255]", l_nb, 1);
							}								
						}
					}
				if n < min ou >max => out of range
				
			
				if (!strncmp(obj_inf[1], "[0.0,1.0]")
				if ((obj_inf[1][0] == '0' || obj_inf[1][0] == '1') && obj_inf[1][1] == '.' && obj_inf[1][2])
				else if (!ft_strncmp(obj_info[1], , 1)
				if (!ft_strncmp(obj_info[1], , 1)
				}
			}
			if (!ft_strcmp(line[i], "C"))
			//CAMERA
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
