/*
** more_calc.c for raytracer1 in /home/mael/raytracer1
**
** Made by mael drapier
** Login   <mael.drapier@epitech.eu@epitech.net>
**
** Started on  Thu Mar  9 17:50:59 2017 mael drapier
** Last update Thu Mar  9 17:54:31 2017 mael drapier
*/

#include "raytracer1.h"

void	set_plane_fade(t_pos *data, t_dist *k, float tmp)
{
  if (k->plane == tmp && tmp < 10000000)
    {
      data->point = calc_point(data->d_vector, k->plane);
      data->d_light = calc_light_vector(data->point);
      data->normal = get_normal_plane(1);
      data->coeff_plane = get_light_coef(data->d_light, data->normal);
      if (data->coeff_plane > 0)
	data->color.a = data->color.a * data->coeff_plane;
      else
	data->color = sfBlack;
    }
}
