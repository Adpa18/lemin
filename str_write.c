/*
** str.c for str in /home/wery_a/rendu/CPE/Lem-In/Test
** 
** Made by Adrien WERY
** Login   <wery_a@epitech.net>
** 
** Started on  Fri Apr 24 20:54:09 2015 Adrien WERY
** Last update Sun May  3 14:57:31 2015 axel vencatareddy
*/

#include "lem_in.h"

void	my_putchar(char c)
{
  write(1, &c, 1);
}

int	my_str(char *s, int mode)
{
  int	i;

  i = 0;
  while (s[i])
    {
      if (mode == 1)
	write(1, &s[i], 1);
      i += 1;
    }
  return (i);
}

void	my_putnbr(int nb)
{
  if (nb / 10 > 0)
    my_putnbr(nb / 10);
  my_putchar(nb % 10 + 48);
}

void	free_double(char **tab)
{
  int	i;

  i = -1;
  while (tab[++i])
    free(tab[i]);
  free(tab);
}
