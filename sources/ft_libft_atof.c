/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 14:46:21 by elraira-          #+#    #+#             */
/*   Updated: 2021/11/30 23:59:24 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_fractol.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

double	ft_atof(char *s)
{
	double	val;
	double	power;
	int		sign;
	int		i;

	sign = 1;
	val = 0.0;
	power = 1.0;
	i = 0;
	if (s[i++] == '-')
		sign = -1;
	while (ft_isdigit(s[i]))
	{
		val = 10.0 * val + (s[i] - '0');
		i++;
	}
	if (s[i] == '.')
		i++;
	while (ft_isdigit(s[i]))
	{
		val = 10.0 * val + (s[i] - '0');
		power *= 10.0;
		i++;
	}
	return (sign * val / power);
}
