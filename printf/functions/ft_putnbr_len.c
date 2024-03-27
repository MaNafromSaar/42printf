/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_len.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaumann <mnaumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 20:05:31 by mnaumann          #+#    #+#             */
/*   Updated: 2024/03/26 23:18:22 by mnaumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_putnbr_recursive(int nb)
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

int	ft_putnbr_len_positive(int nb)
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
	result = ft_putnbr_recursive(nb);
	if (result == -1)
		return (-1);
	len += result;
	return (len);
}

int	ft_putnbr_len_negative(int nb)
{
	int	len;
	int	result;

	len = 0;
	if (write(1, "-", 1) == -1)
		return (-1);
	if (nb == -2147483648)
	{
		if (write(1, "2147483648", 10) == -1)
			return (-1);
		return (11);
	}
	nb = -nb;
	len += 1;
	result = ft_putnbr_recursive(nb);
	if (result == -1)
		return (-1);
	len += result;
	return (len);
}

int	ft_putnbr_len(int nb)
{
	if (nb < 0)
		return (ft_putnbr_len_negative(nb));
	else
		return (ft_putnbr_len_positive(nb));
}
