# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahavu <ahavu@student.hive.fi>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/25 09:22:14 by ahavu             #+#    #+#              #
#    Updated: 2024/12/05 09:57:16 by ahavu            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SOURCES =	ft_printf.c print_char.c print_hex.c print_nbr.c \
			print_ptr.c print_str.c print_uint.c ft_strchr.c \

OBJECTS = $(SOURCES:.c=.o)

HEADER = $(NAME:.a=.h)

CC = cc

CFLAGS = -Wall -Wextra -Werror -I ./../incl

all: $(NAME)

$(NAME): $(OBJECTS)
	ar	-rcs	$(NAME)	$(OBJECTS)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re
