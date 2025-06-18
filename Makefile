# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yulpark <yulpark@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/10 20:28:14 by flima             #+#    #+#              #
#    Updated: 2025/06/18 13:23:45 by yulpark          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

RESET   = \033[0m
GREEN   = \033[32m
YELLOW  = \033[33m
BLUE    = \033[34m

CFLAGS = -Wall -Werror -Wextra -g
# CFLAGS += -fsanitize=address

LIBFT_DIR = Libft
LIBFT = $(LIBFT_DIR)/libft.a

INCLUDE = include
HEADERS = $(INCLUDE)/libft.h \
			$(INCLUDE)/cub3D.h

MLX = mlx/libmlx.a
MLX_INC = -I$(INCLUDE) -Imlx
MLX_FLAGS = -L./mlx -lmlx -lX11 -lXext -lm

SRCS_DIR = srcs
PARSE_DIR = $(SRCS_DIR)/parsing
PARSE_FILES = $(PARSE_DIR)/get_map_from_map.c\
				$(PARSE_DIR)/get_texture_from_map.c\
				$(PARSE_DIR)/utils.c\
				$(PARSE_DIR)/parse.c\
				$(PARSE_DIR)/get_colors_from_map.c

RAY_ENGINE_DIR = $(SRCS_DIR)/engine_ray_casting
RAY_ENGINE_FILES = $(RAY_ENGINE_DIR)/DDA_utils.c \
					$(RAY_ENGINE_DIR)/DDA.c \
					$(RAY_ENGINE_DIR)/vetor.c

ERR_FREE_DIR = $(SRCS_DIR)/errors_n_free
ERR_FREE_FILES = $(ERR_FREE_DIR)/error_handler_msg.c\
					$(ERR_FREE_DIR)/free_all_data.c

RENDERING_DIR = $(SRCS_DIR)/rendering
RENDERING_FILES = $(RENDERING_DIR)/floor_ceiling.c\
					$(RENDERING_DIR)/window.c\
					$(RENDERING_DIR)/minimap.c

SRCS_FILES = $(PARSE_FILES) $(ERR_FREE_FILES) $(RENDERING_FILES)\
				$(RAY_ENGINE_FILES) $(SRCS_DIR)/main.c

OBJS_DIR = objs
OBJS = $(patsubst $(SRCS_DIR)/%.c,$(OBJS_DIR)/%.o,$(SRCS_FILES))

all: $(NAME)


$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c $(HEADERS) | $(MLX)
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) $(MLX_INC) -c $< -o $@
	@echo "$(GREEN)Compiling: $< into $@$(RESET)"

$(LIBFT):
	@$(MAKE) --no-print-directory -C $(LIBFT_DIR)

$(MLX):
	@if [ ! -d "mlx" ]; then \
    git clone https://github.com/42Paris/minilibx-linux.git mlx; \
	fi
	@$(MAKE) -C mlx

$(NAME): $(LIBFT) $(OBJS) Makefile $(MLX)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -lreadline $(MLX_FLAGS) -o $(NAME)
	@echo "\n$(GREEN)cub3D  ✅$(RESET)\n"

clean:
	@$(MAKE) --no-print-directory clean -C Libft
	@if [ -d $(OBJS_DIR) ]; then \
		echo "$(YELLOW)Object files have been removed   ✅$(RESET)"; \
	fi
	@rm -rf $(OBJS_DIR)

fclean: clean
	@$(MAKE) --no-print-directory fclean -C Libft
	# @$(MAKE) clean -C mlx
	@rm -f $(NAME)
	@echo "$(YELLOW)Executable file has been removed ✅$(RESET)"

re: fclean all
	@echo "$(GREEN)Rebuild complete! All files cleaned and recompiled ✅$(RESET)\n"
.PHONY: all clean fclean re
