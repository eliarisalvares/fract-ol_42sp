/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractol.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 13:51:22 by elraira-          #+#    #+#             */
/*   Updated: 2021/12/02 15:40:13 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_fractol.h"

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
