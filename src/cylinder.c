/*
** cylinder.c for raytracer1 in /home/mael/raytracer1
**
** Made by mael drapier
** Login   <mael.drapier@epitech.eu@epitech.net>
**
** Started on  Wed Feb 22 14:06:23 2017 mael drapier
** Last update Wed Mar  8 16:30:19 2017 mael drapier
*/

#include <SFML/Graphics/RenderWindow.h>
#include <math.h>
#include "raytracer1.h"

float	intersect_cylinder(sfVector3f eye_pos, sfVector3f dir_vector,
			   float radius)
{
  sfVector3f	abc;
  float		delta;

  if (radius == 0)
    return (-1.0);
  abc.x = powf(dir_vector.x, 2) + powf(dir_vector.y, 2);
  abc.y = 2 * (eye_pos.x * dir_vector.x + eye_pos.y * dir_vector.y);
  abc.z = powf(eye_pos.x, 2) + powf(eye_pos.y, 2) - powf(radius, 2);
  delta = powf(abc.y, 2) - (4 * abc.x * abc.z);
  return (use_delta(abc, delta));
}

sfVector3f	get_normal_cylinder(sfVector3f intersection_point)
{
  sfVector3f	res;

  res.x = intersection_point.x;
  res.y = intersection_point.y;
  res.z = 0;
  return (res);
}
