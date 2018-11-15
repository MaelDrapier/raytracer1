/*
** utils.c for raytracer1 in /home/mael/raytracer1
**
** Made by mael drapier
** Login   <mael.drapier@epitech.eu@epitech.net>
**
** Started on  Fri Mar  3 16:00:11 2017 mael drapier
** Last update Fri Mar  3 20:54:25 2017 mael drapier
*/

#include <SFML/Graphics/RenderWindow.h>
#include <math.h>

float	use_delta(sfVector3f abc, float delta)
{
  float	k1;
  float	k2;

  if (delta > 0)
    {
      k1 = ((-1 * abc.y) + sqrtf(delta)) / (2 * abc.x);
      k2 = ((-1 * abc.y) - sqrtf(delta)) / (2 * abc.x);
      if (k1 < 0 && k2 < 0)
	return (-1.0);
      if (k1 < 0 && k2 >= 0)
	return (k2);
      if (k1 > k2 && k2 > 0)
	return (k2);
    }
  else if (delta == 0)
    k1 = (-1 * abc.y) / (2 * abc.x);
  else
    k1 = -1.0;
  if (k1 < 0)
    k1 = -1.0;
  return (k1);
}

sfVector3f	convert_radian(sfVector3f angles)
{
  angles.x = (angles.x * M_PI) / 180;
  angles.y = (angles.y * M_PI) / 180;
  angles.z = (angles.z * M_PI) / 180;
  return (angles);
}

sfVector3f	reverse_angles(sfVector3f angles)
{
  angles.x = angles.x * -1;
  angles.y = angles.y * -1;
  angles.z = angles.z * -1;
  return (angles);
}
