##
## Makefile for Makefile in /home/wery_a/rendu/RayTracer/rtv1
## 
## Made by adrien wery
## Login   <wery_a@epitech.net>
## 
## Started on  Tue Feb  3 16:12:36 2015 adrien wery
## Last update Sat Apr 25 19:42:15 2015 Adrien WERY
##

SRC	= main.c 		\
	  str_write.c		\
	  str_op.c		\
	  get.c			\
	  struct.c		\
	  str_to_wordtab.c	\
	  can_go.c		\

CC	= gcc -g

RM	= rm -f

CFLAGS	= -W -Wall -Wextra

NAME	= lem_in

OBJ	= $(SRC:.c=.o)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(LFLAGS)

all: $(NAME)

clean:
	$(RM) $(OBJ) *~ *#

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
