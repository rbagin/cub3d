NAME = cub3D
SRCDIR = src
OBJDIR = obj
INCDIR = include
MLXDIR = MLX42/MLX42
LIBFTDIR = ./libft
SRC_F = init.c cleanup.c main.c \
       map_load.c \
       map_check.c \
       utils.c \
       path.c \
       render.c \
       hooks.c \
       player.c
SRCS = $(addprefix $(SRCDIR)/, $(SRC_F))
OBJS = $(addprefix $(OBJDIR)/, $(SRC_F:.c=.o))
INCLUDE = -I$(INCDIR) -I$(MLXDIR)/include -I$(LIBFTDIR) -I./
LIBFT = $(LIBFTDIR)/libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
MLX_LIB = $(MLXDIR)/build/libmlx42.a -lglfw -ldl -lm
MLX_A = $(MLXDIR)/build/libmlx42.a

all: $(NAME)
$(OBJDIR):
	mkdir -p $(OBJDIR)
$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@
$(NAME): $(OBJS) $(LIBFT) $(MLX_A)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX_LIB) -o $(NAME)
$(LIBFT):
	@make -C $(LIBFTDIR) --no-print-directory

$(MLX_A):
	@cmake -S $(MLXDIR) -B $(MLXDIR)/build
	@make -C $(MLXDIR)/build -j4

clean:
	@rm -rf $(OBJDIR)
	@make -C $(LIBFTDIR) clean --no-print-directory
fclean: clean
	@rm -rf $(NAME)
	@make -C $(LIBFTDIR)  fclean --no-print-directory

TEST_NAME = test_ray
TEST_SRC = $(SRCDIR)/testing/test_raycasting.c \
	$(SRCDIR)/raycasting.c \
	$(SRCDIR)/render.c \
	$(SRCDIR)/player_movement_utils.c \
	$(SRCDIR)/player_movement.c \
	$(SRCDIR)/player_rotation.c
TEST_INCLUDE = -I includes -I $(LIBFTDIR) -I $(MLXDIR)/include

test: $(LIBFT) $(MLX_A)
	$(CC) $(CFLAGS) $(TEST_SRC) $(TEST_INCLUDE) $(LIBFT) $(MLX_LIB) -o $(TEST_NAME)
	./$(TEST_NAME)

test_clean:
	@rm -f $(TEST_NAME)

re: fclean all
.PHONY: all clean fclean re libft test test_clean
