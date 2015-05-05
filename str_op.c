/*
** str2.c for str2 in /home/wery_a/rendu/CPE/Lem-In/Test/v1
** 
** Made by Adrien WERY
** Login   <wery_a@epitech.net>
** 
** Started on  Sat Apr 25 15:14:13 2015 Adrien WERY
** Last update Tue May  5 20:09:49 2015 consta_n
*/

#include "lem_in.h"

int	my_strcmp(char *s1, char *s2)
{
  int	i;

  if (s1 == NULL || s2 == NULL)
    return (-1);
  i = 0;
  while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
    i += 1;
  return (s1[i] - s2[i]);
}

char	*my_strdup(char *s)
{
  char	*dup;
  int	i;
  int	size;

  i = 0;
  size = my_str(s, 0);
  if ((dup = malloc(sizeof(char) * (size + 1))) ==  NULL)
    {
      my_error("Malloc Failed in my_strdup function", -1);
      return (NULL);
    }
  my_memset(dup, '\0', size + 1);
  while (s && s[i] != '\0')
    {
      dup[i] = s[i];
      ++i;
    }
  dup[i] = '\0';
  return (dup);
}

void	my_memset(char *s, char c, int size)
{
  int	i;

  i = -1;
  while (++i < size)
    s[i] = c;
}

char	*free_re(char *s)
{
  if (s)
    free(s);
  return (my_strdup("nil"));
}

char	*epur_str(char *s)
{
  int	i;
  int	x;

  if (s == NULL)
    return (NULL);
  i = 0;
  x = -1;
  while (s[i] && (s[i] == ' ' || s[i] == '\t'))
    ++i;
  if (!s[i])
    return (free_re(s));
  while (s[i])
    {
      s[++x] = s[i];
      while (s[i] && s[i + 1] && (s[i] == ' ' || s[i] == '\t') &&
             (s[i + 1] == ' ' || s[i + 1] == '\t'))
        ++i;
      ++i;
    }
  while (s[x] == ' ' || s[x] == '\t')
    --x;
  s[++x] = '\0';
  return (s);
}
