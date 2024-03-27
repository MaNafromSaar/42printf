/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaumann <mnaumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 11:22:50 by mnaumann          #+#    #+#             */
/*   Updated: 2024/03/27 11:55:48 by mnaumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	ft_putchar_len(char c);
int	ft_putstr_len(char *str);
int	ft_putnbr_recursive(int nb);
int	ft_putnbr_len(int nb);
int	ft_putnbr_base_len(unsigned int nbr, char *base);
int	ft_putnbr_base_add_len(unsigned long nbr, char *base);
int	ft_putnbr_unsigned_len(unsigned int nb);
int	ft_checkformat(const char *format, va_list args);
int	ft_strlen(char *str);

int	ft_printf(const char *format, ...);