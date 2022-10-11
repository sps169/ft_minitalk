/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-s <sperez-s@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 19:43:59 by sperez-s          #+#    #+#             */
/*   Updated: 2022/07/19 09:10:00 by sperez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int		i;

	if (s != NULL)
	{
		i = 0;
		while (s[i] != 0)
		{
			f(i, &s[i]);
			i++;
		}
	}
}
