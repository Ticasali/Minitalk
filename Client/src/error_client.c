/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_client.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ticasali <ticasali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 15:49:10 by ticasali          #+#    #+#             */
/*   Updated: 2025/04/12 02:45:14 by ticasali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/client.h"

void	putchar_error(char c)
{
	write(2, &c, 1);
}

void	error(char *str)
{
	size_t	ct;

	ct = 0;
	while (str[ct] != '\0')
	{
		putchar_error(str[ct]);
		++ct;
	}
	exit(-1);
}
