/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ticasali <ticasali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 18:53:04 by ticasali          #+#    #+#             */
/*   Updated: 2025/04/12 02:40:14 by ticasali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include <stdbool.h>

int		ft_putchar(char c);
int		ft_atoi(char const *str);
int		ft_putstr(char *str);
int		send_str(int pid, char *s);
int		ft_digit(char *str);

void	send_bit(char c, int pid);
void	ft_signal(int sigval);
void	client(int argc, char **argv);
void	error(char *str);
void	putchar_error(char c);

#endif