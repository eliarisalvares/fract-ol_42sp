/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_destroy_fractol.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 13:13:38 by elraira-          #+#    #+#             */
/*   Updated: 2021/11/30 23:59:17 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_fractol.h"

void	ft_destroy_fractol(t_fractol *ptr)
{
	mlx_destroy_image(ptr->mlx_ptr, ptr->img->mlx_img);
	mlx_destroy_window(ptr->mlx_ptr, ptr->mlx_win);
	mlx_destroy_display(ptr->mlx_ptr);
	free(ptr->img);
	free(ptr->mlx_ptr);
	free(ptr);
	exit(0);
}
