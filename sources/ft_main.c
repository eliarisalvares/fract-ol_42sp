/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 13:51:22 by elraira-          #+#    #+#             */
/*   Updated: 2021/12/02 18:59:44 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Main function check and validates arguments and allocates memory for the 
structs. If allocation fails, an error message is displayed. Also, here we 
define window configurations, such as height, width and display shift. */

#include "../includes/ft_fractol.h"

int	main(int argc, char **argv)
{
	t_fractol	*ptr;

	ptr = NULL;
	ptr = (t_fractol *)malloc(sizeof(t_fractol));
	if (!ptr)
		ft_error_message();
	ptr->img = (t_img *)malloc(sizeof(t_img));
	if (!ptr->img)
		ft_error_message();
	ptr->window_width = 600;
	ptr->window_height = 600;
	ptr->display_shift = 0.1;
	if (argc < 2 || argc > 4 || ft_check_fractal_name(ptr, argv, argc) != 1)
	{
		ft_usage_message();
	}
	else
		ft_init_hooks_and_loop(ptr);
	return (0);
}

int	ft_check_fractal_name(t_fractol *ptr, char **argv, int argc)
{
	if (!ft_strncmp("mandelbrot", argv[1], 10))
		ptr->fractal_name = 1;
	else if (!ft_strncmp("julia", argv[1], 5))
	{
		ptr->fractal_name = 2;
		ft_validating_julia_parameters(argc, argv, ptr);
	}
	else if (!ft_strncmp("burning-ship", argv[1], 11))
		ptr->fractal_name = 3;
	else
		return (0);
	ft_init_each_fractal_settings(ptr);
	return (1);
}

void	ft_init_each_fractal_settings(t_fractol *ptr)
{
	if (ptr->fractal_name == 1)
		ft_mandelbrot_settings(ptr);
	else if (ptr->fractal_name == 2)
		ft_julia_settings(ptr);
	else if (ptr->fractal_name == 3)
		ft_burning_ship_settings(ptr);
}

void	ft_launch_each_fractal(t_fractol *ptr)
{
	if (ptr->fractal_name == 1)
		ft_calculate_and_launch_mandelbrot(ptr);
	else if (ptr->fractal_name == 2)
		ft_calculate_and_launch_julia(ptr);
	else if (ptr->fractal_name == 3)
		ft_calculate_and_launch_burning_ship(ptr);
}
