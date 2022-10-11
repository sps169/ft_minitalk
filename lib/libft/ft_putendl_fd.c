/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-s <sperez-s@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 20:25:56 by sperez-s          #+#    #+#             */
/*   Updated: 2022/07/19 09:09:38 by sperez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	size_t		i;
	size_t		size;

	i = 0;
	if (s != NULL)
	{
		size = ft_strlen(s);
		while (i < size)
			write(fd, &s[i++], 1);
		write(fd, "\n", 1);
	}
}
