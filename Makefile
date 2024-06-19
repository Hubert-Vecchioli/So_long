
#so_long
NAME = so_long

SRC 		= checks.c checks_utils.c end.c game_actions.c init.c main.c mlb_actions.c parsing.c render.c utils.c
SRCS_DIR 		= ./src/
SRCS 			= $(addprefix $(SRCS_DIR), $(SRC))
OBJS			=  ${SRCS:.c=.o}
FLAGS       = -Wall -Wextra -Werror -Imlx -I ./include -I$(LIBFT_DIR)

INCLUDES = -I /opt/X11/include
LINKS = -I ./mlx-linux -lXext -lX11 -lm -lbsd
MLX_PATH	= $(MLX_DIR)/libmlx.a

# LIBFT
LIBFT_DIR	= ./libft
#MAKE_LIBFT	= make -s -C $(LIBFT_DIR)
LIBFT_PATH	= $(LIBFT_DIR)/libft.a

all : $(NAME)

.c.o:
	cc $(FLAGS) -I ./include/ -c $< -o ${<:.c=.o} $(INCLUDES)

$(NAME): $(OBJS)
	gcc $(FLAGS) $(OBJS) $(LIBFT_PATH) -o $(NAME) ./mlx-linux/libmlx.a $(LINKS)

clean :
	rm -f ${OBJS}

fclean : clean
	rm -f ${NAME}

re : fclean all

.PHONY: all clean fclean re