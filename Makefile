CC = clang
CFLAGS = -Wall -Werror -Wextra -Iminilibx_linux

EXEC = game.out
MLX_LIB = ./minilibx_linux/libmlx_Linux.a

SRCS = ./src/main.c

OBJS = ${SRCS:.c=.o}

all : compile

compile: $(OBJS)
	$(CC) $(OBJS) ${MLX_LIB} -lXext -lX11 -lm -lz -o ${EXEC}

%.o : %.c
	$(CC) ${CFLAGS} -c $< -o $@

run : compile ${EXEC}
	./${EXEC}

dev : compile ${EXEC}
	valgrind --leak-check=full --show-leak-kinds=all ./${EXEC}

clean :
	rm -rf ${OBJS}

fclean : clean
	rm -rf ${EXEC}

.PHONY : run compile all dev