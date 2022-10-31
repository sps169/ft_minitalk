/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_signal_handler_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-s <sperez-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 09:12:04 by sperez-s          #+#    #+#             */
/*   Updated: 2022/10/31 12:43:33 by sperez-s         ###   ########.fr       */
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

int	send_signal(int signal, int pid, int wait)
{
	if (signal == SIGUSR1)
	{	
		if (kill(pid, SIGUSR1)== -1)
			return (0);
		if (wait)
			pause();
	}
	else if (signal == SIGUSR2)
	{	
		if (kill(pid, SIGUSR2)== -1)
			return (0);
		if (wait)
			pause();
	}
	else if (signal == 0)
	{
		if (wait)
			pause();
		return (0);
	}
	return (1);
}
