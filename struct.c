/*
** struct.c for struct in /home/wery_a/rendu/CPE/Lem-In/Test/v1
** 
** Made by Adrien WERY
** Login   <wery_a@epitech.net>
** 
** Started on  Sat Apr 25 15:05:35 2015 Adrien WERY
** Last update Sat Apr 25 18:09:06 2015 Adrien WERY
*/

#include "lem_in.h"

int		add_room(room_t **rooms, char *name, int x, int y)
{
  room_t        *room;

  if ((room = malloc(sizeof(room_t))) == NULL)
    return (my_error("struct.c : 17 Malloc Failed", -1));
  if ((room->name = my_strdup(name)) == NULL)
    return (my_error("struct.c : 19 my_strdup Failed", -1));
  room->x = x;
  room->y = y;
  room->next = *rooms;
  *rooms = room;
  return (0);
}

lem_t	*init_lem()
{
  lem_t	*lem;

  if ((lem = malloc(sizeof(lem_t))) == NULL)
    {
      my_error("struct.c : 31 Malloc Failed", -1);
      return (NULL);
    }
  if ((lem->room = malloc(sizeof(room_t))) == NULL)
    {
      my_error("struct.c : 36 Malloc Failed", -1);
      return (NULL);
    }
  lem->room->name = NULL;
  lem->room->x = 0;
  lem->room->y = 0;
  return (lem);
}

void    show(room_t *room)
{
  room_t        *tmp;

  tmp = room;
  while (tmp->next)
    {
      my_str("name = ", 1);
      my_str(tmp->name, 1);
      my_str("\tx = ", 1);
      my_putnbr(tmp->x);
      my_str("\ty = ", 1);
      my_putnbr(tmp->y);
      write(1, "\n", 1);
      tmp = tmp->next;
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
