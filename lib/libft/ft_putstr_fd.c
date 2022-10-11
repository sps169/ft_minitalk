/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-s <sperez-s@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 20:00:01 by sperez-s          #+#    #+#             */
/*   Updated: 2022/07/19 09:09:43 by sperez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	i;
	int	size;

	i = 0;
	if (s != NULL)
	{
		size = ft_strlen(s);
		while (i < size)
			write(fd, &s[i++], 1);
	}
}
