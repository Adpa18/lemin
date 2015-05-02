/*
** lem_in.h for lem_in in /home/wery_a
** 
** Made by adrien wery
** Login   <wery_a@epitech.net>
** 
** Started on  Fri Apr  3 17:46:37 2015 adrien wery
** Last update Sat May  2 21:46:53 2015 consta_n
*/

#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
# define BUFF_SIZE 1024

typedef struct		link_s
{
  char			*room1;
  char			*room2;
  struct link_s		*next;
}			link_t;

typedef struct		room_s
{
  char			*name;
  int			x;
  int			y;
  int			id;
  struct room_s		*next;
}			room_t;

typedef struct		lem_s
{
  room_t		*room;
  link_t		*link;
  char			**paths;
  char			*start;
  char			*end;
  int			nb_ant;
}			lem_t;

typedef struct		s_weight
{
  char			*name;
  int			weight;
  char			parcour;
  struct s_weight	*next;
}			t_weight;

typedef struct		s_ant
{
  char			*name;
  char			ant;
  struct s_ant		*next;
}			t_ant;

/* STR_WRITE FUNCTIONS */
void    my_putchar(char c);
int     my_str(char *s, int mode);
void    my_putnbr(int nb);
int	my_error(char *s, int error);
void	free_double(char **tab);

/* STR_OP FUNCTIONS */
int     my_strcmp(char *s1, char *s2);
int     my_strncmp(char *s1, char *s2, int nb);
char    *my_strdup(char *s);
void    my_memset(char *s, char c, int size);
char	*epur_str(char *s);

/* GET && MALLOC FUNCTIONS */
char    **my_str_to_wordtab(char *s, char sp, int i);
char	*get_next_line(int fd);
int     my_getnbr_base(char *s, char *base);
char    *my_malloc(int len);
char    *my_re_alloc(char *s);

/* STRUCT FUNCTIONS */
lem_t   *init_lem();
int	add_room(room_t **rooms, char *name, int x, int y);
int     add_link(link_t **links, char *room1, char *room2);
void    show(room_t *room, link_t *link, int *rooms, int *paths);
void	free_struct(lem_t *lem);

/* CAN GO FUNCTIONS */
void    display_can_go(char *room1, char *room2, int go);
int     can_go(link_t *link, char *room1, char *room2);

int	init_weight(room_t *rooms, t_weight **weight);
int	init_ant(room_t *rooms, t_ant **ant);
int	add_weight(t_weight **weight, char *name);
int	add_ant(t_ant **ant, char *name);
int	lem_in(lem_t *lem);
void	free_tab(int **tab);
char	*my_alloc(int size);
