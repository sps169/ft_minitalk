/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-s <sperez-s@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 17:56:18 by sperez-s          #+#    #+#             */
/*   Updated: 2022/07/19 09:09:33 by sperez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned long	i;
	char			*d;

	d = (char *)b;
	i = 0;
	while (i < len)
	{
		d[i] = (char)c;
		i++;
	}
	return (b);
}
