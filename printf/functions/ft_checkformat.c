/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkformat.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaumann <mnaumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 10:17:13 by mnaumann          #+#    #+#             */
/*   Updated: 2024/03/27 10:34:48 by mnaumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_checkformat(const char *format, va_list args)
{
	if (*format == '%')
		return (ft_putchar_len('%'));
	else if (*format == 'c')
		return (ft_putchar_len(va_arg(args, int)));
	else if (*format == 's')
		return (ft_putstr_len(va_arg(args, char *)));
	else if (*format == 'd' || *format == 'i')
		return (ft_putnbr_len(va_arg(args, int)));
	else if (*format == 'u')
		return (ft_putnbr_unsigned_len(va_arg(args, unsigned int)));
	else if (*format == 'x')
		return (ft_putnbr_base_len(va_arg(args, long int), "0123456789abcdef"));
	else if (*format == 'X')
		return (ft_putnbr_base_len(va_arg(args, long int), "0123456789ABCDEF"));
	else if (*format == 'p')
		return (ft_putnbr_base_add_len(va_arg(args, unsigned long),
				"0123456789abcdef"));
	else
		return (-1);
}
