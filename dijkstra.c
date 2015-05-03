/*
** dijkstra.c for lemin in /home/vencat_a/rendu/CPE_2014_lemin
** 
** Made by axel vencatareddy
** Login   <vencat_a@epitech.net>
** 
** Started on  Sat May  2 17:48:21 2015 axel vencatareddy
** Last update Sun May  3 16:12:42 2015 axel vencatareddy
*/

#include "lem_in.h"

void		init_djikstra(char **graph, int ind_beg, int *dist, int *prev)
{
  int		i;

  i = 0;
  while (graph[i])
    {
      dist[v] = -1;
      prev[v] = -1;
    }
  dist[ind_beg] = 0;
}

void		relax(char **graph, int *dist, int *prev, int *uv)
{
  if (dist[uv[1]] > dist[uv[0]] + graph[uv[0]][uv[1]])
    {
      dist[uv[1]] = dist[uv[0]] + graph[uv[0]][uv[1]];
      prev[uv[1]] = uv[0];
    }
}

void		dijkstra(char **graph, int init_som)
{
  init_dijkstra(graph, indice_beg, dist, prev);
}
