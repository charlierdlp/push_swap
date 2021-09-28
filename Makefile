GNL		= gnl/get_next_line.c
SRCS	= ${GNL} instructions.c push_swap.c utils.c write_do.c radix_sort.c parser.c
OBJS	= ${SRCS:.c=.o}
NAME	= push_swap
CC		= gcc
RM		= rm -f
CFLAGS	= -Wall -Werror -Wextra
SANITIZE = -g -fsanitize=address
%.o: %.c
	${CC} ${CFLAGS} -g -c $< -o $@

${NAME}:	${OBJS}
				make bonus -C libft/
				cp libft/libft.a ${NAME}
				${CC} ${CFLAGS} -g -L libft/ -lft $^ -o ${NAME}

all:		${NAME}

clean:
				${RM} ${OBJS}
				make clean -C libft/

fclean:		clean
				${RM} ${NAME}
				make fclean -C libft/

re:			fclean all

.PHONY:		all clean fclean re