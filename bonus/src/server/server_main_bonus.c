/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_main_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-s <sperez-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 09:26:21 by sperez-s          #+#    #+#             */
/*   Updated: 2022/10/26 16:28:00 by sperez-s         ###   ########.fr       */
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
	if (g_vars.received == g_vars.size * 8 + 32)
		g_vars.message[g_vars.size] = 0;
}

void	signal_handler(int signal)
{
	if (g_vars.received < 32)
		handle_size(signal);
	else
		handle_message(signal);
	g_vars.received++;
	if (g_vars.received == 32)
	{
		g_vars.message = malloc((g_vars.size + 1) * sizeof(char));
		if (g_vars.message == NULL)
			exit(-1);
	}
}

void	reset_vars(void)
{
	g_vars.received = 0;
	g_vars.curr_char = 0;
	g_vars.size = 0;
	g_vars.message = NULL;
}

int	main(void)
{
	ft_printf("Server PID: %u\n", getpid());
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	while (1)
	{
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
