/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr_set.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpons <mpons@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 11:51:00 by mpons             #+#    #+#             */
/*   Updated: 2022/09/03 22:11:04 by mpons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//return i in position of char founded else strlen
int	ft_strchr_char(const char *s, char c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (i);
}

// copare char avec charset
// si trouve coincidence return 1
int	ft_c_vs_charset(char c, const char *cs)
{
	int	i;

	i = 0;
	while (c != cs[i] && cs[i] && cs[i + 1] != '\0')
		i++;
	if (c == cs[i])
		return (1);
	else
		return (0);
}

//return i in position of char from charset
//return strlen if set not found
int	ft_strchr_set(const char *s, char *set)
{
	int	i;

	i = 0;
	while (s[i] && !ft_c_vs_charset(s[i], set))
		i++;
	return (i);
}

//search charset a partir du start, avance l'address si trouve le chset;
//return 0 si ne trouve pas, 1 en succes
int	ft_charset_found(const char *s, int *start, char *set)
{
	int	i;

	i = *start;
	while (s[i] && !ft_c_vs_charset(s[i], set))
		i++;
	if (s[i] == 0)
		return (0);
	else
		*start = i;
	return (1);
}
