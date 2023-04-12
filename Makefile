SERV_SRCS	= ./src/server.c \
		  ./src/server_utils.c

SERV_OBJS	= ${SERV_SRCS:.c=.o}

CLIENT_SRCS	= ./src/client.c

CLIENT_OBJS	= ${CLIENT_SRCS:.c=.o}

SERV_BONUS_SRCS	= ./bonus/server_bonus.c

SERV_BONUS_OBJS	=  ${SERV_BONUS_SRCS:.c=.o}

CLIENT_BONUS_SRCS	= ./bonus/client_bonus.c

CLIENT_BONUS_OBJS	= ${CLIENT_BONUS_SRCS:.c=.o}

LIBFT	= libft/libft.a

INCLUDES	= includes/

RM	= rm -f

CC	= cc

CFLAGS	= -Wall -Werror -Wextra

NAME	= server

NAME2	= client

BONUS_NAME = server_bonus

BONUS_NAME2 = client_bonus

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

${BONUS_NAME} :	${SERV_BONUS_OBJS}
		make all -C libft
		${CC} -o ${BONUS_NAME} ${CFLAGS} -g ${SERV_BONUS_OBJS} ${LIBFT}
		clear
		@toilet -f pagga.tlf --gay "Enjoy ${BONUS_NAME}"

${BONUS_NAME2} :	${CLIENT_BONUS_OBJS}
			make all -C libft
			${CC} -o ${BONUS_NAME2} ${CFLAGS} -g ${CLIENT_BONUS_OBJS} ${LIBFT}
			clear
			@toilet -f pagga.tlf --gay "Enjoy ${BONUS_NAME2}"

all :		${NAME} ${NAME2}
		clear
		@toilet -f pagga.tlf --gay "Enjoy Minitalk !"


bonus :		${BONUS_NAME} ${BONUS_NAME2}
		clear
		@toilet -f pagga.tlf --gay "Enjoy Bonuses !"

clean :
		${RM} ${SERV_OBJS}
		${RM} ${CLIENT_OBJS}
		${RM} ${SERV_BONUS_OBJS}
		${RM} ${CLIENT_BONUS_OBJS}
		make clean -C libft

fclean :	clean
		make fclean -C libft
		${RM} ${NAME}
		${RM} ${NAME2}
		${RM} ${BONUS_NAME}
		${RM} ${BONUS_NAME2}

re :		fclean all

.PHONY :	all clean fclean re
