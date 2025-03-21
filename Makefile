# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahavu <ahavu@student.hive.fi>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/21 15:48:41 by ahavu             #+#    #+#              #
#    Updated: 2025/03/10 14:43:40 by ahavu            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= so_long
SHELL 	:= /bin/bash
MLX_DIR	:= ./MLX42
MLX_AR	:= ./MLX42/build/libmlx42.a
LIBFT_PATH := incl/libft_plus/

ifeq ($(shell uname), Linux)
	LIB = $(MLX_DIR)/build/libmlx42.a -ldl -lglfw -pthread -lm
endif
ifeq ($(shell uname), Darwin)
	LIB = $(MLX_DIR)/build/libmlx42.a -L/opt/homebrew/lib -lglfw \
	-framework Cocoa -framework OpenGL -framework IOKit
endif

SOURCES_PATH	:= sources/
SOURCES 		:=	$(SOURCES_PATH)so_long.c $(SOURCES_PATH)check_input.c \
					$(SOURCES_PATH)ft_error.c $(SOURCES_PATH)parse_map.c \
					$(SOURCES_PATH)run_game.c $(SOURCES_PATH)move_player.c \
					$(SOURCES_PATH)ft_exit.c $(SOURCES_PATH)render.c \
					$(SOURCES_PATH)check_map.c
					
OBJECTS			:= $(SOURCES:.c=.o)
HEADERS			:= -I ./incl -I $(MLX_DIR)/include

CC 		:= cc
CFLAGS	:= -Wall -Wextra -Werror -I./incl

all: $(NAME)

$(MLX_AR):
	@if [ ! -d "$(MLX_DIR)" ]; then \
		echo -e "\033[36m-----Cloning MLX42-----\033[0m"; \
		git clone git@github.com:codam-coding-college/MLX42.git; \
	fi
	@cmake $(MLX_DIR) -B $(MLX_DIR)/build && make -C $(MLX_DIR)/build -j4; \

$(NAME): $(MLX_AR) $(OBJECTS)
	@echo -e "\033[36m-----making libft-----\033[0m"
	@make -C $(LIBFT_PATH)
	$(CC) $(CFLAGS) $(OBJECTS) $(LIBFT_PATH)libft_plus.a \
		$(HEADERS) $(LIB) -o $(NAME)
	@echo -e "\033[36m---------everything is compiled, let's play!!!-------\033[0m"
	@echo -e "\033[36m----👈👉you can move with WASD or arrow keys!👈👉----\033[0m"
	@echo -e "\033[36m-------------😈kill enemies with SPACE😈-------------\033[0m"

clean:
	@rm -rf $(OBJECTS)
	@rm -rf $(MLX_DIR)/build
	@make clean -C $(LIBFT_PATH)
	@echo -e "\033[36m-----headers removed-----\033[0m"

fclean: clean
	@rm -rf $(NAME)
	@make fclean -C $(LIBFT_PATH)
	@rm -rf $(MLX_DIR)
	@echo -e "\033[36m-----everything cleaned-----\033[0m"

re: fclean all

.PHONY: all, clean, fclean, re
