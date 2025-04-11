/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ticasali <ticasali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 23:50:48 by ticasali          #+#    #+#             */
/*   Updated: 2025/04/05 15:04:11 by ticasali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/server.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *str)
{
	size_t	ct;

	ct = 0;
	while (str[ct])
	{
		if (ft_putchar(str[ct]) == -1)
			return (-1);
		++ct;
	}
	return (-1);
}

int	ft_putnbr(int nb)
{
	if (nb < 0)
	{
		if (ft_putchar('-') == -1)
			return (-1);
		ft_putnbr(nb * -1);
	}
	else if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
		if (ft_putchar(nb + 48) == -1)
			return (-1);
	return (0);
}
