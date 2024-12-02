CC = clang
CFLAGS = -Wall -Werror -Wextra -I./MLX42/MLX42 -ldl -lglfw -pthread -lm 

# MLX_LIB = ./MLX42/build/libmlx42.a

SRCS = ./src/main.c

OBJS = ${SRCS:.c=.o}

all : compile
	
compile: $(OBJS)
	$(CC) $(OBJS) ./minilibx_linux/libmlx_Linux.a -lXext -lX11 -Iminilibx_linux -lm -lz 

%.o : %.c
	$(CC) -Wall -Wextra -Werror -Iminilibx_linux -Iminilibx_linux -O3 -c $< -o $@