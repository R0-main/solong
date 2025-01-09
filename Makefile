CC = clang
CFLAGS = -Iincludes

EXEC = game.out
MLX_LIB = ./minilibx_linux/libmlx_Linux.a

DEPENDENCIES_PATH = ./src/dependencies

GNL_SRCS = $(DEPENDENCIES_PATH)/get_next_line/get_next_line.c\
		$(DEPENDENCIES_PATH)/get_next_line/get_next_line_utils.c

SRCS = ./src/main.c\
			./src/mlx_wrapper/animations/animations.c\
			./src/mlx_wrapper/animations/animations_loader.c\
			./src/mlx_wrapper/animations/animation_frame.c\
				./src/mlx_wrapper/rendering/rendering.c\
				./src/mlx_wrapper/rendering/rendering_buffer.c\
				./src/mlx_wrapper/rendering/rendering_queue.c\
			./src/mlx_wrapper/free_all.c\
			./src/mlx_wrapper/mlx_vars.c\
			./src/mlx_wrapper/images_utils.c\
			./src/mlx_wrapper/textures/textures.c\
				./src/mlx_wrapper/textures/textures_loader.c\
		./src/game/game.c\
			./src/game/coordinates/coordinates.c\
		./src/game/map/parser.c\
			./src/game/map/map.c\
			./src/game/map/rendering.c\
			./src/game/map/backtracking.c\
		./src/game/world/world.c\
			./src/game/keybinds/keybinds.c\
				./src/game/keybinds/mouse.c\
		./src/utils/free_2d_buffer.c\
		./src/utils/endswith.c\
		./src/utils/delay.c\
		./src/utils/maths/ft_abs.c\
		./src/utils/exit_error.c\
		$(GNL_SRCS)

OBJS = ${SRCS:.c=.o}

# also compile libft
FT_PRINTF_PATH = ./src/dependencies/ft_printf
FT_PRINTF = ./src/dependencies/ft_printf/libftprintf.a

all : compile

compile: $(OBJS) $(FT_PRINTF)
	$(CC) $(OBJS) ${MLX_LIB} $(FT_PRINTF) -lXext -lX11 -lm -lz -O3 -O2 -flto -ffast-math -march=native -pipe -o ${EXEC}

%.o : %.c
	$(CC) ${CFLAGS} -c $< -o $@

${FT_PRINTF} :
	make re -C $(FT_PRINTF_PATH) --no-print-directory
	cp $(FT_PRINTF) $@

run : compile ${EXEC}
	./${EXEC}

dev : compile ${EXEC}
	valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all ./${EXEC} ./maps/packman.ber
	make fclean

clean_lib :
	make flcean -C $(FT_PRINTF_PATH) --no-print-directory

clean :
	rm -rf ${OBJS}

fclean : clean
	rm -rf ${EXEC}

.PHONY : run compile all dev
