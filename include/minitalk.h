/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-s <sperez-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 09:23:37 by sperez-s          #+#    #+#             */
/*   Updated: 2022/10/25 10:23:36 by sperez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "ft_printf.h"
# include <signal.h>

typedef struct s_gvars
{
	size_t	received;
	size_t	size;
	char	curr_char;
	char	*message;
}	t_gvars;

int	send_string_to_server(char *message, int pid);

#endif
