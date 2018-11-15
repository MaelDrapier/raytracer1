/*
** my_put_pixel.c for raytracer1 in /home/mael/raytracer1
**
** Made by mael drapier
** Login   <mael.drapier@epitech.eu@epitech.net>
**
** Started on  Thu Feb 23 11:50:41 2017 mael drapier
** Last update Thu Feb 23 11:54:32 2017 mael drapier
*/

#include <SFML/Graphics/RenderWindow.h>
#include "struct.h"

void	my_put_pixel(t_my_framebuffer *framebuffer, int x,
		     int y, sfColor color)
{
  int	draw;

  draw = 1;
  if (x < 0 || x > framebuffer->width)
    draw = 0;
  if (y < 0 || y > framebuffer->height)
    draw = 0;
  if (draw == 1)
    {
      framebuffer->pixels[(framebuffer->width * y + x) * 4] = color.r;
      framebuffer->pixels[(framebuffer->width * y + x) * 4 + 1] = color.g;
      framebuffer->pixels[(framebuffer->width * y + x) * 4 + 2] = color.b;
      framebuffer->pixels[(framebuffer->width * y + x) * 4 + 3] = color.a;
    }
}
