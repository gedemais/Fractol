/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   singletons.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 13:07:34 by gedemais          #+#    #+#             */
/*   Updated: 2019/06/08 15:53:13 by gedemais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

double	*julia_x(void)
{
	static double	x = 0.156;

	return (&x);
}

double	*julia_y(void)
{
	static double	y = -0.8;

	return (&y);
}

int	*gpu(void)
{
	static int	val = 0;

	return (&val);
}

int	ft_screen_size(void)
{
	static int	val = HGT * WDT * sizeof(int);

	return (val);
}
