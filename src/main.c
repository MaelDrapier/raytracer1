/*
** main.c for raytracer1 in /home/mael/raytracer1
**
** Made by mael drapier
** Login   <mael.drapier@epitech.eu@epitech.net>
**
** Started on  Wed Feb 22 14:13:19 2017 mael drapier
** Last update Sun Mar 12 15:07:59 2017 mael drapier
*/

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include <stdlib.h>
#include "raytracer1.h"

void	core_loop(t_display *display, t_my_framebuffer *framebuffer)
{
  sfRenderWindow_clear(display->window, sfBlack);
  sfTexture_updateFromPixels(display->texture, framebuffer->pixels,
			     WIDTH, HEIGHT, 0, 0);
  sfRenderWindow_drawSprite(display->window, display->sprite, NULL);
  sfRenderWindow_display(display->window);
  while (sfRenderWindow_isOpen(display->window))
    {
      while (sfRenderWindow_waitEvent(display->window, &display->event))
	{
	  if (display->event.type == sfEvtClosed)
	    sfRenderWindow_close(display->window);
	  if (display->event.key.code == sfKeyEscape)
	    sfRenderWindow_close(display->window);
	}
    }
}

int	core(t_display *display, t_my_framebuffer *framebuffer, t_conf *obj)
{
  t_pos	data;

  data.s_size.x = WIDTH;
  data.s_size.y = HEIGHT;
  data.eye_pos.x = EYE_X;
  data.eye_pos.y = EYE_Y;
  data.eye_pos.z = EYE_Z;
  data.s_pos.x = 0;
  data.s_pos.y = 0;
  display->window = create_win("raytracer1", WIDTH, HEIGHT);
  display->sprite = sfSprite_create();
  display->texture = sfTexture_create(WIDTH, HEIGHT);
  sfSprite_setTexture(display->sprite, display->texture, sfTrue);
  drawing(framebuffer, &data, obj);
  core_loop(display, framebuffer);
  return (0);
}

void	free_this(t_display *display, t_my_framebuffer *framebuffer)
{
  free(framebuffer->pixels);
  sfTexture_destroy(display->texture);
  sfSprite_destroy(display->sprite);
  sfRenderWindow_destroy(display->window);
}

int			main(int ac, char **av)
{
  t_display		display;
  t_my_framebuffer	framebuffer;
  t_conf		*obj;

  obj = NULL;
  framebuffer = my_framebuffer_create(WIDTH, HEIGHT);
  if (ac != 2)
    {
      my_putstr(2, USAGE);
      return (RETURN_FAIL);
    }
  obj = read_objects(obj, av[1]);
  if (obj == NULL)
    {
      my_putstr(2, ERROR_FILE1);
      my_putstr(2, av[1]);
      my_putstr(2, ERROR_FILE2);
      return (RETURN_FAIL);
    }
  core(&display, &framebuffer, obj);
  free_this(&display, &framebuffer);
  return (RETURN_SUCCESS);
}
