/*
** set_tab.c for  in /home/consta_n/Documents/rendu/CPE_2014_lemin
** 
** Made by consta_n
** Login   <consta_n@epitech.net>
** 
** Started on  Sat May  2 18:43:29 2015 consta_n
** Last update Sat May  2 21:46:29 2015 consta_n
*/

#include "lem_in.h"

int		init_weight(room_t *rooms, t_weight **weight)
{
  room_t	*tmp;

  tmp = rooms;
  while (tmp)
    {
      add_weight(weight, tmp->name);
      tmp = tmp->next;
    }
  return (0);
}

int		init_ant(room_t *rooms, t_ant **ant)
{
  room_t	*tmp;

  tmp = rooms;
  while (tmp)
    {
      add_ant(ant, tmp->name);
      tmp = tmp->next;
    }
  return (0);
}
