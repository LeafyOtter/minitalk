#
#	Makefile
#	by wind
#	<loutre@courrier.dev>
#	22/07/21 16:50:42
#	22/07/21 18:07:16
#

MAKEFLAGS	+=	--silent

NAME	=	server

CC		=	clang
CFLAGS	=	-Wall -Wextra -Werror
IFLAGS	=	-I./../includes/

SRCS	=	server.c

all:	$(NAME)

$(NAME):
	$(CC) $(CFLAGS) $(SRCS) -c $(IFLAGS)
	$(CC) $(CFLAGS) $(SRCS:.c=.o) -o $@ $(IFLAGS)

bonus:
	$(CC) $(CFLAGS) -D BONUS=1 $(SRCS) -c $(IFLAGS)
	$(CC) $(CFLAGS) -D BONUS=1 $(SRCS:.c=.o) -o $(NAME) $(IFLAGS)

clean:
	rm -f $(SRCS:.c=.o)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY:	all $(NAME) clean fclean re
