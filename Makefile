CFLAGS =	-Wall -Wextra -Werror -g3 -I.
EXEC1 =		server
EXEC2 =		client
LIBPATH =	libft/
LIB =		libft.a

SRCS1 =		server/main_server.c	\
			common/error.c			\

SRCS2 =		client/main_client.c	\
			common/error.c			\

OBJS1 =		$(SRCS1:.c=.o)

OBJS2 = 	$(SRCS2:.c=.o)

all : 		$(EXEC1) $(EXEC2)

$(EXEC1) :	$(OBJS1)
			gcc $(CFLAGS) $(OBJS1) -o $(EXEC1) $(LIBPATH)$(LIB)

$(EXEC2) :	$(OBJS2)
			gcc $(CFLAGS) $(OBJS2) -o $(EXEC2) $(LIBPATH)$(LIB)

clean :		
			rm -f $(OBJS1) $(OBJS2)
			make -C $(LIBPATH) clean

fclean :	clean
			rm -f $(EXEC1) $(EXEC2)
			make -C $(LIBPATH) fclean

re :		fclean all

.PHONY :	all clean fclean re
