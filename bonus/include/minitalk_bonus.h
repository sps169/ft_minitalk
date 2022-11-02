/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-s <sperez-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 09:23:37 by sperez-s          #+#    #+#             */
/*   Updated: 2022/11/02 12:28:22 by sperez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include "ft_printf.h"
# include <signal.h>

typedef struct s_gvars
{
	size_t	received;
	size_t	sent;
	size_t	size;
	char	curr_char;
	char	*message;
	int		client_pid;
	int		last_signal;
}	t_gvars;

int	send_string_to_server(char *message, int pid);

int	setup_signal(int sig, void (*h)(int, siginfo_t*, void*), int options);

int	send_signal(int signal, int pid);

#endif
