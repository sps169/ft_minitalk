/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-s <sperez-s@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 17:54:16 by sperez-s          #+#    #+#             */
/*   Updated: 2022/07/19 09:09:50 by sperez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strdup(const char *s1)
{
	char	*string;
	int		i;
	char	*src;

	src = (char *) s1;
	string = malloc((ft_strlen(src) + 1) * sizeof(char));
	if (string != NULL)
	{
		i = 0;
		while (s1[i] != 0)
		{
			string[i] = s1[i];
			i++;
		}
		string[i] = '\0';
	}
	return (string);
}
