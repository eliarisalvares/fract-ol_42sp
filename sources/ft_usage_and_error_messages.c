/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usage_and_error_messages.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 18:33:27 by elraira-          #+#    #+#             */
/*   Updated: 2021/12/02 19:45:51 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_fractol.h"

void	ft_usage_message(void)
{
	printf("           ,\n          _o_\n    ._ ,o     `o'\n----(_)        :");
	printf("\n     '  `.     .o\n         -~o~'\n           '\n\n");
	printf("Hello!\nTo generate a fractal, you must choose one of the ");
	printf("following:\n\n1. mandelbrot\n2. julia + complex number between -2");
	printf(".000 and 2.000 (±x.xxx ±x.xxx)\n\nWhich means ");
	printf("your input should look something like this:\n\n\t");
	printf("./fractol julia −0.823 0.156\n\nBUT ATTENTION! It is case ");
	printf("sensitive, so please all lowercase!");
	printf("\n\nYou can also press the arrow keys to go up and down and left");
	printf(" and right,\nuse the mouse scroll to zoom in and out and press ");
	printf("'C' to change the color palette!\nv(⌒o⌒)v\n");
	exit(0);
}

void	ft_julia_usage_message(void)
{
	printf("               .#              \n       #*/ .       )\n");
	printf("   #(.&*  */&,      *    ,  .  \n       /.   &      . *,   /, *\n");
	printf("              ,   . (/  .#     \n                #/\n");
	printf("\nHello!\n\nTo generate a julia fractal, you must type in one ");
	printf("complex number between -2.000 and 2.000 right after calling\n\t");
	printf("./fractol julia.\n\nComplex numbers are composed of one real par");
	printf("t and one imaginary part!\nSo, you actually need to type two ");
	printf("different values separated by a space (' ')\n\nSuch as:\n\n\t");
	printf("0.701 -0.382\n\t-0.726 0.189\n\t0.000 -0.800\n");
	exit(0);
}

void	ft_error_message(void)
{
	printf("Sorry, an error occurred!\n");
	exit(0);
}
