/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_add_len.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaumann <mnaumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 18:43:54 by mnaumann          #+#    #+#             */
/*   Updated: 2024/03/27 13:01:38 by mnaumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_putnbr_base_add_len_zero(void)
{
	if (write(1, "0x0", 3) == -1)
		return (-1);
	return (3);
}

int	ft_putnbr_base_add_len_nonzero(unsigned long nbr, char *base)
{
	int				index;
	char			a[17];
	int				printed_len;

	a[0] = 0;
	index = 0;
	printed_len = ft_putstr_len("0x");
	while (nbr > 0)
	{
		a[index++] = base[nbr % 16];
		nbr = nbr / 16;
	}
	while (--index > -1 && printed_len != -1)
	{
		if (write(1, &a[index], 1) == -1)
			return (-1);
		printed_len += 1;
	}
	return (printed_len);
}

int	ft_putnbr_base_add_len(unsigned long nbr, char *base)
{
	if (nbr == 0)
		return (ft_putnbr_base_add_len_zero());
	else
		return (ft_putnbr_base_add_len_nonzero(nbr, base));
}
