# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahavu <ahavu@student.hive.fi>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/21 15:48:41 by ahavu             #+#    #+#              #
#    Updated: 2025/01/31 15:54:27 by ahavu            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= so_long

LIBMLX	= incl/MLX42/
ifeq ($(shell uname), Linux)
	LIB = $(LIBMLX)/build/libmlx42.a -ldl -lglfw(3) -pthread -lm
ifeq ($(shell uname), Darwin)
	LIB = $(LIBMLX)/build/libmlx42.a -lglfw(3) -framework Cocoa \
		-framework OpenGL -framework IOKit
endif

SOURCES_PATH	= sources/
SOURCES 		= $(SOURCES_PATH)so_long.c
OBJECTS			= $(SOURCES:.c=.o)
HEADER			= so_long.h

CC		= cc
CFLAGS	= -Wall -Wextra -Werror -I./incl

all: libmlx $(NAME)

libmlx:
	cmake $(LIBMLX)

clean:
	rm -rf $(OBJECTS)
	rm -rf $(LIBMLX)/build

fclean:
	rm -rf $(NAME)

re: fclean all