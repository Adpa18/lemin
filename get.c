/*
** get.c for lem_in in /home/vencat_a/rendu/CPE_2014_lemin
** 
** Made by axel vencatareddy
** Login   <vencat_a@epitech.net>
** 
** Started on  Sun May  3 15:28:27 2015 axel vencatareddy
** Last update Sun May  3 15:48:10 2015 axel vencatareddy
*/

#include "lem_in.h"

int		get_path(room_t **room, link_t **link, char **tab)
{
  room_t        *t1;
  room_t        *t2;

  t1 = *room;
  t2 = *room;
  while (t1 && my_strcmp(tab[0], t1->name) != 0)
    t1 = t1->next;
  while (t2 && my_strcmp(tab[1], t2->name) != 0)
    t2 = t2->next;
  free_double(tab);
  if (!t1 || !t2)
    return (my_error("Room doesn't exist", -1));
  if (add_link(link, t1->name, t2->name) == -1)
    return (-1);
  return (0);
}

int		get_struct(int fd, lem_t *lem)
{
  char		*s;

  if ((lem->nb_ant =
       my_getnbr_base(epur_str(get_next_line(fd)), "0123456789")) <= 0)
    return (my_error("I need some ants to play", -1));
  while ((s = epur_str(get_next_line(fd))))
    {
      if (my_strcmp("##start", s) == 0)
        {
          free(s);
          s = epur_str(get_next_line(fd));
          if ((lem->start=check_line(s,&(lem->room),&(lem->link),1)) == NULL)
            return (-1);
        }
      else if (my_strcmp("##end", s) == 0)
        {
          free(s);
          s = epur_str(get_next_line(fd));
          if ((lem->end = check_line(s, &(lem->room), &(lem->link), 2)) == NULL)
            return (-1);
        }
      else if (check_line(s, &(lem->room), &(lem->link), 0) == NULL)
        return (-1);
    }
  return (check_struct(lem));
}
