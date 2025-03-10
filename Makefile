CC = gcc
# -Werror
CFLAGS = -Wall -Wextra -Iincludes -Iminilibx_linux -O3 -O2 -flto -ffast-math -march=native

EXEC = solong

MLX_LIB = ./minilibx_linux/libmlx_Linux.a
MLX_LIB_PATH = ./minilibx_linux/

DEPENDENCIES_PATH = ./src/dependencies

GNL_SRCS = $(DEPENDENCIES_PATH)/get_next_line/get_next_line.c\
		$(DEPENDENCIES_PATH)/get_next_line/get_next_line_utils.c

FT_PRINTF_PATH = ./src/dependencies/ft_printf
FT_PRINTF = ./src/dependencies/ft_printf/libftprintf.a

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
			./src/game/world/edges.c\
			./src/game/coordinates/coordinates.c\
			./src/game/entities/collectible.c\
			./src/game/entities/entities_utils.c\
			./src/game/entities/player.c\
			./src/game/entities/exit.c\
			./src/game/entities/entities.c\
			./src/game/entities/enemy.c\
		./src/game/score/score.c\
		./src/game/map/parser/parser.c\
			./src/game/map/parser/check_borders.c\
			./src/game/map/parser/check_duplicates.c\
			./src/game/map/parser/coordinates_parsing.c\
			./src/game/map/parser/path_checking.c\
			./src/game/map/map.c\
			./src/game/map/rendering.c\
			./src/game/game_ticks.c\
		./src/game/world/world.c\
			./src/game/keybinds/keybinds.c\
				./src/game/keybinds/mouse.c\
			./src/path_finding/neighbors.c\
			./src/path_finding/node_tree.c\
			./src/path_finding/path_finding.c\
			./src/path_finding/node.c\
			./src/path_finding/path_nodes.c\
		./src/utils/free_2d_buffer.c\
		./src/utils/endswith.c\
		./src/utils/maths/ft_abs.c\
		./src/utils/maths/ft_min.c\
		./src/utils/maths/ft_max.c\
		./src/utils/exit_error.c\
		./src/utils/exit_log.c\
		$(GNL_SRCS)

OBJS = $(SRCS:.c=.o)

all : $(EXEC)

$(EXEC): $(FT_PRINTF) $(MLX_LIB) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(MLX_LIB) $(FT_PRINTF) -lXext -lX11 -lm -lz -pipe -o $(EXEC)

$(MLX_LIB):
	@if [ ! -e "$($@)" ]; then \
		git clone https://github.com/42Paris/minilibx-linux.git $(shell dirname $@); \
		cd $(shell dirname $@) && ./configure && cd .. ;\
	fi;
	make re -C $(MLX_LIB_PATH) --no-print-directory

$(FT_PRINTF) :
	make re -C $(FT_PRINTF_PATH) --no-print-directory

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

run : $(EXEC) $(EXEC)
	./$(EXEC)

dev : $(EXEC) $(EXEC)
	valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all ./$(EXEC) ./maps/packman.ber
	make fclean

clean :
	rm -rf $(OBJS)
	make clean -C $(MLX_LIB_PATH) --no-print-directory
	make fclean -C $(FT_PRINTF_PATH) --no-print-directory

fclean :
	rm -rf $(OBJS)
	rm -rf $(EXEC)
	make clean -C $(MLX_LIB_PATH) --no-print-directory
	make fclean -C $(FT_PRINTF_PATH) --no-print-directory

re: fclean all

bonus : all

.PHONY : run all dev re fclean clean bonus
