NAME = tutorial

SRC 		= checks.c end.c game_actions.c init.c main.c mlb_actions.c parsing.c render_interface.c render.c utils.c
SRCS_DIR 		= ./src/
SRCS 			= $(addprefix $(SRCS_DIR), $(SRC))

OBJS			=  ${SRCS:.c=.o}

FLAGS = -Wall -Wextra #-Werror

#MAC LINKS = -I./minilibx_opengl -L./minilibx_opengl -lmlx -framework OpenGL -framework AppKit
LINKS = -I ./mlx-linux -lXext -lX11 -lm -lbsd

# Remember to implement your rules...
INCLUDES = -I/opt/X11/include -Imlx
#$(INCLUDES) dan le .c.o

all : $(NAME)

.c.o:
	cc $(FLAGS) -I ./include/ -c $< -o ${<:.c=.o} $(INCLUDES)

$(NAME): $(OBJS)
	gcc $(FLAGS) $(SRCS) -o $(NAME) ./mlx-linux/libmlx.a $(LINKS)

clean :
	rm -f ${OBJS}

fclean : clean
	rm -f ${NAME}

re : fclean all

.PHONY: all clean fclean re