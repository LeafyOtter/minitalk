#
#	Makefile
#	by fire
#	<loutre@courrier.dev>
#	25/07/21 04:41:40
#	25/07/21 05:04:02
#

NAME		= minitalk
NAME1		= server
NAME2		= client
C_FILES1	= server.c \
			  utils.c
C_FILES2	= client.c \
			  utils.c
SRCS1		= $(addprefix srcs/,$(C_FILES1))
SRCS2		= $(addprefix srcs/,$(C_FILES2))
OBJS1		= $(SRCS1:.c=.o)
OBJS2		= $(SRCS2:.c=.o)
DEPS		= $(OBJS1:.o=.d) $(OBJS2:.o=.d)
CC			= clang
CFLAGS		= -Wall -Wextra -Werror -MMD
IFLAGS		= -I ./includes

.c.o:
			$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $(<:.c=.o)

$(NAME):	$(NAME1) $(NAME2)

all:        $(NAME1) $(NAME2)

-include	$(DEPS)

$(NAME1):   $(OBJS1)
			$(CC) $(OBJS1) $(CFLAGS) -o $(NAME1)

$(NAME2):   $(OBJS2)
			$(CC) $(OBJS2) $(CFLAGS) -o $(NAME2)

bonus:      $(NAME1) $(NAME2)

clean:
			rm -f $(OBJS1) $(OBJS2) $(DEPS)

fclean:		clean
			rm -f $(NAME1) $(NAME2)

re:			fclean all

.PHONY:     all bonus clean fclean re
