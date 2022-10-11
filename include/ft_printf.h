/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-s <sperez-s@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 13:52:35 by sperez-s          #+#    #+#             */
/*   Updated: 2022/07/19 09:27:24 by sperez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include "libft.h"

int	print_arg_char(char character);

int	print_arg_string(char *string);

int	print_arg_pointer(void *pointer);

int	print_arg_decimal(int decimal);

int	print_arg_unsigned_decimal(unsigned int decimal);

int	print_arg_hex(unsigned int hex);

int	print_arg_hex_mayus(unsigned int hex);

int	ft_printf(const char *string, ...);

int	analize_arg(char type, va_list arg);

int	ft_nbr_writer(unsigned long num, char *base, size_t base_len);

int	ft_putnbr_base(unsigned long num, char *base, size_t base_len);

#endif
