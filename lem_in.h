/*
** lem_in.h for lem_in in /home/wery_a
** 
** Made by adrien wery
** Login   <wery_a@epitech.net>
** 
** Started on  Fri Apr  3 17:46:37 2015 adrien wery
** Last update Tue May  5 08:06:46 2015 axel vencatareddy
*/

#ifndef LEM_IN_H_
# define LEM_IN_H_

/* INCLUDES */
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

/* DEFINES */
# define BUFF_SIZE 1024

/* STRUCTS */
typedef struct		s_link
{
  char			*room1;
  char			*room2;
  struct s_link		*next;
}			t_link;

typedef struct		s_six_int
{
  int			i;
  int			j;
  int			x;
  int			test;
  int			save;
  int			save_while;
}			t_six_int;

typedef struct		s_path
{
  char			*name;
  struct s_path		*next;
  struct s_path		*prev;
}			t_path;

typedef struct		s_room
{
  char			*name;
  int			weight;
  char			road;
  char			*ant;
  struct s_room		*next;
}			t_room;

typedef struct		s_lem
{
  t_room		*room;
  t_link		*link;
  char			**paths;
  char			*start;
  char			*end;
  int			nb_ant;
}			t_lem;

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
void	my_putchar(char c);
int	my_str(char *s, int mode);
void	my_putnbr(int nb);
void	free_double(char **tab);

/* ERROR FUNCTIONS */
int	my_error(char *str, int error);
char	*my_str_error(char *str, char *error);

/* STR_OP FUNCTIONS */
int	my_strcmp(char *s1, char *s2);
int	my_strncmp(char *s1, char *s2, int nb);
char	*my_strdup(char *s);
void	my_memset(char *s, char c, int size);
char	*epur_str(char *s);

/* MATH && MALLOC FUNCTIONS */
char	**my_str_to_wordtab(char *s, char sp, int i);
char	*get_next_line(int fd);
int	my_getnbr_base(char *s, char *base);
char	*my_malloc(int len);
char	*my_re_alloc(char *s);

/* STRUCT FUNCTIONS */
t_lem	*init_lem();
int	add_room(t_room **rooms, char *name, char cmd);
int	add_link(t_link **links, char *room1, char *room2);
void	show(t_room *room, t_link *link, int *rooms, int *paths);
void	free_struct(t_lem *lem);

/* CAN GO FUNCTIONS */
void	display_can_go(char *room1, char *room2, int go);
int	can_go(t_link *link, char *room1, char *room2);

/* GET FUNCTIONS */
int	get_path(t_room **room, t_link **link, char **tab);
int	get_struct(int fd, t_lem *lem);

/* MAIN FUNCTIONS */
char	*check_line(char *s, t_room **room, t_link **link, char cmd);
int	check_struct(t_lem *lem);

int	init_weight(t_room *rooms, t_weight **weight);
int	init_ant(t_room *rooms, t_ant **ant);
int	add_weight(t_weight **weight, char *name);
int	add_ant(t_ant **ant, char *name);
int	lem_in(t_lem *lem);
void	free_tab(int **tab);
char	*my_alloc(int size);
int	my_strcmp(char *s1, char *s2);
void	pathfinding(t_lem *lem);
int	add_path(t_path **path, char *name);

#endif /* !LEM_IN_H_ */
