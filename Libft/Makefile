# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yulpark <yulpark@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/12 21:12:39 by flima             #+#    #+#              #
#    Updated: 2025/04/04 20:16:54 by yulpark          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

RESET   = \033[0m
GREEN   = \033[32m

CC= cc

OBJ_DIR = objs
CFLAGS = -Wall -Wextra -Werror -g -I../includes

SRCS = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c \
		ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c \
		ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c \
		ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c \
		ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c \
		ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c \
		ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c ft_isspace.c\
		ft_lstadd_back_bonus.c ft_lstadd_front_bonus.c ft_lstclear_bonus.c \
		ft_lstdelone_bonus.c ft_lstiter_bonus.c ft_lstlast_bonus.c \
		ft_lstmap_bonus.c ft_lstnew_bonus.c ft_lstsize_bonus.c ft_atol.c\
		get_next_line.c get_next_line_utils.c \
		ft_utils.c ft_nbr_tohex.c ft_printf.c \

OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:%.c=%.o))

AR = ar rcs

all: $(NAME)

$(NAME): $(OBJS)
	@$(AR) $(NAME) $(OBJS)
	@echo "\n$(GREEN)Library created!$(RESET)\n"

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY:	 all clean fclean re
