/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_handler_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-s <sperez-s@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 13:10:47 by sperez-s          #+#    #+#             */
/*   Updated: 2022/07/19 09:31:44 by sperez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_arg_char(char character)
{
	return (write(1, &character, 1));
}

int	print_arg_string(char *string)
{
	if (string == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	else
	{
		ft_putstr_fd(string, 1);
		return (ft_strlen(string));
	}
}

int	print_arg_decimal(int decimal)
{
	char	*pointer;
	size_t	len;
	int		printed;

	pointer = ft_itoa(decimal);
	len = ft_strlen(pointer);
	printed = write(1, pointer, len);
	free(pointer);
	return (printed);
}
