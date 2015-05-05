/*
** show_result.c for  in /home/consta_n/Documents/rendu/CPE_2014_lemin
** 
** Made by consta_n
** Login   <consta_n@epitech.net>
** 
** Started on  Tue May  5 03:17:48 2015 consta_n
** Last update Tue May  5 09:26:11 2015 axel vencatareddy
*/

#include "lem_in.h"

int	show_result(char *file, t_lem *lem)
{
  int	fd;
  char	*buff;

  if ((fd = open(file, O_RDONLY)) == -1)
    return (1);
  while ((buff = epur_str(get_next_line(fd))) != NULL)
    {
      if (printf("%s\n", buff) < 0)
	{
	  free(buff);
	  return (my_error("A printf error occured", -1));
	}
      free(buff);
    }
  close(fd);
  if (pathfinding(lem) < 0)
    return (-1);
  return (0);
}
