# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahavu <ahavu@student.hive.fi>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/21 15:48:41 by ahavu             #+#    #+#              #
#    Updated: 2025/02/11 08:29:05 by ahavu            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= so_long
SHELL 	:= /bin/bash
LIBMLX	:= MLX42
LIBFT_PATH := incl/libft_plus/

ifeq ($(shell uname), Linux)
	LIB = $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm
endif
ifeq ($(shell uname), Darwin)
	LIB = $(LIBMLX)/build/libmlx42.a -L/opt/homebrew/lib -lglfw \
	-framework Cocoa -framework OpenGL -framework IOKit
endif

SOURCES_PATH	:= sources/
SOURCES 		:=	$(SOURCES_PATH)so_long.c $(SOURCES_PATH)check_input.c \
					$(SOURCES_PATH)ft_error.c $(SOURCES_PATH)parse_map.c \
					$(SOURCES_PATH)run_game.c $(SOURCES_PATH)move_player.c \
					$(SOURCES_PATH)ft_exit.c $(SOURCES_PATH)render.c
					
OBJECTS			:= $(SOURCES:.c=.o)
HEADERS			:= -I ./incl -I $(LIBMLX)/include

CC 		:= cc
CFLAGS	:= -Wall -Wextra -Werror -I./incl

all: libmlx $(NAME)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

$(SOURCES_PATH)%.o: $(SOURCES_PATH)%.c $(HEADERS)
	$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)

$(NAME): $(OBJECTS)
	make -C $(LIBFT_PATH) --no-print-directory
	$(CC) $(CFLAGS) $(OBJECTS) $(LIBFT_PATH)libft_plus.a \
		$(HEADERS) $(LIB) -o $(NAME)

clean:
	rm -rf $(OBJECTS)
	rm -rf $(LIBMLX)/build
	make clean -C $(LIBFT_PATH) --no-print-directory

fclean: clean
	rm -rf $(NAME)
	make fclean -C $(LIBFT_PATH) --no-print-directory

re: fclean all

.PHONY: all, clean, fclean, re, libmlx