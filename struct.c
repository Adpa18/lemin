/*
** struct.c for struct in /home/wery_a/rendu/CPE/Lem-In/Test/v1
** 
** Made by Adrien WERY
** Login   <wery_a@epitech.net>
** 
** Started on  Sat Apr 25 15:05:35 2015 Adrien WERY
** Last update Sat Apr 25 20:14:59 2015 Adrien WERY
*/

#include "lem_in.h"

lem_t	*init_lem()
{
  lem_t	*lem;

  if ((lem = malloc(sizeof(lem_t))) == NULL)
    {
      my_error("struct.c : 17 Malloc Failed", -1);
      return (NULL);
    }
  if ((lem->room = malloc(sizeof(room_t))) == NULL)
    {
      my_error("struct.c : 22 Malloc Failed", -1);
      return (NULL);
    }
  if ((lem->link = malloc(sizeof(link_t))) == NULL)
    {
      my_error("struct.c : 27 Malloc Failed", -1);
      return (NULL);
    }
  lem->room->name = NULL;
  lem->room->x = 0;
  lem->room->y = 0;
  lem->room->next = NULL;
  lem->link->room1 = NULL;
  lem->link->room2 = NULL;
  return (lem);
}

int		add_room(room_t **rooms, char *name, int x, int y)
{
  room_t        *room;

  if ((room = malloc(sizeof(room_t))) == NULL)
    return (my_error("struct.c : 45 Malloc Failed -> add_room", -1));
  if ((room->name = my_strdup(name)) == NULL)
    return (my_error("struct.c : 47 my_strdup Failed -> add_room", -1));
  room->x = x;
  room->y = y;
  room->next = *rooms;
  *rooms = room;
  return (0);
}

int		add_link(link_t **links, char *room1, char *room2)
{
  link_t        *link;

  if ((link = malloc(sizeof(link_t))) == NULL)
    return (my_error("struct.c : 60 Malloc Failed", -1));
  if ((link->room1 = my_strdup(room1)) == NULL)
    return (my_error("struct.c : 62 my_strdup Failed", -1));
  if ((link->room2 = my_strdup(room2)) == NULL)
    return (my_error("struct.c : 62 my_strdup Failed", -1));
  link->next = *links;
  *links = link;
  return (0);
}

void    show(room_t *room, link_t *link, int *rooms, int *paths)
{
  room_t        *tmp1;
  link_t        *tmp2;

  tmp1 = room;
  tmp2 = link;
  while (tmp1->next)
    {
      my_str("name = ", 1);
      my_str(tmp1->name, 1);
      my_str("\tx = ", 1);
      my_putnbr(tmp1->x);
      my_str("\ty = ", 1);
      my_putnbr(tmp1->y);
      write(1, "\n", 1);
      tmp1 = tmp1->next;
      ++(*rooms);
    }
  while (tmp2->next)
    {
      my_str(tmp2->room1, 1);
      my_str(" is link with ", 1);
      my_str(tmp2->room2, 1);
      write(1, "\n", 1);
      tmp2 = tmp2->next;
      ++(*paths);
    }
}

void	free_struct(lem_t *lem)
{
  while (lem->room)
    {
      free(lem->room->name);
      free(lem->room);
      lem->room = lem->room->next;
    }
  free(lem->start);
  free(lem->end);
  free(lem);
}
