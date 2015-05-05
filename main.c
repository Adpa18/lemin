/*
** main.c for main in /home/wery_a/rendu/Lem-In/Test
** 
** Made by adrien wery
** Login   <wery_a@epitech.net>
** 
** Started on  Fri Apr  3 17:32:29 2015 adrien wery
** Last update Tue May  5 20:10:53 2015 consta_n
*/

#include "lem_in.h"

void	*free_ret(char **tab, char *s)
{
  if (tab)
    free_double(tab);
  if (s)
    free(s);
  return (NULL);
}

char	*check_line(char *s, t_room **room, t_link **link, char cmd)
{
  char	**tab;
  char	*name;

  if (s[0] == '#' || (s[0] == 'n' && s[1] == 'i' && s[2] == 'l'))
    {
      free(s);
      return ("comment");
    }
  name = NULL;
  if ((tab = my_str_to_wordtab(s, ' ', 0)) == NULL)
    return (my_str_error("Malloc Failed in my_str_to_wordtab", NULL));
  if (tab[0] && tab[1] && tab[2])
    {
      if ((add_room(room, tab[0], cmd) == -1)
	  || ((name = my_strdup(tab[0])) == NULL))
	return (free_ret(tab, s));
    }
  else if (get_path(room, link, my_str_to_wordtab(s, '-', 0)) == -1)
    return (free_ret(tab, s));
  free_double(tab);
  free(s);
  if (cmd == 1 || cmd == 2)
    return (name);
  free(name);
  return ("good");
}

int	check_struct(t_lem *lem)
{
  int	rooms;
  int	paths;

  if (!lem->start)
    return (my_error("No ##start in the file", -1));
  if (!lem->end)
    return (my_error("No ##end in the file", -1));
  rooms = -1;
  paths = 0;
  show(lem->room, lem->link, &rooms, &paths);
  if (rooms < 2)
    return (my_error("Need 2 rooms or more", -1));
  else if (paths < rooms - 1)
    return (my_error("Some rooms aren't link", -1));
  return (0);
}

int	parsing(char *file, t_lem *lem)
{
  int	fd;
  char	*s;

  if ((fd = open(file, O_RDONLY)) == -1)
    return (my_error("Can't Open The File", 1));
  while ((s = epur_str(get_next_line(fd))) && s[0] == '#')
    free(s);
  if ((lem->nb_ant =
       my_getnbr_base(s, "0123456789")) <= 0)
    {
      close(fd);
      free(s);
      return (my_error("I need some ants to play", -1));
    }
  free(s);
  if (get_struct(fd, lem) == -1)
    {
      close(fd);
      return (my_error("Can't Get Rooms and Paths", 1));
    }
  close(fd);
  return (0);
}

int	main(int argc, char **argv)
{
  t_lem	*lem;

  if (argc != 2)
    return (my_error("\n\tUsage : ./lem_in <file_name>\n", -1));
  if ((lem = init_lem()) == NULL)
    {
      free_struct(lem);
      return (my_error("Can't Init the lem struct", 1));
    }
  if (parsing(argv[1], lem))
    {
      free_struct(lem);
      return (1);
    }
  if (show_result(argv[1], lem) != 0)
    return (my_error("The program has unfortunately shutdown.", -1));
  free_struct(lem);
  return (0);
}
