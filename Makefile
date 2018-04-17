##
## EPITECH PROJECT, 2017
## 
## File description:
## Makefile
##

CC	=	gcc -g3

NAME	=	bsq

SRC	=	basics.c		\
		my_str_to_word_array.c	\
		squaresort.c		\
		my_getnbr.c		\
		used.c			\
		bsq.c			\

RM	=	rm -f

OBJS	=	$(SRC:.c=.o)

CFLAGS	=	-Wextra -Wall

all:	$(NAME)

$(NAME):	$(OBJS)
		$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
		$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re:	fclean	all

.PHONY:	all clean fclean re
