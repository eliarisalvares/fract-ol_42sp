/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 13:51:22 by elraira-          #+#    #+#             */
/*   Updated: 2021/12/03 16:28:10 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_fractol.h"

int	ft_zoom_hook(int keycode, int x, int y, t_fractol *ptr)
{
	double	tmp_x;
	double	tmp_y;

	tmp_x = x / ptr->zoom_x + ptr->x_min;
	tmp_y = y / ptr->zoom_y + ptr->y_min;
	if (keycode == ZOOM_IN)
	{
		ptr->zoom_x *= 1.1;
		ptr->zoom_y *= 1.1;
		ptr->display_shift /= 1.1;
	}
	if (keycode == ZOOM_OUT)
	{
		ptr->zoom_x /= 1.1;
		ptr->zoom_y /= 1.1;
		ptr->display_shift *= 1.1;
	}
	ptr->x_min = tmp_x - (x / ptr->zoom_x);
	ptr->y_min = tmp_y - (y / ptr->zoom_y);
	ft_put_image_to_window(ptr);
	return (0);
}

int	ft_key_hook(int keycode, t_fractol *ptr)
{
	if (keycode == ESC)
		ft_destroy_fractol(ptr);
	if (keycode == KEY_C)
		ptr->color = ptr->color + 0xF0A0F0;
	if (keycode == ARROW_UP)
		ptr->y_min = ptr->y_min - ptr->display_shift;
	if (keycode == ARROW_DOWN)
		ptr->y_min = ptr->y_min + ptr->display_shift;
	if (keycode == ARROW_LEFT)
		ptr->x_min = ptr->x_min - ptr->display_shift;
	if (keycode == ARROW_RIGHT)
		ptr->x_min = ptr->x_min + ptr->display_shift;
	ft_put_image_to_window(ptr);
	return (0);
}
