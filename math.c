/*
** math.c for lem_in in /home/wery_a/rendu/CPE_2014_lemin
** 
** Made by Adrien WERY
** Login   <wery_a@epitech.net>
** 
** Started on  Fri Apr 24 20:26:44 2015 Adrien WERY
** Last update Tue May  5 07:53:56 2015 axel vencatareddy
*/

#include "lem_in.h"

int	power(int nb1, int p)
{
  int	nb;
  int	i;

  nb = 1;
  i = -1;
  while (++i < p)
    nb *= nb1;
  return (nb);
}

int	my_getnbr_base(char *s, char *base)
{
  int	nb;
  short	i;
  short	n;
  short	p;
  short	len;

  if (!s)
    return (-1);
  len = my_str(base, 0);
  i = my_str(s, 0);
  p = 0;
  nb = 0;
  while (--i > -1)
    {
      if (s[i] == '-')
        return (-1 * nb);
      n = -1;
      while (s[i] != base[++n] && base[n] != '\0');
      if (base[n] == '\0' || n > len)
        n = 0;
      nb += n * power(len, p++);
    }
  return (nb);
}
