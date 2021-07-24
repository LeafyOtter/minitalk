#
#	Makefile
#	by wind
#	<loutre@courrier.dev>
#	22/07/21 16:30:53
#	22/07/21 22:05:40
#

MAKEFLAGS	+=	--silent

NAME		=	minitalk
SNAME		=	server
CNAME		=	client
SNAME_DIR	=	server_srcs
CNAME_DIR	=	client_srcs

all : $(NAME)

$(NAME) :
	$(MAKE) -C $(SNAME_DIR) $(SNAME)
	$(MAKE) -C $(CNAME_DIR) $(CNAME)
	cp $(SNAME_DIR)/$(SNAME) .
	cp $(CNAME_DIR)/$(CNAME) .

bonus:
	$(MAKE) -C $(SNAME_DIR) bonus
	$(MAKE) -C $(CNAME_DIR) $(CNAME)
	cp $(SNAME_DIR)/$(SNAME) .
	cp $(CNAME_DIR)/$(CNAME) .

clean	:
	$(MAKE) -C $(SNAME_DIR) clean
	$(MAKE) -C $(CNAME_DIR) clean

fclean	:
	$(MAKE) -C $(SNAME_DIR) fclean
	$(MAKE) -C $(CNAME_DIR) fclean
	rm -rf $(SNAME) $(CNAME)

re	: fclean all
