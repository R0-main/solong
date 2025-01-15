NAME=libftprintf.a

CC=cc
CFLAGS=-Wall -Werror -Wextra

SRCS=./src/ft_printf.c\
		./src/ft_unsigned_putnbr.c\
		./src/ft_print_hex.c\
		./src/processing/address.c\
		./src/processing/char.c\
		./src/processing/hex.c\
		./src/processing/num.c\
		./src/processing/str.c\
		./src/processing/unsigned_num.c\

OBJS=${SRCS:.c=.o}
LIBFT=../libft/libft.a

INCLUDES_PATH=./includes

all : ${NAME}

${NAME} : ${LIBFT} ${OBJS}
	cp ../libft/libft.a $@
	ar rcs $@ ${OBJS}

${LIBFT} :
	make -C ../libft --no-print-directory

%.o : %.c
	${CC} ${CFLAGS} -I${INCLUDES_PATH} -c $< -o $@

re: fclean all

libft_clean:
	make fclean -C ../libft --no-print-directory

libft_fclean:
	make fclean -C ../libft --no-print-directory

clean: libft_clean
	rm -rf ${OBJS}
	rm -rf ${TESTS_FAKE_OUT} ${TESTS_REAL_OUT}
	rm -rf ${TESTS_WRITTEN_FILE_A} ${TESTS_WRITTEN_FILE_B}

fclean: clean libft_fclean
	rm -rf ${NAME}

.PHONY: check fclean clean libft_fclean libft_clean re all test
