/*
** display.c for raytracing1 in /home/mael/raytracer1
**
** Made by mael drapier
** Login   <mael.drapier@epitech.eu@epitech.net>
**
** Started on  Tue Mar  7 00:41:43 2017 mael drapier
** Last update Tue Mar  7 00:50:15 2017 mael drapier
*/

#include <unistd.h>

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      i = i + 1;
    }
  return (i);
}

void	my_putstr(int fd, char *str)
{
  write(fd, str, my_strlen(str));
}
