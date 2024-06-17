NAME = tutorial

SOURCES = tutorial.c

OBJECTS = $(subst .c,.o,$(SOURCES))

FLAGS = -Wall -Wextra #-Werror
LINKS = -I./minilibx_opengl -L./minilibx_opengl -lmlx -framework OpenGL -framework AppKit

# Remember to implement your rules...
INCLUDES = -I/opt/X11/include -Imlx

.c.o:
	$(CC) $(CFLAGS) -c -o $@ $< $(INCLUDES)

$(NAME): $(OBJECTS)
	gcc $(SOURCES) -o $(NAME) $(FLAGS) $(LINKS)
