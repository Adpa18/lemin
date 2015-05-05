/*
** my_get_next_line.c for  in /home/consta_n/rendu/mini/backup/opti-wolf
** 
** Made by Nicolas Constanty
** Login   <consta_n@epitech.net>
** 
** Started on  Sun Dec 21 19:35:08 2014 Nicolas Constanty
** Last update Tue May  5 20:06:44 2015 consta_n
*/

#include "lem_in.h"

char		*my_alloc(int len)
{
  char		*str;
  int		cpt;

  cpt = 0;
  if (len == 0)
    return (NULL);
  if (!(str = malloc(len + 1)))
    return (NULL);
  while (cpt != len)
    {
      str[cpt] = '\0';
      cpt++;
    }
  str[cpt] = '\0';
  return (str);
}

int		my_read(int fd, char *buffer, int *buffer_i)
{
  int		nb_read;

  *buffer_i = 0;
  nb_read = read(fd, buffer, BUFF_SIZE);
  if (nb_read == -1)
    {
      my_str("Read failed.\n", 1);
      return (-1);
    }
  return (nb_read);
}

char		*get_next_line(int fd)
{
  static char	buffer[BUFF_SIZE];
  static int	nb_read = -1;
  static int	buffer_i = 0;
  char		*str;
  int		i;

  i = 0;
  str = my_alloc(sizeof(*str) * (BUFF_SIZE + 1));
  if (nb_read == -1 || buffer_i >= nb_read)
    nb_read = my_read(fd, buffer, &buffer_i);
  while (i < BUFF_SIZE && buffer[buffer_i] != '\n' && nb_read > 0)
    {
      str[i++] = buffer[buffer_i++];
      if (buffer_i >= nb_read)
	nb_read = my_read(fd, buffer, &buffer_i);
    }
  if (buffer[buffer_i] == '\n')
    buffer_i++;
  if (nb_read <= 0 && i == 0)
    {
      free(str);
      return (NULL);
    }
  str[i] = '\0';
  return (str);
}
