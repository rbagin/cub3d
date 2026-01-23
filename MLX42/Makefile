NAME = testmlx42
INCLUDE = -I include -I MLX42/include/MLX42
SRCS = main.c
HEADER = MLX42.h
OBJS = $(SRCS:.c=.o)
all: $(NAME)
$(NAME): $(OBJS)
	$(CC) $(OBJS) libmlx42.a -ldl -lglfw -o $(NAME)
%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@
clean:
	rm -f $(OBJS)
fclean: clean
	rm -f $(NAME)
re : fclean all