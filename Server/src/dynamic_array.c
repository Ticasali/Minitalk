/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dynamic_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ticasali <ticasali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 03:29:33 by ticasali          #+#    #+#             */
/*   Updated: 2025/04/12 02:05:35 by ticasali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/server.h"

t_array	init_dynamic_array(size_t size)
{
	t_array	output;

	output.arr = malloc(sizeof(char) * size);
	if (output.arr == NULL)
		error("malloc", output);
	output.size = 0;
	output.capacity = size;
	return (output);
}

int	push_array(t_array *darray, char elem)
{
	t_array	doubled;
	int		i;

	i = 0;
	if (darray->capacity - darray->size <= 0)
	{
		doubled = init_dynamic_array(darray->size * 2);
		if (doubled.arr == 0)
			return (1);
		while (i < darray->size)
		{
			doubled.arr[i] = darray->arr[i];
			i++;
		}
		doubled.size = darray->size;
		free(darray->arr);
		*darray = doubled;
	}
	darray->arr[darray->size] = elem;
	darray->size++;
	return (0);
}

void	ft_bzero(void *s, int n)
{
	int		ct;
	char	*str;

	ct = 0;
	str = (char *)(s);
	while (ct < n)
	{
		str[ct] = '\0';
		ct++;
	}
}
