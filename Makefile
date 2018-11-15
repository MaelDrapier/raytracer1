##
## Makefile for raytracer1 in /home/mael/raytracer1
##
## Made by mael drapier
## Login   <mael.drapier@epitech.eu@epitech.net>
##
## Started on  Mon Feb 13 13:48:58 2017 mael drapier
## Last update Thu Mar  9 18:58:25 2017 mael drapier
##

CC	=	gcc

RM	=	rm -f

CFLAGS	+=	-W -Wall -Wextra -Werror
CFLAGS	+=	-I include/

LDFLAGS	=	-lcsfml-graphics -lm

NAME	=	raytracer1

SRCS	=	src/calc_dir_vector.c \
		src/translate.c \
		src/rotate.c \
		src/sphere.c \
		src/plane.c \
		src/cone.c \
		src/cylinder.c \
		src/light.c \
		src/init.c \
		src/my_put_pixel.c \
		src/drawing.c \
		src/utils.c \
		src/get_next_line.c \
		src/get_objects.c \
		src/display.c \
		src/calc_intersect.c \
		src/more_calc.c \
		src/main.c

OBJS	=	$(SRCS:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
		$(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

clean:
		$(RM) $(OBJS)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
