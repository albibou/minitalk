SERV_SRCS	= ./src/server.c

SERV_OBJS	= ${SERV_SRCS:.c=.o}

CLIENT_SRCS	= ./src/client.c

CLIENT_OBJS	= ${CLIENT_SRCS:.c=.o}


LIBFT	= libft/libft.a

INCLUDES	= includes/

RM	= rm -f

CC	= cc

CFLAGS	= -Wall -Werror -Wextra

NAME	= server

NAME2	= client

.DEFAULT_GOAL := all

.c.o :	
		${CC} ${CFLAGS} -I ${INCLUDES} -c $< -o ${<:.c=.o}

${NAME} :	${SERV_OBJS}
		clear
		@toilet -f pagga.tlf --gay "Libft"
		make all -C libft
		clear
		${CC} -o ${NAME} ${CFLAGS} -g  ${SERV_OBJS} ${LIBFT}
		clear
	        @toilet -f pagga.tlf --gay "Enjoy ${NAME} !"

${NAME2} :	${CLIENT_OBJS}
		clear
		@toilet -f pagga.tlf --gay "Libft"
		make all -C libft
		clear
		${CC} -o ${NAME2} ${CFLAGS} -g  ${CLIENT_OBJS} ${LIBFT}
		clear
	        @toilet -f pagga.tlf --gay "Enjoy ${NAME2} !"
	
all :		${NAME} ${NAME2}
		clear
		@toilet -f pagga.tlf --gay "Enjoy Minitalk !"

clean :
		${RM} ${SERV_OBJS}
		${RM} ${CLIENT_OBJS}
		make clean -C libft

fclean :	clean
		make fclean -C libft
		${RM} ${NAME}
		${RM} ${NAME2}

re :		fclean all

.PHONY :	all clean fclean re
