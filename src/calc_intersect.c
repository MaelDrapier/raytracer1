/*
** calc_intersect.c for raytracer1 in /home/mael/raytracer1
**
** Made by mael drapier
** Login   <mael.drapier@epitech.eu@epitech.net>
**
** Started on  Wed Mar  8 11:39:42 2017 mael drapier
** Last update Fri Mar 10 14:00:48 2017 mael drapier
*/

#include <math.h>
#include "raytracer1.h"

sfVector3f	calc_point(sfVector3f dir_vector, float k)
{
  sfVector3f	point;

  point.x = EYE_X + ((k - (k / 100)) * dir_vector.x);
  point.y = EYE_Y + ((k - (k / 100)) * dir_vector.y);
  point.z = EYE_Z + ((k - (k / 100)) * dir_vector.z);
  return (point);
}

sfVector3f	calc_light_vector(sfVector3f point)
{
  sfVector3f	d_light;

  d_light.x = LIGHT_X - point.x;
  d_light.y = LIGHT_Y - point.y;
  d_light.z = LIGHT_Z - point.z;
  return (d_light);
}

void	calc_brightness(t_pos *data, t_conf obj, float k)
{
  data->point = calc_point(data->d_vector, k);
  data->d_light = calc_light_vector(data->point);
  data->point = translate(data->point, obj.trans);
  data->d_light = rotate_xyz(data->d_light, obj.rot);
  data->point = rotate_xyz(data->point, obj.rot);
  if (obj.nb == 1)
    {
      data->normal = get_normal_sphere(data->point);
      data->coeff_sphere = get_light_coef(data->d_light, data->normal);
    }
  else if (obj.nb == 2)
    {
      data->normal = get_normal_cylinder(data->point);
      data->coeff_cylinder = get_light_coef(data->d_light, data->normal);
    }
  else
    {
      data->normal = get_normal_cone(data->point, obj.var);
      data->coeff_cone = get_light_coef(data->d_light, data->normal);
    }
}

void	calc_all(t_pos *data, t_dist *k, t_conf obj)
{
  k->tmp_sphere = intersect_sphere(obj.eye, obj.vect, obj.var);
  if (obj.nb == 1 && k->tmp_sphere < k->sphere && k->tmp_sphere > 0)
    {
      k->sphere = k->tmp_sphere;
      calc_brightness(data, obj, k->sphere);
    }
  k->tmp_cylinder = intersect_cylinder(obj.eye, obj.vect, obj.var);
  if (obj.nb == 2 && k->tmp_cylinder < k->cylinder && k->tmp_cylinder > 0)
    {
      k->cylinder = k->tmp_cylinder;
      calc_brightness(data, obj, k->cylinder);
    }
  k->tmp_cone = intersect_cone(obj.eye, obj.vect, obj.var);
  if (obj.nb == 3 && k->tmp_cone < k->cone && k->tmp_cone > 0)
    {
      k->cone = k->tmp_cone;
      calc_brightness(data, obj, k->cone);
    }
}

void		draw_shadow(t_my_framebuffer *framebuffer, t_pos *data,
			    t_conf *obj, t_dist *k)
{
  int		j;
  int		res;

  j = 0;
  res = 0;
  if (data->color.a > 40)
    data->color.a = 40;
  data->point = calc_point(data->d_vector, k->shadow);
  data->d_light = calc_light_vector(data->point);
  while (j < obj[0].elem)
    {
      obj[j] = modifier(obj[j], data->point, data->d_light);
      if (obj[j].nb == 1)
	k->sphere = intersect_sphere(obj[j].eye, obj[j].vect, obj[j].var);
      if (obj[j].nb == 2)
	k->cylinder = intersect_cylinder(obj[j].eye, obj[j].vect, obj[j].var);
      if (obj[j].nb == 3)
	k->cone = intersect_cone(obj[j].eye, obj[j].vect, obj[j].var);
      if (k->sphere > 0 || k->cylinder > 0 || k-> cone > 0)
	res = 1;
      j = j + 1;
    }
  if (res != 0)
    my_put_pixel(framebuffer, data->s_pos.x, data->s_pos.y, data->color);
}
