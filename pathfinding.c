/*
** pathfinding.c for pathfinding in /home/vezia_l/rendu
** 
** Made by louis vezia
** Login   <vezia_l@epitech.net>
** 
** Started on  Sat May  2 20:26:22 2015 louis vezia
** Last update Tue May  5 08:19:10 2015 axel vencatareddy
*/

#include "lem_in.h"

void		display_the_turns(t_six_int *t, char **name, t_lem *lem, t_path **tmp)
{
  while (t->i < t->j)
    {
      printf("P%d-%s", t->i, *name);
      if (t->i + 1 < t->j)
	printf(" ");
      if (!my_strcmp(*name, lem->end))
	t->test = 1;
      if ((*tmp)->prev)
	{
	  t->save++;
	  t->save_while = 1;
	  while (t->save_while > 0)
	    {
	      *tmp = (*tmp)->prev;
	      t->save_while--;
	    }
	  *name = (*tmp)->name;
	}
      t->i++;
    }
}

void		display_the_after_turns(t_six_int *t, t_path **tmp, t_path *path)
{
  while (t->save > 0)
    {
      *tmp = (*tmp)->next;
      t->save--;
    }
  if (t->test == 1)
    {
      t->x++;
      t->test = 0;
      *tmp = (*tmp)->prev;
    }
  printf("\n");
}

void		display(t_lem *lem, t_path *path, int nb_ant)
{
  t_path	*tmp;
  t_six_int	t;
  char		*name;

  tmp = path;
  t.j = 2;
  t.x = 1;
  t.test = 0;
  t.save = 0;
  while (t.x <= nb_ant && tmp)
    {
      name = tmp->name;
      t.i = t.x;
      display_the_turns(&t, &name, lem, &tmp);
      display_the_after_turns(&t, &tmp, path);
      if (tmp && tmp->next)
	tmp = tmp->next;
      if (t.j < nb_ant + 1)
	t.j++;
    }
}

void		find_lem_end(t_room **tmp, t_lem *lem)
{
  while (*tmp)
    {
      if (!my_strcmp(lem->end, (*tmp)->name))
	break;
      *tmp = (*tmp)->next;
    }
}

void		display_path(t_lem *lem)
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
  display(lem, path, lem->nb_ant);
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

void		pathfinding(t_lem *lem)
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
  display_path(lem);
}
