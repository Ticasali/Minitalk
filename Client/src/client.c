/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ticasali <ticasali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 12:28:51 by ticasali          #+#    #+#             */
/*   Updated: 2025/04/12 02:45:05 by ticasali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/client.h"

volatile bool	g_lobal;

void	send_bit(char c, int pid)
{
	int	ct;

	ct = 128;
	while (ct >= 1)
	{
		if (g_lobal == true)
		{
			if (ct & c)
			{
				if (kill(pid, SIGUSR1) == -1)
					error("Error Signal!\n");
			}
			else
			{
				if (kill(pid, SIGUSR2) == -1)
					error("Error Signal!\n");
			}
			ct /= 2;
			g_lobal = false;
		}
	}
}

int	send_str(int pid, char *str)
{
	size_t	ct;

	ct = 0;
	while (str[ct])
	{
		send_bit(str[ct], pid);
		++ct;
	}
	send_bit('\0', pid);
	return (0);
}

void	ft_signal(int sigval)
{
	usleep(100);
	g_lobal = true;
	if (sigval == SIGUSR1)
		write(1, "Signal Check From Server\n", 26);
	return ;
}

void	client(int argc, char **argv)
{
	struct sigaction	sa;

	g_lobal = true;
	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGUSR1);
	sa.sa_handler = ft_signal;
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
	{
		error("Error Signal Client\n");
	}
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
	{
		error("Error Signal Client\n");
	}
	if (ft_atoi(argv[1]) <= 0)
		error("Wrong PID\n");
	if (argc == 3)
		send_str(ft_atoi(argv[1]), argv[2]);
	else
	{
		error("Wrong Arguments\n");
	}
	pause();
}
