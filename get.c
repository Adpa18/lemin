/*
** get.c for get in /home/wery_a/rendu/CPE/Lem-In/Test
** 
** Made by Adrien WERY
** Login   <wery_a@epitech.net>
** 
** Started on  Fri Apr 24 20:26:44 2015 Adrien WERY
** Last update Sat Apr 25 19:25:23 2015 Adrien WERY
*/

#include "lem_in.h"
# define BUFF_SIZE 1

char    *my_malloc(int len)
{
  char  *s;
  int   i;

  i = 0;
  if ((s = malloc(len)) == NULL)
    return (NULL);
  while (i < len)
    s[i++] = '\0';
  return (s);
}

char    *my_re_alloc(char *s)
{
  char  *s2;
  int   i;

  if ((s2 = my_malloc((my_str(s, 0) + 2) * sizeof(char))) == NULL)
    return (NULL);
  i = -1;
  while (s[++i] != '\0')
    s2[i] = s[i];
  s2[++i] = '\0';
  free(s);
  return (s2);
}

char    *get_next_line(int fd)
{
  char  buff[BUFF_SIZE];
  char  *str;
  int   i;
  int   size;

  i = 0;
  size = 0;
  str = my_malloc(sizeof(char));
  str[0] = '\0';
  while ((size = read(fd, buff, BUFF_SIZE)) > 0 && buff[0] != '\n')
    {
      if ((str = my_re_alloc(str)) == NULL)
	{
	  my_error("get.c : 55 Malloc Failed", -1);
	  return (NULL);
	}
      str[i++] = buff[0];
    }
  if (size == 0 && i == 0)
    return (NULL);
  else
    return (str);
}

int     power(int nb1, int p)
{
  int   nb;
  int   i;

  nb = 1;
  i = -1;
  while (++i < p)
    nb *= nb1;
  return (nb);
}

int     my_getnbr_base(char *s, char *base)
{
  int   nb;
  short i;
  short n;
  short p;
  short len;

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
