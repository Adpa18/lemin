/*
** str_to_wordtab.c for str_to_wordtab in /home/wery_a/rendu/CPE/Lem-In/Test/v1
** 
** Made by Adrien WERY
** Login   <wery_a@epitech.net>
** 
** Started on  Sat Apr 25 15:27:15 2015 Adrien WERY
** Last update Sat May  2 20:51:33 2015 consta_n
*/

#include "lem_in.h"

int	word_len(char *s, char sp)
{
  int	i;

  i = 0;
  while (s[i] != '\0' && s[i] != sp && s[i] != '\n')
    ++i;
  return (i);
}

int	word_count(char *s, char sp)
{
  int	i;
  int	n;

  i = 0;
  n = 0;
  while (s[i] != '\0' && s[i] != '\n')
    {
      if (s[i] == sp && s[i + 1] != '\0')
	++n;
      ++i;
    }
  return (n);
}

char	**my_str_to_wordtab(char *s, char sp, int i)
{
  char	**tab;
  int	x;
  int	y;

  y = 0;
  x = 0;
  if ((tab = malloc((word_count(s, sp) + 2) * sizeof(char *))) == NULL)
    return (NULL);
  while (s[i] != '\0' && s[i] != '\n')
    {
      if (s[i] == sp || s[i] == '\n')
	{
	  while (s[++i] == sp);
	  ++y;
	  x = 0;
	}
      if ((tab[y] = my_alloc((word_len(s + i, sp) + 1))) == NULL)
	return (NULL);
      while (s[i] != '\0' && s[i] != sp && s[i] != '\n')
	tab[y][x++] = s[i++];
      tab[y][x] = '\0';
    }
  tab[y + 1] = '\0';
  return (tab);
}
