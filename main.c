/*
** main.c for main in /home/wery_a/rendu/Lem-In/Test
** 
** Made by adrien wery
** Login   <wery_a@epitech.net>
** 
** Started on  Fri Apr  3 17:32:29 2015 adrien wery
** Last update Sat Apr 25 18:18:49 2015 Adrien WERY
*/

#include <stdio.h>
#include "lem_in.h"

int	get_path(room_t **room, char **tab)
{
  room_t	*t1;
  room_t	*t2;

  t1 = *room;
  t2 = *room;
  while (t1 && my_strcmp(tab[0], t1->name) != 0)
    t1 = t1->next;
  while (t2 && my_strcmp(tab[1], t2->name) != 0)
    t2 = t2->next;
  if (!t1 || !t2)
    return (my_error("Room doesn't exist", -1));
  printf("%s link with %s\n", t1->name, t2->name);
  free_double(tab);
  return (0);
}

char	*check_line(char *s, room_t **room, char cmd)
{
  char	**tab;
  char	*name;

  if (s[0] == '#')
    return ("comment");
  name = NULL;
  tab = my_str_to_wordtab(s, ' ', 0);
  if (tab[0] && tab[1] && tab[2])
    {
      if (add_room(room, tab[0], my_getnbr_base(tab[1], "0123456789"),
		   my_getnbr_base(tab[2], "0123456789")) == -1)
	return (NULL);
      if ((name = my_strdup(tab[0])) == NULL)
	return (NULL);
    }
  else
    get_path(room, my_str_to_wordtab(s, '-', 0));
  free_double(tab);
  if (cmd == 1)
    return (name);
  free(name);
  return ("good");
}

int	get_struct(int fd, lem_t *lem)
{
  char	*s;

  while ((s = epur_str(get_next_line(fd))))
    {
      if (my_strcmp("##start", s) == 0)
	{
	  free(s);
	  s = epur_str(get_next_line(fd));
	  lem->start = check_line(s, &(lem->room), 1);
	}
      else if (my_strcmp("##end", s) == 0)
	{
	  free(s);
	  s = epur_str(get_next_line(fd));
	  lem->end = check_line(s, &(lem->room), 1);
	}
      else
	{
	  check_line(s, &(lem->room), 0);
	  free(s);
	}
    }
  show(lem->room);
  printf("start = %s\t end = %s\n", lem->start, lem->end);
  return (0);
}

int	parsing(char *file)
{
  int	fd;
  lem_t	*lem;

  if ((fd = open(file, O_RDONLY)) == -1)
    return (-1);
  lem = init_lem();
  get_struct(fd, lem);
  free_struct(lem);
  return (0);
}

int	main(int argc, char **argv)
{
  if (argc < 2)
    return (my_error("\n\tUsage : ./lem_in <file_name>\n", -1));
  parsing(argv[1]);
  return (0);
}
