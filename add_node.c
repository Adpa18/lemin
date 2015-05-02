/*
** add_node.c for  in /home/consta_n/Documents/rendu/CPE_2014_lemin
** 
** Made by consta_n
** Login   <consta_n@epitech.net>
** 
** Started on  Sat May  2 21:18:48 2015 consta_n
** Last update Sat May  2 21:27:44 2015 consta_n
*/

#include "lem_in.h"

int		add_ant(t_ant **ant, char *name)
{
  t_ant		*node;

  if ((node = malloc(sizeof(t_ant))) == NULL)
    return (my_error("struct.c : 60 Malloc Failed", -1));
  node->name = name;
  node->ant = 0;
  node->next = *ant;
  *ant = node;
  return (0);
}

int		add_weight(t_weight **weight, char *name)
{
  t_weight	*node;

  if ((node = malloc(sizeof(t_weight))) == NULL)
    return (my_error("struct.c : 60 Malloc Failed", -1));
  node->name = name;
  node->weight = -1;
  node->parcour = 0;
  node->next = *weight;
  *weight = node;
  return (0);
}
