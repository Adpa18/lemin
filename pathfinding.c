/*
** pathfinding.c for pathfinding in /home/vezia_l/rendu
** 
** Made by louis vezia
** Login   <vezia_l@epitech.net>
** 
** Started on  Sat May  2 20:26:22 2015 louis vezia
** Last update Tue May  5 08:45:24 2015 axel vencatareddy
*/

#include "lem_in.h"

int		display_path(t_lem *lem)
{
  t_room	*tmp;
  t_room	*tmp1;
  t_path       	*path;

  tmp = lem->room;
  path = NULL;
  find_lem_end(&tmp, lem);
  tmp1 = lem->room;
  add_path(&path, tmp->name);
  while (tmp1)
    {
      while (tmp1)
	{
	  if (!my_strcmp(tmp1->name, tmp->ant))
	    break;
	  tmp1 = tmp1->next;
	}
      add_path(&path, tmp1->name);
      if (!my_strcmp(tmp1->name, lem->start))
	break;
      tmp = tmp1;
      tmp1 = lem->room;
    }
  return (display(lem, path, lem->nb_ant));
}

void		calc_weight(t_room *parent, t_room *child)
{
  if (child->weight != 1 &&
      (parent->weight + 1 < child->weight || child->weight == -1))
    {
      child->weight = parent->weight + 1;
      child->ant = parent->name;
    }
}

t_room		*set_parent(t_room *rooms)
{
  t_room	*tmp;
  int		weight;

  weight = 0xFFFFFF;
  tmp = rooms;
  while (tmp)
    {
      if (tmp->weight < weight && tmp->road != 1 && tmp->weight > 0)
	weight = tmp->weight;
      tmp = tmp->next;
    }
  tmp = rooms;
  while (tmp)
    {
      if (tmp->weight == weight && tmp->road != 1)
        break;
      tmp = tmp->next;
    }
  return (tmp);
}

int		pathfinding(t_lem *lem)
{
  t_room	*tmp_r1;
  t_room	*tmp_r2;

  tmp_r1 = lem->room;
  while (tmp_r1)
    {
      if (!my_strcmp(lem->start, tmp_r1->name))
	break;
      tmp_r1 = tmp_r1->next;
    }
  while (my_strcmp(tmp_r1->name, lem->end))
    {
      tmp_r2 = lem->room;
      while (tmp_r2)
	{
	  if (my_strcmp(tmp_r1->name, tmp_r2->name)
	      && !can_go(lem->link, tmp_r1->name, tmp_r2->name))
	    calc_weight(tmp_r1, tmp_r2);
	  tmp_r2 = tmp_r2->next;
	}
      tmp_r1->road = 1;
      tmp_r1 = set_parent(lem->room);
    }
  return (display_path(lem));
}
