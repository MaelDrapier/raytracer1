/*
** struct.h for raytracer1 in /home/mael/raytracer1
**
** Made by mael drapier
** Login   <mael.drapier@epitech.eu@epitech.net>
**
** Started on  Wed Feb 22 15:45:24 2017 mael drapier
** Last update Thu Mar  9 17:37:15 2017 mael drapier
*/

#ifndef STRUCT_H_
# define STRUCT_H_
# include <SFML/Graphics/RenderWindow.h>

typedef	struct		s_my_framebuffer
{
  sfUint8		*pixels;
  int			width;
  int			height;
}			t_my_framebuffer;

typedef	struct		s_display
{
  sfRenderWindow	*window;
  sfEvent		event;
  sfSprite		*sprite;
  sfTexture		*texture;
}			t_display;

typedef	struct		s_pos
{
  sfVector3f		eye_pos;
  sfVector3f		point;
  sfVector3f		d_vector;
  sfVector3f		d_light;
  sfVector3f		normal;
  sfColor		color;
  sfVector2i		s_size;
  sfVector2i		s_pos;
  float			coeff_sphere;
  float			coeff_cylinder;
  float			coeff_cone;
  float			coeff_plane;
}			t_pos;

typedef	struct		s_dist
{
  float			sphere;
  float			plane;
  float			cylinder;
  float			cone;
  float			tmp_sphere;
  float			tmp_cylinder;
  float			tmp_cone;
  float			shadow;
}			t_dist;

typedef	struct		s_conf
{
  sfVector3f		eye;
  sfVector3f		vect;
  sfVector3f		trans;
  sfVector3f		rot;
  int			var;
  int			nb;
  int			elem;
}			t_conf;

#endif /* !STRUCT_H_ */
