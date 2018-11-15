/*
** calc_dir_vector.c for raytracer1 in /home/mael/raytracer1
**
** Made by mael drapier
** Login   <mael.drapier@epitech.eu@epitech.net>
**
** Started on  Wed Feb 22 14:02:38 2017 mael drapier
** Last update Tue Mar  7 22:26:58 2017 mael drapier
*/

#include <SFML/Graphics/RenderWindow.h>

sfVector3f	calc_dir_vector(float dist_to_plane, sfVector2i screen_size,
				sfVector2i screen_pos)
{
  sfVector3f	dir_vector;

  dir_vector.x = dist_to_plane;
  dir_vector.y = (screen_size.x / 2) - screen_pos.x;
  dir_vector.z = (screen_size.y / 2) - screen_pos.y;
  return (dir_vector);
}
