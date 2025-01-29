# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahavu <ahavu@student.hive.fi>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/21 15:48:41 by ahavu             #+#    #+#              #
#    Updated: 2025/01/29 13:46:10 by ahavu            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= so_long

LIBMLX	= incl/MLX42/
OS		= $(shell uname)
ifeq ($(OS), Linux)
	LIB = $(LIBMLX)/build/libmlx42.a -ldl -lglfw(3) -pthread -lm
endif

ifeq ($(OS), Darwin)
	LIB = $(LIBMLX)/build/libmlx42.a -lglfw(3) -framework Cocoa \
		-framework OpenGL -framework IOKit
endif

SOURCES_PATH	= sources/
SOURCES 		= $(SOURCES_PATH)so_long.c
					
OBJECTS			= $(SOURCES:.c=.o)
HEADER			= so_long.h

CC		= cc
CFLAGS	= -Wall -Wextra -Werror

all: libmlx $(NAME)

libmlx:
	cmake $(LIBMLX)

clean:
	rm -rf $(OBJECTS)
	rm -rf $(LIBMLX)/build

fclean:
	rm -rf $(NAME)

re: fclean all