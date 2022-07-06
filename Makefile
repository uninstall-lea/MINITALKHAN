CFLAGS =	-Wall -Wextra -Werror -g3 -I.
SERVER =	server
CLIENT =	client
LIBPATH =	srcs/libft/
LIB =		libft.a

SRC_S =		srcs/serv/main_server.c	\
			srcs/common/error.c			

SRC_C =		srcs/cli/main_client.c	\
			srcs/common/error.c			

OBJ_S =		$(SRC_S:.c=.o)

OBJ_C = 	$(SRC_C:.c=.o)

all : 		$(LIB) $(SERVER) $(CLIENT)

$(LIB) :
			make -C $(LIBPATH)

$(SERVER) :	$(OBJ_S)
			gcc $(CFLAGS) $(OBJ_S) -o $(SERVER) $(LIBPATH)$(LIB)

$(CLIENT) :	$(OBJ_C)
			gcc $(CFLAGS) $(OBJ_C) -o $(CLIENT) $(LIBPATH)$(LIB)

clean :		
			rm -f $(OBJ_S) $(OBJ_C)
			make -C $(LIBPATH) clean

fclean :	clean
			rm -f $(SERVER) $(CLIENT)
			make -C $(LIBPATH) fclean

re :		fclean all

.PHONY :	all clean fclean re
