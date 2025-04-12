/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ticasali <ticasali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 18:53:04 by ticasali          #+#    #+#             */
/*   Updated: 2025/04/11 23:56:49 by ticasali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H
# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include <stdbool.h>

typedef struct s_array
{
	char	*arr;
	int		size;
	int		capacity;
}	t_array;

t_array	init_dynamic_array(size_t size);

int		push_array(t_array *darray, char elem);
int		ft_putchar(char c);
int		ft_putnbr(int nbr);
int		ft_putstr(char *str);

void	ft_server(int sigval, siginfo_t *siginfo, void *useless);
void	secure_server(siginfo_t *siginfo);
void	error(char *str, t_array arr);
void	putchar_error(char c);
void	setup_loop(void);
void	ft_bzero(void *s, int n);

#endif