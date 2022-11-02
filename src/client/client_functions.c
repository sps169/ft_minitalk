/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-s <sperez-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 11:31:37 by sperez-s          #+#    #+#             */
/*   Updated: 2022/11/02 11:53:28 by sperez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	send_char_to_server(unsigned char c, int pid)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if ((c >> i) & 1)
		{
			if (kill(pid, SIGUSR1) == -1)
				return (0);
			usleep(100);
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
				return (0);
			usleep(100);
		}
		i--;
	}
	return (1);
}

int	send_size_to_server(size_t size, int pid)
{
	size_t	bits;

	bits = 0;
	while (bits <= 31)
	{
		if ((size >> (31 - bits)) & 1)
		{
			if (kill(pid, SIGUSR1) == -1)
				return (-1);
			usleep(100);
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
				return (-1);
			usleep(100);
		}
		bits++;
	}
	return (1);
}

int	send_string_to_server(char *message, int pid)
{
	int	char_sent;

	char_sent = 1;
	if (message && *message != 0)
		send_size_to_server(ft_strlen(message), pid);
	else
		return (0);
	while (char_sent && *message)
	{
		char_sent = send_char_to_server(*message, pid);
		if (char_sent)
			message++;
	}
	return (char_sent);
}
