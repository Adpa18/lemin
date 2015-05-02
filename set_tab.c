/*
** set_tab.c for  in /home/consta_n/Documents/rendu/CPE_2014_lemin
** 
** Made by consta_n
** Login   <consta_n@epitech.net>
** 
** Started on  Sat May  2 18:43:29 2015 consta_n
** Last update Sat May  2 19:30:01 2015 consta_n
*/

#include "lem_in.h"

int		list_len(room_t *rooms)
{
  int		i;
  room_t	*tmp;

  i = 0;
  tmp = rooms;
  while (tmp)
    {
      i++;
      tmp = tmp->next;
    }
  return (i + 1);
}

int		**weight_tab(room_t *rooms)
{
  room_t	*tmp;
  int		**wtab;
  int		i;

  tmp = rooms;
  i = list_len(rooms);
  if (!(wtab = malloc(sizeof(int *) * (i + 1))))
    return (NULL);
  tmp = rooms;
  if (!(wtab[0] = malloc(sizeof(int) * (3))))
    return (NULL);
  wtab[0][0] = i;
  i = 1;
  while (tmp)
    {
      if (!(wtab[i] = malloc(sizeof(int) * (3))))
	return (NULL);
      wtab[i][0] = tmp->id;
      wtab[i][1] = -1;
      wtab[i][2] = 0;
      i++;
      tmp = tmp->next;
    }
  wtab[i] = NULL;
  return (wtab);
}

int		**ant_tab(room_t *rooms)
{
  room_t	*tmp;
  int		**atab;
  int		i;

  tmp = rooms;
  i = list_len(rooms);
  if (!(atab = malloc(sizeof(int *) * (i + 1))))
    return (NULL);
  tmp = rooms;
  if (!(atab[0] = malloc(sizeof(int) * (2))))
    return (NULL);
  atab[0][0] = i;
  i = 1;
  while (tmp)
    {
      if (!(atab[i] = malloc(sizeof(int) * (2))))
	return (NULL);
      atab[i][0] = tmp->id;
      atab[i][1] = -1;
      i++;
      tmp = tmp->next;
    }
  atab[i] = NULL;
  return (atab);
}
