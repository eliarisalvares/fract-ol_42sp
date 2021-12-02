/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractal_julia.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 13:51:22 by elraira-          #+#    #+#             */
/*   Updated: 2021/12/02 19:51:52 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_fractol.h"

void	ft_validating_julia_parameters(int argc, char *argv[], t_fractol *ptr)
{
	if (argc == 4)
	{
		ptr->c_real = ft_atof(argv[2]);
		ptr->c_im = ft_atof(argv[3]);
	}
	else
		ft_julia_usage_message();
}

void	ft_julia_settings(t_fractol *ptr)
{
	ptr->iteration = 0;
	ptr->x_min = -2.0;
	ptr->x_max = 2.0;
	ptr->y_min = -2.0;
	ptr->y_max = 2.0;
	ptr->img_x = ptr->window_width;
	ptr->img_y = ptr->window_height;
	ptr->zoom_x = 150;
	ptr->zoom_y = 150;
	ptr->z_real = 0;
	ptr->z_im = 0;
	ptr->max_iteration = 200;
	ptr->color = 0xFFA90CC;
}

void	ft_init_julia(t_fractol *ptr)
{
	ptr->iteration = 0;
	ptr->z_real = ptr->x / ptr->zoom_x + ptr->x_min;
	ptr->z_im = ptr->y / ptr->zoom_y + ptr->y_min;
}

void	ft_calculate_and_launch_julia(t_fractol *ptr)
{
	ptr->x = 0;
	while (ptr->x < ptr->img_x)
	{
		ptr->y = 0;
		while (ptr->y < ptr->img_y)
		{
			ft_init_julia(ptr);
			while (ptr->z_real * ptr->z_real + ptr->z_im * ptr->z_im < 4
				&& ptr->iteration < ptr->max_iteration)
			{
				ptr->temp = ptr->z_real;
				ptr->z_real = ptr->z_real * ptr->z_real - ptr->z_im * ptr->z_im
					+ ptr->c_real;
				ptr->z_im = 2 * ptr->z_im * ptr->temp + ptr->c_im;
				ptr->iteration++;
			}
			ft_draw_pixels(ptr->x, ptr->y,
				ptr->iteration * ptr->color / ptr->max_iteration, ptr);
			ptr->y++;
		}
		ptr->x++;
	}
}
