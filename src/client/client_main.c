/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-s <sperez-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 09:26:24 by sperez-s          #+#    #+#             */
/*   Updated: 2022/10/25 10:30:25 by sperez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(int argc, char *argv[])
{
	int	pid;

	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		if (pid > 0)
		{
			if (ft_strlen(argv[2]) > 0)
				send_string_to_server(argv[2], pid);
			else
				ft_printf("Empty string\n");
		}
		else
			ft_printf("Wrong pid\n");
	}
	else
		ft_printf("Wrong args\n");
	return (0);
}
