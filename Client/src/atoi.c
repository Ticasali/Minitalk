/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ticasali <ticasali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 00:11:05 by ticasali          #+#    #+#             */
/*   Updated: 2025/04/05 14:39:35 by ticasali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/client.h"

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

int	ft_atoi(char const *str)
{
	unsigned long	ret;
	int				sign;
	size_t			ct;

	sign = 1;
	ret = 0;
	ct = 0;
	while ((str[ct] >= 9 && str[ct] <= 13) || (str[ct] == ' '))
		ct++;
	if (str[ct] == '-' || str[ct] == '+')
		if (str[ct++] == '-')
			sign = -1;
	while (str[ct] > 47 && str[ct] < 58)
	{
		ret += str[ct] - 48;
		if ((str[++ct] > 47 && str[ct] < 58))
			ret *= 10;
	}
	return ((int)(ret * sign));
}
