/*
** struct.c for struct in /home/wery_a/rendu/CPE/Lem-In/Test/v1
** 
** Made by Adrien WERY
** Login   <wery_a@epitech.net>
** 
** Started on  Sat Apr 25 15:05:35 2015 Adrien WERY
** Last update Tue May  5 17:39:21 2015 consta_n
*/

#include "lem_in.h"

t_lem		*init_lem()
{
  t_lem		*lem;

  if ((lem = malloc(sizeof(t_lem))) == NULL)
    {
      my_error("struct.c : 17 Malloc Failed", -1);
      return (NULL);
    }
  if ((lem->room = malloc(sizeof(t_room))) == NULL)
    {
      my_error("struct.c : 22 Malloc Failed", -1);
      return (NULL);
    }
  lem->start = NULL;
  lem->end = NULL;
  lem->nb_ant = 0;
  lem->room->name = NULL;
  lem->room->next = NULL;
  lem->room->weight = -1;
  lem->room->road = 1;
  lem->link = NULL;
  return (lem);
}

int		add_room(t_room **rooms, char *name, char cmd)
{
  t_room	*room;
  t_room	*tmp;

  tmp = *rooms;
  while (tmp)
    {
      if (!my_strcmp(name, tmp->name))
	return (my_error("Room already exist", - 1));
      tmp = tmp->next;
    }
  if ((room = malloc(sizeof(t_room))) == NULL)
    return (my_error("struct.c : 45 Malloc Failed -> add_room", -1));
  if ((room->name = my_strdup(name)) == NULL)
    return (my_error("struct.c : 47 my_strdup Failed -> add_room", -1));
  if (cmd == 1)
    room->weight = 0;
  else
    room->weight = -1;
  room->road = 0;
  room->ant = NULL;
  room->next = *rooms;
  *rooms = room;
  return (0);
}

int		add_link(t_link **links, char *room1, char *room2)
{
  t_link	*link;

  if ((link = malloc(sizeof(t_link))) == NULL)
    return (my_error("struct.c : 60 Malloc Failed", -1));
  if ((link->room1 = my_strdup(room1)) == NULL)
    return (my_error("struct.c : 62 my_strdup Failed", -1));
  if ((link->room2 = my_strdup(room2)) == NULL)
    return (my_error("struct.c : 62 my_strdup Failed", -1));
  link->next = *links;
  *links = link;
  return (0);
}

int		add_path(t_path **paths, char *name)
{
  static int	i = 0;
  t_path	*path;

  if ((path = malloc(sizeof(t_path))) == NULL)
    return (my_error("struct.c : 60 Malloc Failed", -1));
  path->name = name;
  path->next = *paths;
  path->prev = NULL;
  if (i != 0)
    path->next->prev = path;
  *paths = path;
  i = 1;
  return (0);
}

void		show(t_room *room, t_link *link, int *rooms, int *paths)
{
  t_room	*tmp1;
  t_link	*tmp2;

  tmp1 = room;
  tmp2 = link;
  while (tmp1)
    {
      tmp1 = tmp1->next;
      ++(*rooms);
    }
  while (tmp2)
    {
      tmp2 = tmp2->next;
      ++(*paths);
    }
}
