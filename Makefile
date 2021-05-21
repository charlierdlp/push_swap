SRCS	= checker.c
OBJS	= ${SRCS:.c=.o}
NAME	= checker
CC		= gcc
RM		= rm -f
CFLAGS	= -Wall -Werror -Wextra
SANITIZE = -g -fsanitize=address
%.o: %.c
	${CC} -c $< -o $@

${NAME}:	${OBJS}
				make bonus -C libft/
				cp libft/libft.a ${NAME}
				${CC} -L libft/ -lft $^ -o ${NAME}

all:		${NAME}

clean:
				${RM} ${OBJS}
				make clean -C libft/

fclean:		clean
				${RM} ${NAME}
				make fclean -C libft/

re:			fclean all

.PHONY:		all clean fclean re