/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_mlx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 13:51:22 by elraira-          #+#    #+#             */
/*   Updated: 2021/12/03 13:44:14 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_fractol.h"

int	ft_init_hooks_and_loop(t_fractol *ptr)
{
	ft_init_mlx(ptr);
	mlx_hook(ptr->mlx_win, 2, 1L << 0, ft_key_hook, ptr);
	mlx_mouse_hook(ptr->mlx_win, ft_zoom_hook, ptr);
	mlx_loop(ptr->mlx_ptr);
	return (0);
}

int	ft_init_mlx(t_fractol *ptr)
{
	ptr->mlx_ptr = mlx_init();
	if (!(ptr->mlx_ptr))
		ft_error_message();
	ptr->mlx_win = mlx_new_window(ptr->mlx_ptr,
			ptr->window_width, ptr->window_height, "fract-ol 42_sp");
	if (!(ptr->mlx_win))
		ft_error_message();
	ft_put_image_to_window(ptr);
	return (0);
}
