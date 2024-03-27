# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mnaumann <mnaumann@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/20 10:30:24 by mnaumann          #+#    #+#              #
#    Updated: 2024/03/26 18:46:36 by mnaumann         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = cc
HEADER = ./ft_printf.h
CFLAGS = -Wall -Wextra -Werror -I$(HEADER)
SRCS = 	ft_printf.c \
		functions/ft_checkformat.c \
		functions/ft_putchar_len.c \
		functions/ft_putnbr_len.c \
		functions/ft_putnbr_unsigned_len.c \
		functions/ft_putstr_len.c \
		functions/ft_putnbr_base_len.c \
		functions/ft_putnbr_base_add_len.c \
		functions/ft_strlen.c \

%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@

functions/%.o: functions/%.c
	$(CC) -c $(CFLAGS) $< -o $@

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME):  $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re