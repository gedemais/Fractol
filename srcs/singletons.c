/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   singletons.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 13:07:34 by gedemais          #+#    #+#             */
/*   Updated: 2019/05/29 13:18:33 by gedemais         ###   ########.fr       */
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