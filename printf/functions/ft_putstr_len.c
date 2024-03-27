/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_len.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaumann <mnaumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 19:54:11 by mnaumann          #+#    #+#             */
/*   Updated: 2024/03/27 13:00:12 by mnaumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_putstr_len(char *str)
{
	int	len;

	if (str == NULL)
		len = write(1, "(null)", 6);
	else
		len = write(1, str, ft_strlen(str));
	if (len < 0)
		return (-1);
	return (len);
}
