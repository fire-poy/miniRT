/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpons <mpons@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 20:01:00 by mpons             #+#    #+#             */
/*   Updated: 2022/09/01 21:00:39 by mpons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_quantite_trimer_debut(const char *s, const char *cs)
{	
	int	i;

	i = 0;
	while (s[i] && ft_c_vs_charset(s[i], cs))
		i++;
	return (i);
}

int	ft_quantite_trimer_fin(const char *s, const char *cs)
{	
	int	i;
	int	len;

	len = ft_strlen(s);
	i = len - 1;
	while (ft_c_vs_charset(s[i], cs) && i > 0)
		i--;
	return (len - (i + 1));
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*dst;
	int		taille;
	int		i;
	int		fin;

	if (!s1)
		return (NULL);
	taille = ft_strlen(s1);
	i = ft_quantite_trimer_debut(s1, set);
	fin = ft_quantite_trimer_fin(s1, set);
	taille = taille - fin - i;
	dst = ft_substr(s1, i, taille);
	return (dst);
}
/*
int	main(int ac, char **av)
{	
	(void) ac;
	printf("string original = %s\n charset = %s\n", av[1], av[2]);
	printf("string trimed = %s\n", ft_strtrim(av[1], av[2]));
	return (0);
}
*/
