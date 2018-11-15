/*
** cone.c for raytracer1 in /home/mael/raytracer1
**
** Made by mael drapier
** Login   <mael.drapier@epitech.eu@epitech.net>
**
** Started on  Wed Feb 22 14:05:45 2017 mael drapier
** Last update Fri Mar 10 14:07:09 2017 mael drapier
*/

#include <SFML/Graphics/RenderWindow.h>
#include <math.h>
#include "raytracer1.h"

float		intersect_cone(sfVector3f eye_pos, sfVector3f dir_vector,
			       float semiangle)
{
  sfVector3f	abc;
  float		angle;
  float		delta;

  if (semiangle == 0)
    return (-1.0);
  angle = (semiangle * M_PI) / 180;
  abc.x = powf(dir_vector.x, 2) + powf(dir_vector.y, 2);
  abc.x = abc.x - (powf(tanf(angle), 2) * powf(dir_vector.z, 2));
  abc.y = (2 * eye_pos.x * dir_vector.x) + (2 * eye_pos.y * dir_vector.y);
  abc.y = abc.y - (powf(tanf(angle), 2) * (2 * eye_pos.z * dir_vector.z));
  abc.z = powf(eye_pos.x, 2) + powf(eye_pos.y, 2);
  abc.z = abc.z - (powf(tanf(angle), 2) * powf(eye_pos.z, 2));
  delta = powf(abc.y, 2) - (4 * abc.x * abc.z);
  return (use_delta(abc, delta));
}

sfVector3f	get_normal_cone(sfVector3f intersection_point, float semiangle)
{
  sfVector3f	res;

  semiangle = (semiangle * M_PI) / 180;
  res.x = intersection_point.x;
  res.y = intersection_point.y;
  res.z = (semiangle * -1) * intersection_point.z;
  return (res);
}
