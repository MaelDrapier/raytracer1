/*
** drawing.c for raytracer1 in /home/mael/raytracer1
**
** Made by mael drapier
** Login   <mael.drapier@epitech.eu@epitech.net>
**
** Started on  Thu Feb 23 13:01:21 2017 mael drapier
** Last update Sun Mar 12 15:07:18 2017 mael drapier
*/

#include <SFML/Graphics/RenderWindow.h>
#include "raytracer1.h"

sfColor	set_brightness(t_pos *data, t_dist *k, float tmp)
{
  set_plane_fade(data, k, tmp);
  if (tmp == k->sphere && tmp < 10000000)
    {
      if (data->coeff_sphere > 0)
	data->color.a = data->color.a * data->coeff_sphere;
      else
	data->color = sfBlack;
    }
  if (tmp == k->cylinder && tmp < 10000000)
    {
      if (data->coeff_cylinder > 0)
	data->color.a = data->color.a * data->coeff_cylinder;
      else
  	data->color = sfBlack;
    }
  if (tmp == k->cone && tmp < 10000000)
    {
      if (data->coeff_cone > 0)
	data->color.a = (int) data->color.a * data->coeff_cone;
      else
	data->color = sfBlack;
    }
  return (data->color);
}

float	draw_objects(t_my_framebuffer *framebuffer, t_pos *data,
		     t_dist *k, float tmp)
{
  if (k->plane > 0 && k->plane < tmp)
    {
      tmp = k->plane;
      data->color = COLOR_PLANE;
    }
  if (k->sphere > 0 && k->sphere < tmp)
    {
      tmp = k->sphere;
      data->color = COLOR_SPHERE;
    }
  if (k->cylinder > 0 && k->cylinder < tmp)
    {
      tmp = k->cylinder;
      data->color = COLOR_CYLINDER;
    }
  if (k->cone > 0 && k->cone < tmp)
    {
      tmp = k->cone;
      data->color = COLOR_CONE;
    }
  data->color = set_brightness(data, k, tmp);
  my_put_pixel(framebuffer, data->s_pos.x, data->s_pos.y, data->color);
  return (tmp);
}

t_conf	modifier(t_conf obj, sfVector3f eye_pos, sfVector3f dir_vector)
{
  obj.eye = translate(eye_pos, obj.trans);
  obj.vect = rotate_xyz(dir_vector, obj.rot);
  obj.eye = rotate_xyz(obj.eye, obj.rot);
  return (obj);
}

void		search_objects(t_my_framebuffer *framebuffer,
			       t_pos *data, t_conf *obj)
{
  t_dist	k;
  int		j;

  j = 0;
  k.sphere = 10000000;
  k.cylinder = 10000000;
  k.cone = 10000000;
  data->color = sfBlack;
  k.plane = intersect_plane(data->eye_pos, data->d_vector);
  while (j < obj[0].elem)
    {
      obj[j] = modifier(obj[j], data->eye_pos, data->d_vector);
      calc_all(data, &k, obj[j]);
      j = j + 1;
    }
  k.shadow = draw_objects(framebuffer, data, &k, 10000000);
  k.sphere = -1;
  k.cylinder = -1;
  k.cone = -1;
  draw_shadow(framebuffer, data, obj, &k);
}

void	drawing(t_my_framebuffer *framebuffer, t_pos *data, t_conf *obj)
{
  while (data->s_pos.y < HEIGHT)
    {
      while (data->s_pos.x < WIDTH)
	{
	  data->d_vector = calc_dir_vector(WIDTH, data->s_size, data->s_pos);
	  search_objects(framebuffer, data, obj);
	  data->s_pos.x = data->s_pos.x + 1;
	}
      data->s_pos.x = 0;
      data->s_pos.y = data->s_pos.y + 1;
    }
}
