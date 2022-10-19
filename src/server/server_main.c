/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-s <sperez-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 09:26:21 by sperez-s          #+#    #+#             */
/*   Updated: 2022/10/19 17:15:50 by sperez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_gvars gvars;

void	init_message(void)
{
	gvars.message = malloc((gvars.size + 1)* sizeof(char));
	if (gvars.message == NULL)
		exit(-1);
}

void	handle_size(int signal)
{
	if (signal == SIGUSR1)
	{
		ft_printf("1");
		gvars.size <<= 1;
		gvars.size += 1;
	}
	else if (signal == SIGUSR2)
	{
		ft_printf("0");
		gvars.size <<= 1;
	}
}

void	handle_message(int signal)
{
	if (signal == SIGUSR1)
	{
		ft_printf("1");

	}
	else if (signal == SIGUSR2)
	{
		ft_printf("0");
	}	
}

void	signal_handler(int signal)
{
	if (gvars.received < 32)
		handle_size(signal);
	else
		handle_message(signal);		
	gvars.received++;
	if (gvars.received == 32)
	{
		init_message();
		ft_printf("\n");
	}
}

void	init_vars(void)
{
	gvars.received = 0;
	gvars.curr_char = 0;
	gvars.size = 0;
	gvars.message = NULL;
}
int	main(void)
{
	ft_printf("Server PID: %u\n",getpid());
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);

	while (1)
	{
		if (gvars.received >= 32 && (gvars.size * 8) + 32 == gvars.received)
		{	
			ft_printf("\nReceived!\n");
		}	
		pause();
	}
	return (0);
}
