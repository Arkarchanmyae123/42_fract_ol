# --- Variables ---
NAME    = fractol
CC      = cc
CFLAGS  = -Wall -Wextra -Werror

# --- MinilibX Variables ---
MLX_DIR = ./minilibx-linux
MLX_INC = -I $(MLX_DIR)
MLX_LNK = -L $(MLX_DIR) -lmlx -lXext -lX11 -lm

# --- Files ---
SRCS    = julia.c julia_event.c julia_render.c 
OBJS    = $(SRCS:.c=.o)

# --- Rules ---

# Default target
all: $(NAME)

# Compile MinilibX first, then link the object files into the final executable
$(NAME): $(OBJS)
	@make -C $(MLX_DIR)
	$(CC) $(CFLAGS) $(OBJS) $(MLX_LNK) -o $(NAME)

# Compile each .c file into a .o (object) file 
%.o: %.c
	$(CC) $(CFLAGS) $(MLX_INC) -c $< -o $@

# Remove object files and clean MinilibX
clean:
	rm -f $(OBJS)
	@make clean -C $(MLX_DIR)

# Remove object files AND the executable
fclean: clean
	rm -f $(NAME)

# Rebuild everything from scratch
re: fclean all

# Tell Make these aren't real files
.PHONY: all clean fclean re