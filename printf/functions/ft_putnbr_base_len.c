/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_len.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaumann <mnaumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 20:22:13 by mnaumann          #+#    #+#             */
/*   Updated: 2024/03/27 11:49:22 by mnaumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_putnbr_base_len(unsigned int nbr, char *base)
{
	int				index;
	char			a[17];
	int				printed_len;

	index = 0;
	printed_len = 0;
	if (nbr == 0)
		printed_len += write(1, &base[0], 1);
	while (nbr > 0)
	{
		a[index++] = base[nbr % 16];
		nbr = nbr / 16;
	}
	while (--index > -1)
	{
		printed_len += write(1, &a[index], 1);
		if ((printed_len <= 0))
			return (-1);
	}
	return (printed_len);
}
