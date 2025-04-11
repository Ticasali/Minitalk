/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ticasali <ticasali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 12:27:17 by ticasali          #+#    #+#             */
/*   Updated: 2025/04/12 00:45:22 by ticasali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/server.h"

t_array	g_arr;

void	ft_server(int sigval, siginfo_t *siginfo, void *useless)
{
	static int	ascii = 0;
	static int	bit = 0;

	(void)useless;
	if (sigval == SIGUSR1)
		ascii += (128 >> bit);
	bit += 1;
	if (bit == 8)
	{
		if (push_array(&g_arr, ascii) == 1)
			error("Malloc_again\n", g_arr);
		bit = 0;
		if (ascii == '\0')
		{
			ft_putstr(g_arr.arr);
			ft_bzero(g_arr.arr, g_arr.size);
			g_arr.size = 0;
			if (kill(siginfo->si_pid, SIGUSR1) == -1)
				error("Error Signal!\n", g_arr);
		}
		ascii = 0;
	}
	secure_server(siginfo);
}

void	secure_server(siginfo_t *siginfo)
{
	if (siginfo->si_pid == 0)
		error("Wrong PID\n", g_arr);
	if (kill(siginfo->si_pid, SIGUSR2) == -1)
		error("Error Signal\n", g_arr);
}

void	setup_loop(void)
{
	struct sigaction	sa;

	g_arr = init_dynamic_array(10);
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = ft_server;
	if ((sigaction(SIGUSR1, &sa, 0)) == -1)
		error("Error Signal1\n", g_arr);
	if ((sigaction(SIGUSR2, &sa, 0)) == -1)
		error("Error Signal2\n", g_arr);
	while (1)
		pause();
	free(g_arr.arr);
}
