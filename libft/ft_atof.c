/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpons <mpons@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 16:18:46 by mpons             #+#    #+#             */
/*   Updated: 2022/09/14 14:21:57 by slott            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_is_it_white_space(char c)
{
	if (c == ' ' || c == '\t' || c == '\v'
		|| c == '\f' || c == '\r' || c == '\n')
		return (1);
	else
		return (0);
}

float	get_sign(char *s, int *i)
{
	float	sign;

	sign = 1.0f;
	while (ft_is_it_white_space(s[*i]))
		(*i)++;
	if (s[*i] == '-' || s[*i] == '+')
	{
		if (s[*i] == '-')
			sign *= -1.0f;
		(*i)++;
	}
	return (sign);
}

//il manque check max and min
//55-> 2.g
//60-> ft_is_digit-> en plus pas null
int	ft_is_it_float(char *s)
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
	{
		i++;
		j++;
		if (s[i] && s[i] == '.' && ft_isdigit(s[i + 1]))
		{
			if (++point > 1)
				return (0);
			i++;
		}
	}
	if ((s[i] == '\0' || ft_is_it_white_space(s[i])) && j > 0)
		return (1);
	return (0);
}

//88-> 1ere fois value = 0
float	ft_atof(char *s)
{
	int		i;
	int		point;
	float	sign;
	float	value;
	float	decimal;

	i = 0;
	value = 0;
	point = 0;
	decimal = 1.0f;
	sign = 1.0f * get_sign(s, &i);
	while (ft_isdigit(s[i]))
	{
		value *= 10;
		value += s[i++] - '0';
		if (point == 1)
			decimal *= 10;
		if (s[i] == '.')
		{
			point = 1;
			i++;
		}
	}
	return ((value * sign) / decimal);
}
