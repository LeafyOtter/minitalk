#
#	Makefile
#	by wind
#	<loutre@courrier.dev>
#	22/07/21 16:38:39
#	22/07/21 19:41:03
#

MAKEFLAGS	+=	--silent

NAME	=	client

CC		=	clang
CFLAGS	=	-Wall -Wextra -Werror
IFLAGS	=	-I./../includes/

SRCS	=	client.c

all:	$(NAME)

$(NAME):
	$(CC) $(CFLAGS) $(SRCS) -c $(IFLAGS)
	$(CC) $(CFLAGS) $(SRCS:.c=.o) -o $@ $(IFLAGS)

clean:
	rm -f $(SRCS:.c=.o)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY:	all $(NAME) clean fclean re
