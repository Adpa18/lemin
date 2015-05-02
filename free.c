/*
** free_asm.c for  in /home/consta_n/Documents/rendu/CPE_2014_corewar/asm/parser
** 
** Made by consta_n
** Login   <consta_n@epitech.net>
** 
** Started on  Sun Apr  5 20:32:49 2015 consta_n
** Last update Sat May  2 19:59:47 2015 consta_n
*/

#include <stdlib.h>

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
