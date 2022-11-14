/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_main_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-s <sperez-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 09:26:21 by sperez-s          #+#    #+#             */
/*   Updated: 2022/11/14 12:06:00 by sperez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

t_gvars	g_vars;

void	handle_size(int signal)
{
	if (signal == SIGUSR1)
	{
		g_vars.size <<= 1;
		g_vars.size += 1;
	}
	else if (signal == SIGUSR2)
	{
		g_vars.size <<= 1;
	}
}

void	handle_message(int signal)
{
	int	mask;
	int	curr_bit;

	curr_bit = (7 - g_vars.received % 8);
	mask = (1 << curr_bit);
	if (signal == SIGUSR1)
		g_vars.curr_char = ((g_vars.curr_char & ~mask) | (1 << curr_bit));
	else if (signal == SIGUSR2)
		g_vars.curr_char = ((g_vars.curr_char & ~mask) | (0 << curr_bit));
	if (g_vars.received != 32 && curr_bit == 0)
	{
		g_vars.message[(g_vars.received - 32) / 8] = g_vars.curr_char;
		g_vars.curr_char = 0;
	}
	if (g_vars.received + 1 == g_vars.size * 8 + 32)
		g_vars.message[g_vars.size] = 0;
}

void	signal_handler(int signal, siginfo_t *info, void *vp)
{
	(void)vp;
	g_vars.client_pid = info->si_pid;
	g_vars.last_signal = signal;
	if (g_vars.received == 32)
	{
		g_vars.message = malloc((g_vars.size + 1) * sizeof(char));
		if (g_vars.message == NULL)
			exit(-1);
	}
	if (g_vars.received < 32)
	{
		handle_size(signal);
		g_vars.received++;
	}
	else if (g_vars.received >= 32 && (g_vars.size * 8) + 32 > g_vars.received)
	{	
		handle_message(signal);
		g_vars.received++;
	}
}

void	reset_vars(void)
{
	g_vars.received = 0;
	g_vars.sent = 0;
	g_vars.curr_char = 0;
	g_vars.size = 0;
	g_vars.message = NULL;
	g_vars.client_pid = 0;
	g_vars.last_signal = 0;
}

int	main(void)
{
	ft_printf("Server PID: %u\n", getpid());
	setup_signal(SIGUSR1, signal_handler, SA_SIGINFO);
	setup_signal(SIGUSR2, signal_handler, SA_SIGINFO);
	while (1)
	{
		if (g_vars.client_pid != 0)
		{
			g_vars.sent++;
			send_signal(g_vars.last_signal, g_vars.client_pid);
		}
		if (g_vars.received >= 32 && (g_vars.size * 8) + 32 == g_vars.received)
		{	
			ft_printf("%s\n", g_vars.message);
			free(g_vars.message);
			reset_vars();
		}
		pause();
	}
	return (0);
}
