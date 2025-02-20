# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahavu <ahavu@student.hive.fi>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/07 10:20:46 by ahavu             #+#    #+#              #
#    Updated: 2025/02/05 11:43:56 by ahavu            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft_plus.a
LIBFT_PATH = libft_src/
PRINTF_PATH = ft_printf/

LIBFT_SRC = $(LIBFT_PATH)ft_atoi.c $(LIBFT_PATH)ft_bzero.c \
			$(LIBFT_PATH)ft_calloc.c $(LIBFT_PATH)ft_isalnum.c \
			$(LIBFT_PATH)ft_isalpha.c $(LIBFT_PATH)ft_isascii.c \
			$(LIBFT_PATH)ft_isdigit.c $(LIBFT_PATH)ft_isprint.c \
			$(LIBFT_PATH)ft_itoa.c $(LIBFT_PATH)ft_memchr.c \
			$(LIBFT_PATH)ft_memcmp.c $(LIBFT_PATH)ft_memcpy.c \
			$(LIBFT_PATH)ft_memmove.c $(LIBFT_PATH)ft_memset.c \
			$(LIBFT_PATH)ft_putchar_fd.c $(LIBFT_PATH)ft_putendl_fd.c \
			$(LIBFT_PATH)ft_putnbr_fd.c $(LIBFT_PATH)ft_putstr_fd.c \
			$(LIBFT_PATH)ft_split.c $(LIBFT_PATH)ft_strchr.c \
			$(LIBFT_PATH)ft_strdup.c $(LIBFT_PATH)ft_striteri.c \
			$(LIBFT_PATH)ft_strjoin.c $(LIBFT_PATH)ft_strlcat.c \
			$(LIBFT_PATH)ft_strlcpy.c $(LIBFT_PATH)ft_strlen.c \
			$(LIBFT_PATH)ft_strmapi.c $(LIBFT_PATH)ft_strncmp.c \
			$(LIBFT_PATH)ft_strnstr.c $(LIBFT_PATH)ft_strrchr.c \
			$(LIBFT_PATH)ft_strtrim.c $(LIBFT_PATH)ft_substr.c \
			$(LIBFT_PATH)ft_tolower.c $(LIBFT_PATH)ft_toupper.c \
			$(LIBFT_PATH)ft_lstadd_front.c $(LIBFT_PATH)ft_lstnew.c \
			$(LIBFT_PATH)ft_lstsize.c $(LIBFT_PATH)ft_lstlast.c \
			$(LIBFT_PATH)ft_lstadd_back.c $(LIBFT_PATH)ft_lstdelone.c \
			$(LIBFT_PATH)ft_lstclear.c $(LIBFT_PATH)ft_lstiter.c \
			$(LIBFT_PATH)ft_lstmap.c $(LIBFT_PATH)get_next_line.c \
			$(LIBFT_PATH)ft_atoi_longlong.c

PRINTF_SRC = 	$(PRINTF_PATH)ft_printf.c $(PRINTF_PATH)print_char.c \
				$(PRINTF_PATH)print_hex.c $(PRINTF_PATH)print_nbr.c \
				$(PRINTF_PATH)print_ptr.c $(PRINTF_PATH)print_str.c \
				$(PRINTF_PATH)print_uint.c

LIBFT_OBJECTS = $(LIBFT_SRC:.c=.o)
PRINTF_OBJECTS = $(PRINTF_SRC:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -I../

all: $(NAME)

$(NAME): $(LIBFT_OBJECTS) $(PRINTF_OBJECTS)
	@ar -rcs $(NAME) $(LIBFT_OBJECTS) $(PRINTF_OBJECTS)

$(LIBFT_PATH)%.o: $(LIBFT_PATH)%.c ../libft_plus.h
	@$(CC) $(CFLAGS) -c $< -o $@
	
$(PRINTF_PATH)%.o: $(PRINTF_PATH)%.c ../libftprintf.h
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(LIBFT_OBJECTS) $(PRINTF_OBJECTS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
