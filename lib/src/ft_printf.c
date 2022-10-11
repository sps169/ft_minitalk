/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-s <sperez-s@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 12:14:15 by sperez-s          #+#    #+#             */
/*   Updated: 2022/07/19 09:31:52 by sperez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <unistd.h>

int	analize_arg(char type, va_list arg)
{
	if (type == 'c')
		return (print_arg_char(va_arg(arg, int)));
	else if (type == 's')
		return (print_arg_string(va_arg(arg, char *)));
	else if (type == 'i')
		return (print_arg_decimal(va_arg(arg, int)));
	else if (type == 'p')
		return (print_arg_pointer(va_arg(arg, void *)));
	else if (type == 'd')
		return (print_arg_decimal(va_arg(arg, int)));
	else if (type == 'u')
		return (print_arg_unsigned_decimal(va_arg(arg, unsigned int)));
	else if (type == 'x')
		return (print_arg_hex(va_arg(arg, unsigned int)));
	else if (type == 'X')
		return (print_arg_hex_mayus(va_arg(arg, unsigned int)));
	else if (type == '%')
	{
		write(1, "%", 1);
		return (1);
	}
	return (0);
}

int	ft_printf(const char *string, ...)
{
	va_list	arg;
	size_t	count;
	int		i;

	count = 0;
	i = 0;
	va_start(arg, string);
	while (string[i] != 0)
	{
		if (string[i] == '%')
		{
			count += analize_arg(string[i + 1], arg);
			i += 2;
		}
		else
		{
			write(1, &string[i++], 1);
			count++;
		}
	}
	va_end(arg);
	return (count);
}
