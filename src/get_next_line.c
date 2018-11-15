/*
** get_next_line.c for matchstick in /home/mael/CPE_2016_matchstick
**
** Made by mael drapier
** Login   <mael.drapier@epitech.eu@epitech.net>
**
** Started on  Sun Feb 19 20:53:33 2017 mael drapier
** Last update Sun Feb 26 17:58:42 2017 mael drapier
*/

#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

char		get_next_char(const int fd)
{
  static int	i = 0;
  static int	lenght = 0;
  static char	buf[READ_SIZE];
  char		res;

  if (lenght == 0)
    {
      lenght = read(fd, buf, READ_SIZE);
      if (lenght == 0)
	return (0);
      i = 0;
    }
  res = buf[i];
  i = i + 1;
  lenght = lenght - 1;
  return (res);
}

char	*realloc_this(char *old_line, int j)
{
  char	*new_line;
  int	i;

  i = 0;
  if ((new_line = malloc(sizeof(char) * (j + READ_SIZE + 1))) == NULL)
    return (NULL);
  while (i <= j)
    {
      new_line[i] = old_line[i];
      i = i + 1;
    }
  free(old_line);
  return (new_line);
}

char	*get_next_line(const int fd)
{
  char	*whole_line;
  char	next_char;
  int	j;

  j = 0;
  next_char = get_next_char(fd);
  if (next_char == 0)
    return (NULL);
  if ((whole_line = malloc(sizeof(char) * READ_SIZE + 1)) == NULL)
    return (NULL);
  while (next_char != '\n' && next_char != '\0')
    {
      whole_line[j] = next_char;
      if (((j + 1) % READ_SIZE) == 0)
	{
	  if ((whole_line = realloc_this(whole_line, j)) == NULL)
	    return (NULL);
	}
      j = j + 1;
      next_char = get_next_char(fd);
    }
  whole_line[j] = '\0';
  return (whole_line);
}
