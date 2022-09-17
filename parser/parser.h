/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpons <mpons@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 16:18:48 by mpons             #+#    #+#             */
/*   Updated: 2022/09/17 13:07:28 by mpons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "../miniRt.h"

# define AMBIANT 0
# define CAMERA 1
# define LIGHT 2
# define SPHERE 3
# define PLAN 4
# define CYLINDRE 5

# define WHITE_SPACES " \t\v\f\r\n"

# define ERR_COLOR "Error\nIl faut 3 infos pour la couleur [R,G,B]"
# define ERR_COLOR_R "Error\nCe n'est pas un numero [0,255]"
# define ERR_COLOR_R2 "Error\nCouleurs R,G,B doivent être dans le range [0,255]"
# define ERR_TYPE "Error\nQuantite des info ne match pas au type d'objet"
# define ERR_COORD "Error\nIl faut 3 infos pour les coordonnées [x,y,z]"
# define ERR_FLOAT "Error\nNumero n'est pas un float"
# define ERR_FLOAT_RANGE "Error\nFloat dehors range [0.0,1.0]"
# define ERR_FORMAT_N "Error\nFormat numero incorrect"
# define ERR_F_R_N "Error\nFormat ou range numero incorrect"
# define ERR_L_AMB_MAX "Error\n1 Lumière ambiente maximum"

# ifndef T_SET
#  define T_SET

typedef struct s_set	t_set;
# endif

# ifndef T_Q_OBJ
#  define T_Q_OBJ

typedef struct s_q_obj
{
	int	a;
	int	c;
	int	l;
	int	sp;
	int	pl;
	int	cy;
}	t_q_obj;
# endif

// utils
void	print_tab(char **tab);
void	print_obj(t_q_obj *q_obj);
int		ft_putnbr(int nb, int fd);
void	print_error_exit(char *e, int line_err, int exit_status);
void	free_and_error(char **obj_info, char **tab_col, char *err, int l_nb);
void	check_arg(const char *scene);
int		is_it_empty_line(char **line, int fd);
int		is_in_range(float n, float min, float max);
void	check_colors(char **obj_info, char *l_color, int l_nb);
int		ft_is_it_int(char *s);

// CHECK SCENE
void	check_scene(char *scene_file, t_q_obj *q_obj);

//lumiere ambiante
void	check_lumnosite(char **obj_info, char *lumnosite, int l_nb);
void	check_lumiere_ambiente(char **obj_info, int *q_l, int l_nb);

//camera
void	check_coordonees(char **obj_info, char *vector, int l_nb);
void	check_vector_orientation(char **obj_info, char *vector, int l_nb);
void	check_fov(char **obj_info, char *fov, int l_nb);
void	check_camera(char **obj_info, int *q_c, int l_nb);

//lumiere
void	check_lumiere(char **obj_info, int *q_l, int l_nb);

//sphere
void	check_positive_float(char **obj_info, char *diameter, int l_nb);
void	check_diameter(char **obj_info, char *diameter, int l_nb);
void	check_sphere(char **obj_info, int *q_sp, int l_nb);

//plane
void	check_plane(char **obj_info, int *q_obj, int l_nb);

//cylindre
void	check_cylindre(char **obj_info, int *q_obj, int l_nb);

// GET SCENE
t_vect	get_vector_from_string(char *rgb);
void	get_scene(char *scene_file, t_set *set);
void	get_objects(char **obj_info, t_set *set);
void	get_lumiere_ambiente(t_set *set, char **obj_info);
void	get_camera(t_set *set, char **obj_info);
void	get_lumiere(t_set *set, char **obj_info);
void	get_sphere(t_set *set, char **obj_info);
void	get_plane(t_set *set, char **obj_info);
void	get_cylindre(t_set *set, char **obj_info);

#endif
