##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

NAME	= ai

CC	= gcc

RM	= rm -f

SRC	= src/*.c

OBJ	= $(SRC:.c=.o)

LIBFLAG	= -L ./lib/my/ -lmy

all: $(NAME)

$(NAME):
	cd lib/my && make
	$(CC) $(SRC) -o $(NAME) $(LIBFLAG)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
