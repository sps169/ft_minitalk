/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_signal_handler_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-s <sperez-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 09:12:04 by sperez-s          #+#    #+#             */
/*   Updated: 2022/11/11 13:42:34 by sperez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

int	setup_signal(int sig, void (*h)(int, siginfo_t *, void *), int options)
{
	int					r;
	struct sigaction	s;

	s.__sigaction_u.__sa_sigaction = h;
	sigemptyset(&s.sa_mask);
	s.sa_flags = options;
	r = sigaction(sig, &s, NULL);
	if (r < 0)
		return (-1);
	return (r);
}

void	send_signal(int signal, int pid)
{
	if (signal == SIGUSR1)
	{	
		usleep(100);
		while (kill(pid, SIGUSR1)== -1)
			usleep(10);
	}
	else if (signal == SIGUSR2)
	{	
		usleep(100);
		while (kill(pid, SIGUSR2)== -1)
			usleep(10);
	}
}
