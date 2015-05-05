/*
** free_asm.c for  in /home/consta_n/Documents/rendu/CPE_2014_corewar/asm/parser
** 
** Made by consta_n
** Login   <consta_n@epitech.net>
** 
** Started on  Sun Apr  5 20:32:49 2015 consta_n
** Last update Tue May  5 16:48:43 2015 consta_n
*/

#include "lem_in.h"

void		free_room(t_room *room)
{
  t_room	*mem;

  mem = room;
  while (room)
    {
      mem = room;
      if (room->name)
        free(room->name);
      room = room->next;
      if (mem)
        free(mem);
    }
}

void		free_link(t_link *link)
{
  t_link	*mem;

  mem = link;
  while (link)
    {
      mem = link;
      if (link->room1)
        free(link->room1);
      if (link->room2)
        free(link->room2);
      link = link->next;
      if (mem)
        free(mem);
    }
}

void		free_struct(t_lem *lem)
{
  if (lem->room)
    free_room(lem->room);
  if (lem->link)
    free_link(lem->link);
  if (lem->start)
    free(lem->start);
  if (lem->end)
    free(lem->end);
  if (lem)
    free(lem);
}

void		free_func(t_path *path)
{
  t_path	*tmp;
  t_path	*mem;

  tmp = path;
  while (tmp)
    {
      mem = tmp;
      tmp = tmp->next;
      if (mem)
	free(mem);
    }
}

void		free_tab(int **tab)
{
  int		i;

  i = 0;
  while (tab && tab[i])
    {
      if (tab[i])
	free(tab[i]);
      i++;
    }
  if (tab)
    free(tab);
}
