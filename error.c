/*
** error.c for lem_in in /home/vencat_a/rendu/CPE_2014_lemin
** 
** Made by axel vencatareddy
** Login   <vencat_a@epitech.net>
** 
** Started on  Sun May  3 14:54:21 2015 axel vencatareddy
** Last update Sun May  3 14:59:48 2015 axel vencatareddy
*/

#include "lem_in.h"

int		my_error(char *str, int error)
{
  int		i;

  i = -1;
  while (str[++i])
    write(2, &str[i], 1);
  write(2, "\n", 1);
  return (error);
}

char		*my_str_error(char *str, char *error)
{
  int		i;

  i = -1;
  while (str[++i])
    write(2, &str[i], 1);
  write(2, "\n", 1);
  return (error);
}
