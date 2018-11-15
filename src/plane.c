/*
** plane.c for raytracer1 in /home/mael/raytracer1
**
** Made by mael drapier
** Login   <mael.drapier@epitech.eu@epitech.net>
**
** Started on  Wed Feb 22 14:06:04 2017 mael drapier
** Last update Wed Mar  8 17:08:24 2017 mael drapier
*/

#include <SFML/Graphics/RenderWindow.h>

float	intersect_plane(sfVector3f eye_pos, sfVector3f dir_vector)
{
  float	k;

  if (dir_vector.z == 0)
    return (-1.0);
  k = (-1 * eye_pos.z) / dir_vector.z;
  if (k <= 0)
    return (-1.0);
  return (k);
}

sfVector3f	get_normal_plane(int upward)
{
  sfVector3f	res;

  res.x = 0;
  res.y = 0;
  if (upward == 0)
    res.z = 100;
  else
    res.z = 100;
  return (res);
}
