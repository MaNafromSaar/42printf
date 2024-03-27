/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned_len.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaumann <mnaumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:16:36 by mnaumann          #+#    #+#             */
/*   Updated: 2024/03/26 23:19:52 by mnaumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_putnbr_unsigned_recursive(unsigned int nb)
{
	char	digit;
	int		len;
	int		result;

	len = 1;
	if (nb / 10 != 0)
	{
		result = ft_putnbr_recursive(nb / 10);
		if (result == -1)
			return (-1);
		len += result;
	}
	digit = (nb % 10) + '0';
	if (write(1, &digit, 1) == -1)
		return (-1);
	return (len);
}

int	ft_putnbr_unsigned_len(unsigned int nb)
{
	int	len;
	int	result;

	len = 0;
	if (nb == 0)
	{
		if (write(1, "0", 1) == -1)
			return (-1);
		return (1);
	}
	result = ft_putnbr_unsigned_recursive(nb);
	if (result == -1)
		return (-1);
	len += result;
	return (len);
}
