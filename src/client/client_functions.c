/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-s <sperez-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 11:31:37 by sperez-s          #+#    #+#             */
/*   Updated: 2022/10/17 12:25:24 by sperez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	send_char_to_server(unsigned char c, int pid)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (c & 1)
		{
			if (kill(pid, SIGUSR1) == -1)
				return (0);
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
				return (0);
		}
		i++;
		c >>= 1;
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
		message++;
	}
	return (char_sent);
}
