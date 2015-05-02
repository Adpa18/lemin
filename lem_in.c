/*
** lem_in.c for  in /home/consta_n/Documents/rendu/CPE_2014_lemin
** 
** Made by consta_n
** Login   <consta_n@epitech.net>
** 
** Started on  Sat May  2 19:09:43 2015 consta_n
** Last update Sat May  2 20:01:01 2015 consta_n
*/

#include "lem_in.h"

int	lem_in(lem_t *lem)
{
  int	**wtab;
  int	**atab;

  if (!(wtab = weight_tab(lem->room)))
    return (1);
  if (!(atab = ant_tab(lem->room)))
    return (1);
  free_tab(wtab);
  free_tab(atab);
  return (0);
}
