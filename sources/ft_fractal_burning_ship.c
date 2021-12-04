/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractal_burning_ship.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 17:41:44 by elraira-          #+#    #+#             */
/*   Updated: 2021/12/04 14:18:06 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_fractol.h"

void	ft_burning_ship_settings(t_fractol *ptr)
{
	ptr->iteration = 0;
	ptr->x_min = -2.0;
	ptr->x_max = 2.0;
	ptr->y_min = -2.0;
	ptr->y_max = 2.0;
	ptr->zoom_x = 150;
	ptr->zoom_y = 150;
	ptr->c_real = ptr->x / ptr->zoom_x + ptr->x_min;
	ptr->c_im = ptr->y / ptr->zoom_y + ptr->y_min;
	ptr->z_real = 0;
	ptr->z_im = 0;
	ptr->max_iteration = 200;
	ptr->img_x = ptr->window_width;
	ptr->img_y = ptr->window_height;
	ptr->color = 0xFFA90CC;
}

void	ft_init_burning_ship(t_fractol *ptr)
{
	ptr->iteration = 0;
	ptr->c_real = ptr->x / ptr->zoom_x + ptr->x_min;
	ptr->c_im = ptr->y / ptr->zoom_y + ptr->y_min;
	ptr->z_real = 0;
	ptr->z_im = 0;
}

void	ft_calculate_and_launch_burning_ship(t_fractol *ptr)
{
	ptr->x = -1;
	while (++ptr->x < ptr->img_x)
	{
		ptr->y = 0;
		while (ptr->y < ptr->img_y)
		{
			ft_init_burning_ship(ptr);
			while (ptr->z_real * ptr->z_real + ptr->z_im * ptr->z_im < 4
				&& ptr->iteration < ptr->max_iteration)
			{
				ptr->temp = ptr->z_real * ptr->z_real - ptr->z_im
					* ptr->z_im + ptr->c_real;
				ptr->z_im = fabs(2 * ptr->z_im * ptr->z_real) + ptr->c_im;
				ptr->z_real = ptr->temp;
				ptr->iteration++;
			}
			ft_draw_pixels(ptr->x, ptr->y,
				ptr->iteration * ptr->color / ptr->max_iteration, ptr);
			ptr->y++;
		}
	}
}
