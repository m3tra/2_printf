CC := gcc
CFLAGS := -Wall -Werror -Wextra -Iinc -Ilibft -g # -fsanitize=address
SRCS := $(wildcard src/*.c)
OBJS := $(subst .c,.o,${SRCS})

all: libftprintf.a

bonus: libftprintf.a

libftprintf.a: libft/libft.a ${OBJS}
	cp libft/libft.a $@
	ar rcs $@ ${OBJS}

libft/libft.a:
	make -C libft

clean:
	rm -f src/*.o
	make -C libft $@

fclean: clean
	rm -f libftprintf.a
	make -C libft $@

re: fclean all

.PHONY: all bonus fclean clean re libft/libft.a
