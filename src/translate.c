/*
** translate.c for raytracer1 in /home/mael/raytracer1
**
** Made by mael drapier
** Login   <mael.drapier@epitech.eu@epitech.net>
**
** Started on  Wed Feb 22 14:05:02 2017 mael drapier
** Last update Fri Mar  3 17:42:34 2017 mael drapier
*/

#include <SFML/Graphics/RenderWindow.h>

sfVector3f	translate(sfVector3f to_translate, sfVector3f translations)
{
  sfVector3f	to_return;

  to_return.x = to_translate.x + translations.x;
  to_return.y = to_translate.y + translations.y;
  to_return.z = to_translate.z + translations.z;
  return (to_return);
}
