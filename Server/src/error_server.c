/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_server.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ticasali <ticasali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 15:51:10 by ticasali          #+#    #+#             */
/*   Updated: 2025/04/11 23:56:25 by ticasali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/server.h"

void	putchar_error(char c)
{
	write(2, &c, 1);
}

void	error(char *str, t_array arr)
{
	size_t	ct;

	ct = 0;
	while (str[ct] != '\0')
	{
		putchar_error(str[ct]);
		++ct;
	}
	free(arr.arr);
	exit(-1);
}
