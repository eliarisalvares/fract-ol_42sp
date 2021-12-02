/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractol.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 13:18:24 by elraira-          #+#    #+#             */
/*   Updated: 2021/12/02 19:50:22 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FRACTOL_H
# define FT_FRACTOL_H

/*.................MinilibX is mandatory for project graphics.................*/
# include "../minilibx-linux/mlx.h"

/*......................The math.h header defines various mathematical functions
and one macro. All the functions available in this library take double as an 
argument and return double as the result.....................................*/
# include <math.h>
# include <stdio.h>
# include <stdlib.h>

/*..................................Keycodes..................................*/
# define KEY_C 99
# define ESC 65307
# define ARROW_LEFT 65361
# define ARROW_UP 65362
# define ARROW_RIGHT 65363
# define ARROW_DOWN 65364
# define ZOOM_OUT 5
# define ZOOM_IN 4

/*..............MiniLibX basics to create and render images...................*/

typedef struct s_img
{
	void	*mlx_img;
	char	*data;
	int		line_length;
	int		bits_per_pixel;
	int		endian;
}t_img;

/*..........Everything needed to create the fractals images and run the program.
......................Will be referenced as "t_fractol *ptr".................*/

typedef struct s_fractol
{
	void	*mlx_win;
	void	*mlx_ptr;
	int		window_width;
	int		window_height;
	int		color;
	int		fractal_name;
	int		x;
	double	x_min;
	double	x_max;
	int		y;
	double	y_min;
	double	y_max;
	double	zoom_x;
	double	zoom_y;
	int		img_x;
	int		img_y;
	double	z_real;
	double	z_im;
	double	c_real;
	double	c_im;
	double	iteration;
	double	temp;
	float	display_shift;
	int		max_iteration;
	t_img	*img;
}				t_fractol;

/* .....................Usage message functions.............................. */

/**
 * @brief Displays error message when something doesn't work properly with the
 * MinilibX.
 * 
 */
void			ft_error_message(void);
/**
 * @brief The subject demands for a usage message whenever completed
 * parameters are not passed correctly. This function displays everything needed
 * for the user to generate the fractals.
 */
void			ft_usage_message(void);
/**
 * @brief Displays informations about how to pass parameters to generate the 
 * julia fractal correctly.
 * 
 */
void			ft_julia_usage_message(void);

/*................Functions to receive and validate arguments.................*/

int				ft_main(int argc, char **argv);
int				ft_check_fractal_name(t_fractol *ptr, char **argv, int argc);
void			ft_init_each_fractal_settings(t_fractol *ptr);
void			ft_launch_each_fractal(t_fractol *ptr);

/*.........Functions that will create ./fractol images and windows ...........*/

int				ft_init_mlx(t_fractol *ptr);
void			ft_draw_pixels(int x, int y, int color, t_fractol *ptr);
int				ft_put_image_to_window(t_fractol *ptr);

/*...................Destroys processes and close program ....................*/

void			ft_destroy_fractol(t_fractol *ptr);

/*............Mandelbrot calculation and init functions.......................*/

void			ft_mandelbrot_settings(t_fractol *ptr);
void			ft_init_mandelbrot(t_fractol *ptr);
void			ft_calculate_and_launch_mandelbrot(t_fractol *ptr);

/* .................Julia calculation and init functions......................*/

/**
 * @brief receive the arguments to validate the complex number given to generate
 * the julia fractal, destroys everything in case there's an error.
 * 
 * @param argc number of arguments
 * @param argv array of arguments
 */
void			ft_validating_julia_parameters(int argc,
					char *argv[], t_fractol *ptr);
void			ft_julia_settings(t_fractol *ptr);
void			ft_calculate_and_launch_julia(t_fractol *ptr);

/*................Burning Ship calculation and init functions.................*/

void			ft_burning_ship_settings(t_fractol *ptr);
void			ft_init_burning_ship(t_fractol *ptr);
void			ft_calculate_and_launch_burning_ship(t_fractol *ptr);

/*....................................Hooks...................................*/

/**
 * @brief manages key actions
 * 
 * @param keycode the correspondent keycode
 */
int				ft_key_hook(int keycode, t_fractol *ptr);
/**
 * @brief manages zoom in and out
 * 
 * @param keycode keycode for scroll up and down
 * @param x x axis
 * @param y y axis
*/
int				ft_zoom_hook(int keycode, int x, int y, t_fractol *ptr);

/**
 * @brief initiates zoom and key hooks as well as mlx and the loop that will 
 * keep the minilibX running and the program window open.
 * 
 * @param ptr t_fractol struct
 */
int				ft_init_hooks_and_loop(t_fractol *ptr);

/*..............................Libft Functions...............................*/

/**
 * @brief checks if the passed character is a decimal digit character -
 * 0 1 2 3 4 5 6 7 8 9.
 *
 * @param c the character to be checked.
 * @return int, this function returns non-zero value if c is a digit, else it
 * returns 0.
 */
int				ft_isdigit(int c);

/**
 * @brief responsible for taking the complex number passed as arguments (char)
 * via terminal to generate the julia fractal and converting them so 
 * calculations are possible. * 
 * @param s char argument
 * @return double 
 */
double			ft_atof(char *s);

/**
 * @brief compares at most the first n bytes of str1 and str2.
 *
 * @param s1 this is the first string to be compared.
 * @param s2 this is the second string to be compared.
 * @param n the first n bytes of to be compared
 * @return if Return value < 0 then it indicates str1 is less than str2. If
 * Return value > 0 then it indicates str2 is less than str1. If Return
 * value = 0 then it indicates str1 is equal to str2.
 */
int				ft_strncmp(const char *s1, const char *s2, size_t n);

#		endif
