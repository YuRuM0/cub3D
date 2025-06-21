# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: flima <flima@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/10 20:28:14 by flima             #+#    #+#              #
#    Updated: 2025/06/21 17:20:02 by flima            ###   ########.fr        #
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

MLX42_DIR = MLX42
MLX42_LIB = $(MLX42_DIR)/build/libmlx42.a
MLX42_INC = -IMLX42/include

MLX_INC = -I$(INCLUDE) $(MLX42_INC)
MLX_FLAGS = -L$(MLX42_DIR)/build -lmlx42 -lglfw -ldl -lm -lGL -pthread

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
					$(RAY_ENGINE_DIR)/vetor.c \
					$(RAY_ENGINE_DIR)/player_controls.c

ERR_FREE_DIR = $(SRCS_DIR)/errors_n_free
ERR_FREE_FILES = $(ERR_FREE_DIR)/error_handler_msg.c\
					$(ERR_FREE_DIR)/free_all_data.c

RENDERING_DIR = $(SRCS_DIR)/rendering
RENDERING_FILES = $(RENDERING_DIR)/floor_ceiling.c\
					$(RENDERING_DIR)/window.c

SRCS_FILES = $(PARSE_FILES) $(ERR_FREE_FILES) $(RENDERING_FILES)\
				$(RAY_ENGINE_FILES) $(SRCS_DIR)/main.c

OBJS_DIR = objs
OBJS = $(patsubst $(SRCS_DIR)/%.c,$(OBJS_DIR)/%.o,$(SRCS_FILES))

all: $(NAME)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c $(HEADERS) | $(MLX42_LIB)
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) $(MLX_INC) -c $< -o $@
	@echo "$(GREEN)Compiling: $< into $@$(RESET)"

$(LIBFT):
	@$(MAKE) --no-print-directory -C $(LIBFT_DIR)

$(MLX42_LIB):
	@if [ ! -d "$(MLX42_DIR)" ]; then \
		echo "Cloning MLX42..."; \
		git clone https://github.com/codam-coding-college/MLX42.git $(MLX42_DIR); \
	fi
	@cmake -S $(MLX42_DIR) -B $(MLX42_DIR)/build
	@cmake --build $(MLX42_DIR)/build

$(NAME): $(LIBFT) $(OBJS) Makefile $(MLX42_LIB)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX42_LIB) $(MLX_FLAGS) -o $(NAME)
	@echo "\n$(GREEN)cub3D  ✅$(RESET)\n"

clean:
	@$(MAKE) --no-print-directory clean -C $(LIBFT_DIR)
	@if [ -d $(OBJS_DIR) ]; then \
		echo "$(YELLOW)Object files have been removed   ✅$(RESET)"; \
	fi
	@rm -rf $(OBJS_DIR)

fclean: clean
	@$(MAKE) --no-print-directory fclean -C $(LIBFT_DIR)
	@rm -f $(NAME)
	@echo "$(YELLOW)Executable file has been removed ✅$(RESET)"

re: fclean all
	@echo "$(GREEN)Rebuild complete! All files cleaned and recompiled ✅$(RESET)\n"

.PHONY: all clean fclean re
