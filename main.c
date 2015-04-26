/*
** main.c for main in /home/wery_a/rendu/Lem-In/Test
** 
** Made by adrien wery
** Login   <wery_a@epitech.net>
** 
** Started on  Fri Apr  3 17:32:29 2015 adrien wery
** Last update Sun Apr 26 16:55:26 2015 Adrien WERY
*/

#include <stdio.h>
#include "lem_in.h"

int	get_path(room_t **room, link_t **link, char **tab)
{
  room_t	*t1;
  room_t	*t2;

  t1 = *room;
  t2 = *room;
  while (t1 && my_strcmp(tab[0], t1->name) != 0)
    t1 = t1->next;
  while (t2 && my_strcmp(tab[1], t2->name) != 0)
    t2 = t2->next;
  free_double(tab);
  if (!t1 || !t2)
    return (my_error("Room doesn't exist", -1));
  if ( add_link(link, t1->name, t2->name) == -1)
    return (-1);
  return (0);
}

char	*check_line(char *s, room_t **room, link_t **link, char cmd)
{
  char	**tab;
  char	*name;

  if (s[0] == '#')
    return ("comment");
  name = NULL;
  if ((tab = my_str_to_wordtab(s, ' ', 0)) == NULL)
    {
      my_error("Malloc Failed in my_str_to_wordtab", -1);
      return (NULL);
    }
  if (tab[0] && tab[1] && tab[2])
    {
      if ((add_room(room, tab[0], my_getnbr_base(tab[1], "0123456789"),
		    my_getnbr_base(tab[2], "0123456789")) == -1)
	  || ((name = my_strdup(tab[0])) == NULL))
	return (NULL);
    }
  else if (get_path(room, link, my_str_to_wordtab(s, '-', 0)) == -1)
    return (NULL);
  free_double(tab);
  if (cmd == 1)
    return (name);
  free(name);
  return ("good");
}

int	check_struct(lem_t *lem)
{
  int	rooms;
  int	paths;

  if (!lem->start)
    return (my_error("No ##start in the file", -1));
  if (!lem->end)
    return (my_error("No ##end in the file", -1));
  printf("start = %s\tend = %s\tnb_ant = %d\n", lem->start, lem->end, lem->nb_ant);
  rooms = 0;
  paths = 0;
  show(lem->room, lem->link, &rooms, &paths);
  if (rooms < 2)
    return (my_error("Need 2 rooms or more", -1));
  else if (paths < rooms - 1)
    return (my_error("Some rooms aren't link", -1));
  return (0);
}

int	get_struct(int fd, lem_t *lem)
{
  char	*s;

  if ((lem->nb_ant = my_getnbr_base(epur_str(get_next_line(fd)), "0123456789")) < 0)
    return (my_error("I need some ants to play", -1));
  while ((s = epur_str(get_next_line(fd))))
    {
      if (my_strcmp("##start", s) == 0)
	{
	  free(s);
	  s = epur_str(get_next_line(fd));
	  if ((lem->start = check_line(s, &(lem->room), &(lem->link), 1)) == NULL)
	    return (-1);
	}
      if (my_strcmp("##end", s) == 0)
	{
	  free(s);
	  s = epur_str(get_next_line(fd));
	  if ((lem->end = check_line(s, &(lem->room), &(lem->link), 1)) == NULL)
	    return (-1);
	}
      else if (check_line(s, &(lem->room), &(lem->link), 0) == NULL)
	return (-1);
      free(s);
    }
  return (check_struct(lem));
}

int	parsing(char *file, char *room1, char *room2)
{
  char	go;
  int	fd;
  lem_t	*lem;

  if ((fd = open(file, O_RDONLY)) == -1)
    return (my_error("Can't Open The File", -1));
  if ((lem = init_lem()) == NULL)
    return (my_error("Can't Init the lem struct", 1));
  if (get_struct(fd, lem) == -1)
    return (my_error("Can't Get Rooms and Paths", 1));
  free_struct(lem);
  go = can_go(lem->link, room1, room2);
  display_can_go(room1, room2, go);
  return (0);
}

int	main(int argc, char **argv)
{
  if (argc < 4)
    return (my_error("\n\tUsage : ./lem_in <file_name>\n", -1));
  parsing(argv[1], argv[2], argv[3]);
  return (0);
}
