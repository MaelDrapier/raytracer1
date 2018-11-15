/*
** light.c for raytracer1 in /home/mael/raytracer1
**
** Made by mael drapier
** Login   <mael.drapier@epitech.eu@epitech.net>
**
** Started on  Wed Feb 22 14:07:08 2017 mael drapier
** Last update Fri Mar 10 14:24:14 2017 mael drapier
*/

#include <SFML/Graphics/RenderWindow.h>
#include <math.h>
#include "raytracer1.h"

float	get_light_coef(sfVector3f light_vector, sfVector3f normal_vector)
{
  float	res;
  float	diviser;
  float	diviser_2;
  float	dot_product;

  diviser = powf(light_vector.x, 2) + powf(light_vector.y, 2);
  diviser = diviser + powf(light_vector.z, 2);
  diviser = sqrtf(diviser);
  diviser_2 = powf(normal_vector.x, 2) + powf(normal_vector.y, 2);
  diviser_2 = diviser_2 + powf(normal_vector.z, 2);
  diviser_2 = sqrtf(diviser_2);
  diviser = diviser * diviser_2;
  dot_product = light_vector.x * normal_vector.x;
  dot_product = dot_product + (light_vector.y * normal_vector.y);
  dot_product = dot_product + (light_vector.z * normal_vector.z);
  if (diviser == 0)
    return (0);
  res = dot_product / diviser;
  if (res < 0)
    return (0);
  return (res);
}
