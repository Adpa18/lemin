/*
** can_go.c for can_go in /home/wery_a/rendu/CPE/Lem-In/Test/v1
** 
** Made by Adrien WERY
** Login   <wery_a@epitech.net>
** 
** Started on  Sat Apr 25 19:40:55 2015 Adrien WERY
** Last update Tue May  5 07:48:49 2015 axel vencatareddy
*/

#include "lem_in.h"

int     can_go(t_link *link, char *room1, char *room2)
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
