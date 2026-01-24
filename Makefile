NAME = cub3D
SRCDIR = src
OBJDIR = obj
INCDIR = include
MLXDIR = MLX42/MLX42
LIBFTDIR = ./libft
SRC_F = init.c cleanup.c main.c \
       map.c map_check.c utils.c path.c \
       render.c hooks.c player.c
SRCS = $(addprefix $(SRCDIR)/, $(SRC_F))
OBJS = $(addprefix $(OBJDIR)/, $(SRC_F:.c=.o))
INCLUDE = -I$(INCDIR) -I$(MLXDIR)/include -I$(LIBFTDIR) -I./
LIBFT = $(LIBFTDIR)/libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
MLX_LIB = $(MLXDIR)/libmlx42.a -lglfw -ldl -lm

all: $(NAME)
$(OBJDIR):
	mkdir -p $(OBJDIR)
$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@
$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX_LIB) -o $(NAME)
$(LIBFT):
	@make -C $(LIBFTDIR) --no-print-directory
clean:
	@rm -rf $(OBJDIR)
	@make -C $(LIBFTDIR) clean --no-print-directory
fclean: clean
	@rm -rf $(NAME)
	@make -C $(LIBFTDIR)  fclean --no-print-directory
re: fclean all
.PHONY: all clean fclean re libft