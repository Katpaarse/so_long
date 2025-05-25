NAME = so_long
SRCS = src/main.c src/parsing/parse_map.c src/parsing/validate_map.c src/utils.c src/parsing/flood_fill.c src/game_intializer.c
OBJS = $(SRCS:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I./MLX42/include -I./src/libft -I./include
LDFLAGS = -LMLX42/build -lmlx42 -lglfw -ldl -lm -lpthread -Lsrc/libft -lft

MLX_DIR = MLX42
MLX_BUILD_DIR = $(MLX_DIR)/build

LIBFT_DIR = src/libft
LIBFT_LIB = $(LIBFT_DIR)/libft.a

all: $(MLX_BUILD_DIR)/libmlx42.a $(LIBFT_LIB) $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LDFLAGS)

$(MLX_BUILD_DIR)/libmlx42.a:
	cmake -S $(MLX_DIR) -B $(MLX_BUILD_DIR)
	cmake --build $(MLX_BUILD_DIR) -j4

$(LIBFT_LIB):
	$(MAKE) -C $(LIBFT_DIR)

clean:
	rm -f $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

fcleanall: fclean
	rm -rf $(MLX_BUILD_DIR)

re: fclean all

.PHONY: all clean fclean fcleanall re