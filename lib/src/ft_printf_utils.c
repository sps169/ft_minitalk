/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-s <sperez-s@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 13:13:50 by sperez-s          #+#    #+#             */
/*   Updated: 2022/07/19 09:31:50 by sperez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_nbr_writer(unsigned long num, char *base, size_t base_len)
{
	int	n;

	n = 0;
	if (num > 0)
	{
		n = ft_nbr_writer(num / base_len, base, base_len);
		n += write(1, &base[num % base_len], 1);
	}
	return (n);
}

int	ft_putnbr_base(unsigned long num, char *base, size_t base_len)
{
	int	n;

	n = 0;
	if (num == 0)
		return (write(1, "0", 1));
	n = ft_nbr_writer(num, base, base_len);
	return (n);
}
