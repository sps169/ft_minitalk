/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-s <sperez-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 11:31:37 by sperez-s          #+#    #+#             */
/*   Updated: 2022/10/18 10:21:47 by sperez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdio.h>

static int	send_char_to_server(unsigned char c, int pid)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if ((c >> i) & 1)
		{
			ft_printf("1");
			if (kill(pid, SIGUSR1) == -1)
				return (0);
		}
		else
		{
			ft_printf("0");
			if (kill(pid, SIGUSR2) == -1)
				return (0);
		}
		i--;
	}
	return (1);
}

int	send_string_to_server(char *message, int pid)
{
	int	char_sent;

	char_sent = 1;
	while (message && char_sent && *message != 0)
	{
		char_sent = send_char_to_server(*message, pid);
		ft_printf(" %c\n", *message);
		message++;
	}
	return (char_sent);
}
