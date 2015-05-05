##
## Makefile for Makefile in /home/wery_a/rendu/RayTracer/rtv1
## 
## Made by adrien wery
## Login   <wery_a@epitech.net>
## 
## Started on  Tue Feb  3 16:12:36 2015 adrien wery
## Last update Tue May  5 18:36:13 2015 consta_n
##

CC	= gcc -g

RM	= rm -f

CFLAGS	= -W -Wall -Wextra

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
	  show_result.c		\
	  display_dijkstra.c	\

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
