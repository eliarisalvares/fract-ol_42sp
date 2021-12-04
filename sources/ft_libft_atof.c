/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libft_atof.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 14:46:21 by elraira-          #+#    #+#             */
/*   Updated: 2021/12/04 14:32:46 by elraira-         ###   ########.fr       */
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
	double	nb;
	double	power;
	int		sign;
	int		i;

	sign = 1;
	nb = 0.0;
	power = 1.0;
	i = 0;
	if (s[i++] == '-')
		sign = -1;
	while (ft_isdigit(s[i]))
	{
		nb = 10.0 * nb + (s[i] - '0');
		i++;
	}
	if (s[i] == '.')
		i++;
	while (ft_isdigit(s[i]))
	{
		nb = 10.0 * nb + (s[i] - '0');
		power *= 10.0;
		i++;
	}
	return (sign * nb / power);
}
