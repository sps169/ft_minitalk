/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_functions_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-s <sperez-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 11:31:37 by sperez-s          #+#    #+#             */
/*   Updated: 2022/10/31 12:46:14 by sperez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

static int	send_char_to_server(unsigned char c, int pid)
{
	int	i;

	i = 7;
	ft_printf("%c ", c);
	while (i >= 0)
	{
		if ((c >> i) & 1)
		{
			if (kill(pid, SIGUSR1) == -1)
				return (0);
			pause();
			ft_printf("1");
			usleep(20);
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
				return (0);
			pause();
			ft_printf("0");
			usleep(20);
		}
		i--;
	}
	ft_printf("\n");
	return (1);
}

int	send_size_to_server(size_t size, int pid)
{
	size_t	bits;

	bits = 0;
	ft_printf("Size: ");
	while (bits <= 31)
	{
		if ((size >> (31 - bits)) & 1)
		{
			if (kill(pid, SIGUSR1) == -1)
				return (-1);
			pause();
			ft_printf("1");
			usleep(20);
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
				return (-1);
			pause();
			ft_printf("0");
			usleep(20);
		}
		bits++;
	}
	ft_printf("\n");
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
		message++;
	}
	return (char_sent);
}
