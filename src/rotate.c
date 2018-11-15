/*
** rotate.c for raytracer1 in /home/mael/raytracer1
**
** Made by mael drapier
** Login   <mael.drapier@epitech.eu@epitech.net>
**
** Started on  Wed Feb 22 14:04:48 2017 mael drapier
** Last update Fri Mar 10 14:54:37 2017 mael drapier
*/

#include <SFML/Graphics/RenderWindow.h>
#include <math.h>
#include "raytracer1.h"

sfVector3f	rotate_xyz(sfVector3f to_rotate, sfVector3f angles)
{
  sfVector3f	tmp;

  angles = convert_radian(angles);
  tmp.x = to_rotate.x;
  tmp.y = to_rotate.y * cosf(angles.x);
  tmp.y = tmp.y + (to_rotate.z * (-1 * sinf(angles.x)));
  tmp.z = to_rotate.y * sinf(angles.x);
  tmp.z = tmp.z + (to_rotate.z * cosf(angles.x));
  to_rotate = tmp;
  tmp.x = to_rotate.x * cosf(angles.y);
  tmp.x = tmp.x + (to_rotate.z * sinf(angles.y));
  tmp.y = to_rotate.y;
  tmp.z = to_rotate.x * (-1 * sinf(angles.y));
  tmp.z = tmp.z + (to_rotate.z * cosf(angles.y));
  to_rotate = tmp;
  tmp.x = to_rotate.x * cosf(angles.z);
  tmp.x = tmp.x + (to_rotate.y * (-1 * sinf(angles.z)));
  tmp.y = to_rotate.x * sinf(angles.z);
  tmp.y = tmp.y + (to_rotate.y * cosf(angles.z));
  tmp.z = tmp.z;
  return (tmp);
}

sfVector3f	rotate_zyx(sfVector3f to_rotate, sfVector3f angles)
{
  sfVector3f	tmp;

  angles = convert_radian(angles);
  angles = reverse_angles(angles);
  tmp.x = to_rotate.x;
  tmp.y = to_rotate.y * cosf(angles.x);
  tmp.y = tmp.y + (to_rotate.z * (-1 * sinf(angles.x)));
  tmp.z = to_rotate.y * sinf(angles.x);
  tmp.z = tmp.z + (to_rotate.z * cosf(angles.x));
  to_rotate = tmp;
  tmp.x = to_rotate.x * cosf(angles.y);
  tmp.x = tmp.x + (to_rotate.z * sinf(angles.y));
  tmp.y = to_rotate.y;
  tmp.z = to_rotate.x * (-1 * sinf(angles.y));
  tmp.z = tmp.z + (to_rotate.z * cosf(angles.y));
  to_rotate = tmp;
  tmp.x = to_rotate.x * cosf(angles.z);
  tmp.x = tmp.x + (to_rotate.y * (-1 * sinf(angles.z)));
  tmp.y = to_rotate.x * sinf(angles.z);
  tmp.y = tmp.y + (to_rotate.y * cosf(angles.z));
  tmp.z = tmp.z;
  return (tmp);
}
