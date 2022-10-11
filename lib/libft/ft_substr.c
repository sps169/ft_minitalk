/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-s <sperez-s@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 11:07:40 by sperez-s          #+#    #+#             */
/*   Updated: 2022/07/19 09:08:35 by sperez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static size_t	get_s_len(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;

	s_len = 0;
	while (s[s_len] != 0)
		s_len++;
	if (start >= s_len)
		s_len = 0;
	else if (s_len - start < len)
		s_len = s_len - start;
	else
		s_len = len;
	return (s_len);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char				*new_str;
	unsigned int		i;
	size_t				s_len;

	s_len = 0;
	if (s != NULL)
		s_len = get_s_len(s, start, len);
	new_str = malloc((s_len + 1) * sizeof(char));
	if (new_str == NULL)
		return (NULL);
	i = 0;
	if (new_str != NULL)
	{
		while (i < s_len)
		{
			new_str[i] = s[start + i];
			i++;
		}
	}
	new_str[i] = '\0';
	return (new_str);
}
