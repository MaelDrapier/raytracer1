/*
** raytracer1.h for raytracer1 in /home/mael/raytracer1
**
** Made by mael drapier
** Login   <mael.drapier@epitech.eu@epitech.net>
**
** Started on  Mon Feb 13 14:10:42 2017 mael drapier
** Last update Sun Mar 12 15:07:49 2017 mael drapier
*/

#ifndef RAYTRACER1_H_
# define RAYTRACER1_H_

# include "struct.h"
# define RETURN_SUCCESS 0
# define RETURN_FAIL 84
# define USAGE "Usage: ./raytracer1 [config_file]\n"
# define ERROR_FILE1 "Config file '"
# define ERROR_FILE2 "' is invalid.\n"
# define WIDTH 1600
# define HEIGHT 900
# define EYE_X -800
# define EYE_Y 0
# define EYE_Z 100
# define LIGHT_X -800
# define LIGHT_Y 0
# define LIGHT_Z 500
# define COLOR_PLANE (sfColor) {0, 0, 255, 255}
# define COLOR_SPHERE (sfColor) {0, 255, 255, 255}
# define COLOR_CYLINDER (sfColor) {150, 150, 150, 255}
# define COLOR_CONE (sfColor) {200, 0, 0, 255}

t_my_framebuffer	my_framebuffer_create(int wdt, int hgt);
sfRenderWindow		*create_win(char *name, int width, int height);
t_conf			*read_objects(t_conf *obj, char *filename);
void			my_put_pixel(t_my_framebuffer *framebuffer, int x,
				     int y, sfColor color);
void			my_putstr(int fd, char *str);
void			calc_all(t_pos *data, t_dist *k, t_conf obj);
void			drawing(t_my_framebuffer *framebuffer,
				t_pos *data, t_conf *obj);
void			draw_shadow(t_my_framebuffer *framebuffer, t_pos *data,
				    t_conf *obj, t_dist *k);
void			set_plane_fade(t_pos *data, t_dist *k, float tmp);
float			use_delta(sfVector3f abc, float delta);
float			intersect_sphere(sfVector3f eye_pos,
					 sfVector3f dir_vector, float radius);
float			intersect_plane(sfVector3f eye_pos,
					sfVector3f dir_vector);
float			intersect_cylinder(sfVector3f eye_pos,
					   sfVector3f dir_vector, float radius);
float			intersect_cone(sfVector3f eye_pos,
				       sfVector3f dir_vector, float semiangle);
float			get_light_coef(sfVector3f light_vector,
				       sfVector3f normal_vector);
sfVector3f		convert_radian(sfVector3f angles);
sfVector3f		reverse_angles(sfVector3f angles);
sfVector3f		calc_dir_vector(float dist_to_plane,
					sfVector2i screen_size,
					sfVector2i screen_pos);
sfVector3f		translate(sfVector3f to_translate,
				  sfVector3f translations);
sfVector3f		rotate_xyz(sfVector3f to_rotate, sfVector3f angles);
sfVector3f		rotate_zyx(sfVector3f to_rotate, sfVector3f angles);
t_conf			modifier(t_conf obj, sfVector3f eye_pos,
				 sfVector3f dir_vector);
sfVector3f		get_normal_plane(int upward);
sfVector3f		get_normal_sphere(sfVector3f intersection_point);
sfVector3f		get_normal_cylinder(sfVector3f intersection_point);
sfVector3f		get_normal_cone(sfVector3f intersection_point,
					float semiangle);
sfVector3f		calc_point(sfVector3f dir_vector, float k);
sfVector3f		calc_light_vector(sfVector3f point);

#endif /* !RAYTACER1_H_ */
