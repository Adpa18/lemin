##
## Makefile for Makefile in /home/wery_a/rendu/RayTracer/rtv1
## 
## Made by adrien wery
## Login   <wery_a@epitech.net>
## 
## Started on  Tue Feb  3 16:12:36 2015 adrien wery
## Last update Sat May  2 21:27:22 2015 consta_n
##

SRC	= main.c 		\
	  str_write.c		\
	  get.c			\
	  str_op.c		\
	  my_get_next_line.c	\
	  struct.c		\
	  str_to_wordtab.c	\
	  can_go.c		\
	  set_tab.c		\
	  add_node.c		\
	  free.c		\
	  lem_in.c

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
