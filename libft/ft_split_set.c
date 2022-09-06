/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_set.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpons <mpons@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 22:05:11 by mpons             #+#    #+#             */
/*   Updated: 2022/09/05 13:12:23 by mpons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_words_set(const char *s, char *set)
{	
	int	i;
	int	word;

	word = 0;
	i = 0;
	if (set == NULL)
		return (1);
	while (s[i])
	{	
		while (s[i] && ft_c_vs_charset(s[i], set))
			i++;
		if (!s[i])
			return (word);
		word++;
		while (s[i] && !ft_c_vs_charset(s[i], set))
			i++;
	}
	return (word);
}

static int	ft_w_copy(char **tab, char *s, char *set)
{	
	int	i;
	int	j;
	int	word;
	int	debut;

	word = 0;
	i = 0;
	j = -1;
	if (set == NULL)
		return (1);
	while (s[i])
	{	
		while (s[i] && ft_c_vs_charset(s[i], set))
			i++;
		if (!s[i])
			break ;
		debut = i;
		while (s[i] && !ft_c_vs_charset(s[i], set))
			i++;
		tab[++j] = ft_substr(s, debut, i - debut);
		if (!tab[j])
			return (1);
	}
	return (0);
}

char	**ft_split_set(char *s, char *set)
{
	char	**tab;
	int		words;

	if (!s)
		return (NULL);
	words = ft_words_set(s, set);
	if (words == 0)
		return (NULL);
	tab = malloc((words + 1) * sizeof(char *));
	if (!tab)
		return (NULL);
	if (ft_w_copy(tab, s, set))
	{
		free_tab(tab);
		return (NULL);
	}
	tab[words] = NULL;
	return (tab);
}
