/*
** lem_in.c for  in /home/consta_n/Documents/rendu/CPE_2014_lemin
** 
** Made by consta_n
** Login   <consta_n@epitech.net>
** 
** Started on  Sat May  2 19:09:43 2015 consta_n
** Last update Sat May  2 21:43:49 2015 consta_n
*/

#include "lem_in.h"

int		lem_in(lem_t *lem)
{
  t_weight	*weight;
  t_ant		*ant;

  if (!(init_weight(lem->room, &weight)))
    return (1);
  if (!(init_ant(lem->room, &ant)))
    return (1);
  return (0);
}
