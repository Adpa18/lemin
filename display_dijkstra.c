/*
** display_dijkstra.c for lem_in in /home/vencat_a/rendu/CPE_2014_lemin
** 
** Made by axel vencatareddy
** Login   <vencat_a@epitech.net>
** 
** Started on  Tue May  5 08:44:22 2015 axel vencatareddy
** Last update Tue May  5 09:28:17 2015 axel vencatareddy
*/

#include "lem_in.h"

int             disp_turn(t_six_int *t, char **name, t_lem *lem, t_path **tmp)
{
  while (t->i < t->j)
    {
      if (printf("P%d-%s", t->i, *name) < 0)
        return (my_error("A printf error occured", -1));
      if (t->i + 1 < t->j)
        if (printf(" ") < 0)
          return (my_error("A printf error occured", -1));
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
  return (0);
}

int             display_the_after_turns(t_six_int *t, t_path **tmp)
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
  if (printf("\n") < 0)
    return (my_error("A printf error occured", -1));
  return (0);
}

int             display(t_lem *lem, t_path *path, int nb_ant)
{
  t_path        *tmp;
  t_six_int     t;
  char          *name;

  tmp = path;
  t.j = 2;
  t.x = 1;
  t.test = 0;
  t.save = 0;
  while (t.x <= nb_ant && tmp)
    {
      name = tmp->name;
      t.i = t.x;
      if (disp_turn(&t, &name, lem, &tmp) == -1)
        return (-1);
      if (display_the_after_turns(&t, &tmp) == -1)
        return (-1);
      if (tmp && tmp->next)
        tmp = tmp->next;
      if (t.j < nb_ant + 1)
        t.j++;
    }
  return (0);
}

void            find_lem_end(t_room **tmp, t_lem *lem)
{
  while (*tmp)
    {
      if (!my_strcmp(lem->end, (*tmp)->name))
        break;
      *tmp = (*tmp)->next;
    }
}
