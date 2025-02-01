# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahavu <ahavu@student.hive.fi>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/21 15:48:41 by ahavu             #+#    #+#              #
#    Updated: 2025/02/01 17:20:58 by ahavu            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= so_long
SHELL 	:= /bin/bash
LIBMLX	:= MLX42/
ifeq ($(shell uname), Linux)
	LIB = $(LIBMLX)/build/libmlx42.a -ldl -lglfw(3) -pthread -lm
endif
ifeq ($(shell uname), Darwin)
	LIB = $(LIBMLX)/build/libmlx42.a -lglfw(3) -framework Cocoa \
		-framework OpenGL -framework IOKit
endif

SOURCES_PATH	:= sources/
SOURCES 		:=	$(SOURCES_PATH)so_long.c $(SOURCES_PATH)check_input.c \
					$(SOURCES_PATH)ft_error.c $(SOURCES_PATH)parse_map.c
					
OBJECTS			:= $(SOURCES:.c=.o)
HEADERS			:= -I ./incl -I $(LIBMLX)/include

CC		:= cc
CFLAGS	:= -Wall -Wextra -Werror -I./incl

all: libmlx $(NAME)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)

$(NAME): $(OBJECTS)
	$(CC) $(OBJECTS) $(LIB) $(HEADERS) -o $(NAME)

clean:
	rm -rf $(OBJECTS)
	rm -rf $(LIBMLX)/build

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re, libmlx