/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_handler.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-s <sperez-s@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 17:02:44 by sperez-s          #+#    #+#             */
/*   Updated: 2022/07/19 09:31:47 by sperez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_arg_pointer(void *pointer)
{
	int	n;

	ft_putstr_fd("0x", 1);
	n = ft_putnbr_base((unsigned long) pointer, "0123456789abcdef", 16);
	return (2 + n);
}

int	print_arg_unsigned_decimal(unsigned int decimal)
{
	return (ft_putnbr_base((unsigned int) decimal, "0123456789", 10));
}

int	print_arg_hex(unsigned int hex)
{
	int	n;

	n = ft_putnbr_base(hex, "0123456789abcdef", 16);
	return (n);
}

int	print_arg_hex_mayus(unsigned int hex)
{
	int	n;

	n = ft_putnbr_base(hex, "0123456789ABCDEF", 16);
	return (n);
}
