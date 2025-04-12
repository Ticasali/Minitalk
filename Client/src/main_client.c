/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_client.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ticasali <ticasali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 18:53:56 by ticasali          #+#    #+#             */
/*   Updated: 2025/04/12 02:17:06 by ticasali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/client.h"

int	main(int argc, char **argv)
{
	if (argc != 3)
		return (-1);
	if (ft_digit(argv[1]) == 0)
		return (-1);
	client(argc, argv);
	return (0);
}
