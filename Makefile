##
## Makefile for Makefile in /home/wery_a/rendu/RayTracer/rtv1
## 
## Made by adrien wery
## Login   <wery_a@epitech.net>
## 
## Started on  Tue Feb  3 16:12:36 2015 adrien wery
## Last update Tue May  5 03:45:37 2015 axel vencatareddy
##

CC	= gcc -g

RM	= rm -f

CFLAGS	= -W -Wall -Wextra -ansi -pedantic

SRCS	= main.c 		\
	  str_write.c		\
	  get.c			\
	  math.c		\
	  str_op.c		\
	  my_get_next_line.c	\
	  struct.c		\
	  str_to_wordtab.c	\
	  can_go.c		\
	  set_tab.c		\
	  add_node.c		\
	  free.c		\
	  error.c		\
	  pathfinding.c		\

NAME	= lem_in

OBJS	= $(SRCS:.c=.o)

$(NAME):  $(OBJS)
	  $(CC) $(OBJS) -o $(NAME)

all:	  $(NAME)

clean:
	  $(RM) $(OBJS) *~ *#

fclean:   clean
	  $(RM) $(NAME)

re:	  fclean all

.PHONY: all clean fclean re
