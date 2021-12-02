NAME			=	fractol

SRCS_DIR		=	./sources/

INCLUDES		=	./includes/

AR				=	ar
ARFLAGS			=	rcs

SRCS_F			=	ft_main.c \
					ft_usage_and_error_messages.c \
					ft_init_mlx.c \
					ft_create_image.c \
					ft_hooks.c \
					ft_fractal_julia.c \
					ft_fractal_mandelbrot.c \
					ft_fractal_burning_ship.c \
					ft_destroy_fractol.c \
					ft_libft_strncmp.c \
					ft_libft_atof.c 

SRCS			= 	$(addprefix $(SRCS_DIR), $(SRCS_F))

OBJS			=	$(SRCS:.c=.o)

CC				=	gcc
CC_FLAGS		= 	-Wall -Wextra -Werror -g -O3

RM				=	rm -f

.c.o:			
				$(CC) $(C_FLAGS) -c $< -o $(<:.c=.o) -I ./includes -I ./minilibx-linux


$(NAME):		$(OBJS)
				make -sC ./minilibx-linux all
				$(CC) $(CC_FLAGS) $(OBJS) -o $(NAME) -L ./minilibx-linux -lmlx -lXext -lX11 -lm

all:			$(NAME)

clean:
				make -sC ./minilibx-linux clean
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean all

.PHONY:			all clean fclean re