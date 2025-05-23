# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: filipe <filipe@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/10 20:28:14 by flima             #+#    #+#              #
#    Updated: 2025/04/26 23:33:49 by filipe           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

RESET   = \033[0m
GREEN   = \033[32m
YELLOW  = \033[33m
BLUE    = \033[34m

CFLAGS = -Wall -Werror -Wextra -g CFLAGS += -fsanitize=address

LIBFT_DIR = Libft
LIBFT = $(LIBFT_DIR)/libft.a

MLX = mlx/libmlx.a
MLX_FLAGS = -I$(INCLUDES_DIR) -L./mlx -lmlx -lX11 -lXext -lm

INCLUDE = includes
HEADERS = $(INCLUDE)/libft.h \


SCRS_DIR = srcs
SRCS_FILES = 

OBJS_DIR = objs
OBJS = $(patsubst $(SCRS_DIR)/%.c,$(OBJS_DIR)/%.o,$(SRC_FILES))

all: $(NAME)

$(NAME): $(LIBFT) $(MLX) $(OBJS) Makefile
	@$(CC) $(CFLAGS) $(MLX_FLAGS) $(OBJS) $(LIBFT) -I$(INCLUDE) -lreadline -o $(NAME)
	@echo "\n$(GREEN)minishell  ✅$(RESET)\n"

$(OBJS_DIR)/%.o: $(SCRS_DIR)/%.c $(HEADERS)
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) $(MLX_FLAGS) -I$(INCLUDE) -c $< -o $@
	@echo "$(GREEN)Compiling: $< into $@$(RESET)"

$(LIBFT):
	@$(MAKE) --no-print-directory -C $(LIBFT_DIR)

$(MLX):
	@if [ ! -d "mlx" ]; then \
    git clone https://github.com/42Paris/minilibx-linux.git mlx; \
	fi
	@$(MAKE) -C mlx
	
clean:
	@$(MAKE) --no-print-directory clean -C Libft mlx
	@if [ -d $(OBJS_DIR) ]; then \
		echo "$(YELLOW)Object files have been removed   ✅$(RESET)"; \
	fi
	@rm -rf $(OBJS_DIR)

fclean: clean
	@$(MAKE) --no-print-directory fclean -C Libft mlx
	@rm -f $(NAME)
	@echo "$(YELLOW)Executable file has been removed ✅$(RESET)"

re: fclean all
	@echo "$(GREEN)Rebuild complete! All files cleaned and recompiled ✅$(RESET)\n"
.PHONY: all clean fclean re
