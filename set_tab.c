/*
** set_tab.c for  in /home/consta_n/Documents/rendu/CPE_2014_lemin
** 
** Made by consta_n
** Login   <consta_n@epitech.net>
** 
** Started on  Sat May  2 18:43:29 2015 consta_n
** Last update Tue May  5 08:08:08 2015 axel vencatareddy
*/

#include "lem_in.h"

int		init_weight(t_room *rooms, t_weight **weight)
{
  t_room	*tmp;

  tmp = rooms;
  while (tmp)
    {
      add_weight(weight, tmp->name);
      tmp = tmp->next;
    }
  return (0);
}

int		init_ant(t_room *rooms, t_ant **ant)
{
  t_room	*tmp;

  tmp = rooms;
  while (tmp)
    {
      add_ant(ant, tmp->name);
      tmp = tmp->next;
    }
  return (0);
}
