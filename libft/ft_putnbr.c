/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpons <mpons@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 21:39:26 by mpons             #+#    #+#             */
/*   Updated: 2022/09/03 21:53:18 by mpons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr(int nb, int fd)
{
	int				count;
	unsigned int	nbr;

	count = 0;
	if (nb < 0)
	{
		ft_putchar_fd('-', fd);
		nbr = (unsigned int)(nb * -1);
	}
	else
		nbr = (unsigned int)nb;
	if (nbr >= 10)
	{
		count += ft_putnbr(nbr / 10, 2);
		nbr = nbr % 10;
	}
	if (nbr < 10)
	{
		ft_putchar_fd(nbr + 48, fd);
	}
	return (count);
}
