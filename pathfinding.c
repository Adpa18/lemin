/*
** pathfinding.c for pathfinding in /home/vezia_l/rendu
** 
** Made by louis vezia
** Login   <vezia_l@epitech.net>
** 
** Started on  Sat May  2 20:26:22 2015 louis vezia
** Last update Tue May  5 03:04:32 2015 axel vencatareddy
*/

#include "lem_in.h"

void		display(t_path *path)
{
  t_path	*tmp;

  tmp = path;
  while (tmp)
    {
      printf("path->name = %s\n", tmp->name);
      tmp = tmp->next;
    }
}

void		display_path(lem_t *lem)
{
  room_t	*tmp;
  room_t	*tmp1;
  t_path       	*path;

  tmp = lem->room;
  path = NULL;
  while (tmp)
    {
      if (!my_strcmp(lem->end, tmp->name))
	break;
      tmp = tmp->next;
    }
  tmp1 = lem->room;
  printf("tmp->name = %s\n", tmp->name);
  add_path(&path, tmp->name);
  while (tmp1)
    {
      while (tmp1)
	{
	  if (!my_strcmp(tmp1->name, tmp->ant))
	    break;
	  tmp1 = tmp1->next;
	}
      printf("tmp1->name = %s\n", tmp1->name);
      add_path(&path, tmp1->name);
      if (!my_strcmp(tmp1->name, lem->start))
	break;
      tmp = tmp1;
      tmp1 = lem->room;
    }
  display(path);
}

void		calc_weight(room_t *parent, room_t *child)
{
  if (child->weight != 1 &&
      (parent->weight + 1 < child->weight || child->weight == -1))
    {
      child->weight = parent->weight + 1;
      child->ant = parent->name;
    }
}

room_t		*set_parent(room_t *rooms)
{
  room_t	*tmp;
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

void		pathfinding(lem_t *lem)
{
  room_t	*tmp_r1;
  room_t	*tmp_r2;

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
	    {
	      calc_weight(tmp_r1, tmp_r2);
	    }
	  tmp_r2 = tmp_r2->next;
	}
      tmp_r1->road = 1;
      tmp_r1 = set_parent(lem->room);
    }
  display_path(lem);
}
