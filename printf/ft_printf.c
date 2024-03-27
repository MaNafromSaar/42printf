/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaumann <mnaumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 09:18:31 by mnaumann          #+#    #+#             */
/*   Updated: 2024/03/27 12:33:07 by mnaumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		printed_len;

	va_start(args, format);
	printed_len = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			printed_len += ft_checkformat(format, args);
			if (printed_len < 0)
				return (-1);
			format++;
		}
		else
		{
			printed_len += ft_putchar_len(*format);
			if (printed_len < 0)
				return (-1);
			format++;
		}
	}
	va_end(args);
	return (printed_len);
}

// int ft_errorcheck
// flagging errors in every function, whenever write is used and may fail
