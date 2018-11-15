/*
** get_objects.c for raytracer1 in /home/mael/raytracer1
**
** Made by mael drapier
** Login   <mael.drapier@epitech.eu@epitech.net>
**
** Started on  Mon Mar  6 17:10:05 2017 mael drapier
** Last update Mon Mar  6 23:36:13 2017 mael drapier
*/

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "raytracer1.h"
#include "get_next_line.h"

int	my_getnbr(char *str)
{
  int	i;
  int	res;
  int	neg;

  i = 0;
  res = 0;
  neg = 1;
  if (str == NULL)
    return (0);
  while (str[i] == '-')
    {
      neg = neg * -1;
      i = i + 1;
    }
  while (str[i] != '\0')
    {
      if (str[i] < '0' || str[i] > '9')
	return (res * neg);
      res = res * 10;
      res = res + str[i] - 48;
      i = i + 1;
    }
  return (res * neg);
}

int	my_strcmp(char *s1, char *s2)
{
  int	i;

  i = 0;
  while (s1[i] != '\0' || s2[i] != '\0')
    {
      if (s1[i] != s2[i])
	return (s1[i] - s2[i]);
      i = i + 1;
    }
  return (0);
}

t_conf	fill_numbers(t_conf obj, char *s, int fd)
{
  if (my_strcmp(s, "obj:") == 0)
    {
      s = get_next_line(fd);
      obj.nb = my_getnbr(s);
    }
  else if (my_strcmp(s, "rot:") == 0)
    {
      obj.rot.x = my_getnbr(get_next_line(fd));
      obj.rot.y = my_getnbr(get_next_line(fd));
      obj.rot.z = my_getnbr(get_next_line(fd));
    }
  else if (my_strcmp(s, "trans:") == 0)
    {
      obj.trans.x = my_getnbr(get_next_line(fd));
      obj.trans.y = my_getnbr(get_next_line(fd));
      obj.trans.z = my_getnbr(get_next_line(fd));
    }
  else if (my_strcmp(s, "var:") == 0)
    obj.var = my_getnbr(get_next_line(fd));
  return (obj);
}

t_conf	*fill_conf(t_conf *obj, char *filename)
{
  int	fd;
  int	j;
  char	*s;

  j = 0;
  if ((fd = open(filename, O_RDONLY)) < 0)
    {
      obj[0].nb = 0;
      return (obj);
    }
  while ((s = get_next_line(fd)) != NULL)
    {
      obj[j].elem = 0;
      if (my_strcmp(s, "******") == 0)
	j = j + 1;
      obj[j] = fill_numbers(obj[j], s, fd);
    }
  close (fd);
  return (obj);
}

t_conf	*read_objects(t_conf *obj, char *filename)
{
  int	fd;
  char	*s;
  int	size;

  size = 1;
  if ((fd = open(filename, O_RDONLY)) < 0)
    return (NULL);
  while ((s = get_next_line(fd)) != NULL)
    {
      if (my_strcmp(s, "******") == 0)
	size = size + 1;
    }
  if ((obj = malloc(sizeof(t_conf) * (size + 1))) == NULL)
    return (obj);
  close(fd);
  obj = fill_conf(obj, filename);
  obj[0].elem = size;
  return (obj);
}
