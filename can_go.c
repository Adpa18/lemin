/*
** can_go.c for can_go in /home/wery_a/rendu/CPE/Lem-In/Test/v1
** 
** Made by Adrien WERY
** Login   <wery_a@epitech.net>
** 
** Started on  Sat Apr 25 19:40:55 2015 Adrien WERY
** Last update Sat Apr 25 19:41:18 2015 Adrien WERY
*/

#include "lem_in.h"

void    display_can_go(char *room1, char *room2, int go)
{
  my_str(room1, 1);
  if (go == 0)
    my_str(" can go to ", 1);
  else
    my_str(" can't go to ", 1);
  my_str(room2, 1);
  write(1, "\n", 1);
}

int     can_go(link_t *link, char *room1, char *room2)
{
  while (link)
    {
      if ((my_strcmp(link->room1, room1) == 0 &&
           my_strcmp(link->room2, room2) == 0)
          || (my_strcmp(link->room1, room2) == 0 &&
              my_strcmp(link->room2, room1) == 0))
        return (0);
      link = link->next;
    }
  return (-1);
}
