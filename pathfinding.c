/*
** pathfinding.c for pathfinding in /home/vezia_l/rendu
** 
** Made by louis vezia
** Login   <vezia_l@epitech.net>
** 
** Started on  Sat May  2 20:26:22 2015 louis vezia
** Last update Sun May  3 02:36:44 2015 louis vezia
*/

void		calc_weight(room_t *parent, room_t *child)
{
  if (child->weight != 1 &&
      (parent->weight + 1 < child->weight || child->weight == -1))
    {
      child->weight = parent->weight + 1;
      parent->road = 1;
      child->ant = parent->name;
    }
}

int		pathfinding(t_ant *ant_tab, lem_t *lem)
{
  room_t	*tmp_r1;
  room_t	*tmp_r2;

  tmp_r1 = lem->room;
  tmp_r2 = lem->room;
  while (tmp_r1)
    {
      if (!strcmp(lem->start, tmp->name))
	break;
      tmp_r1 = tmp_r1->next;
    }
  while (tmp_r2)
    {
      if (strcmp(tmp_r1->name, tmp_r2->name)
	  && !can_go(lem->link, tmp_r1->name, tmp_r2->name))
	{
	  calc_weight(weight, tmp_r1, tmp_r2)
	}
      tmp_r2 = tmp_r2->next;
    }
  return (0);
}
