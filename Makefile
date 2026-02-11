NAME = cub3D

SRCDIR = src
OBJDIR = obj
INCDIR = includes
MLXDIR = MLX42
LIBFTDIR = ./libft

SRC_BOTH = grid.c \
		init_game.c \
		main.c \
		hooks.c \
		map_load.c \
		map_header.c \
		player_movement_utils.c \
		player_movement.c \
		raycasting.c \
		render.c \
		rgb.c \
		tex_utils.c \
		textures.c \
		split_pars.c \
		start_player.c \
		validation.c \
		cleanup.c \
		utils_pars.c
SRC_BNS = bonus_mouse.c \
		bonus_minimap.c \
		bonus_doors.c \
		bonus_sprites.c \
		draw_mini.c \
		draw_spr.c
SRC_SHARED = player_rotation.c
ifdef WITH_BONUS
	FILES = $(SRC_BOTH) $(SRC_BNS)
else
	FILES = $(SRC_BOTH) $(SRC_SHARED)
endif
#path generation
SRCS = $(addprefix $(SRCDIR)/, $(FILES))
OBJS = $(addprefix $(OBJDIR)/, $(FILES:.c=.o))

INCLUDE = -I$(INCDIR) -I$(MLXDIR)/include -I$(LIBFTDIR) -I./
LIBFT = $(LIBFTDIR)/libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
MLX_LIB = $(MLXDIR)/build/libmlx42.a -lglfw -ldl -pthread -lm
MLX_A = $(MLXDIR)/build/libmlx42.a

all: $(NAME)
bonus: fclean
	@make WITH_BONUS=1 all

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
re: fclean all

.PHONY: all clean fclean re libft test test_clean
