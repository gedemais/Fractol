/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 18:28:38 by gedemais          #+#    #+#             */
/*   Updated: 2019/06/04 18:46:13 by gedemais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"


int	ft_exit(void)
{
	exit(EXIT_SUCCESS);
}

double	ft_sq(double nb)
{
	return (nb * nb);
}

int		ft_palette_tree(int n, int max, int palette, bool psychedelic)
{
	if (palette == 0)
		return (ft_palette_one(n, max, psychedelic));
	else if (palette == 1)
		return (ft_palette_two(n, max, psychedelic));
	else if (palette == 2)
		return (ft_palette_three(n, max, psychedelic));
	else if (palette == 3)
		return (ft_palette_four(n, max, psychedelic));
	else if (palette == 4)
		return (ft_palette_five(n, max, psychedelic));
	else
		return (0);
}

double	ft_fractals_tree(void *param, char w)
{
	t_multi	*s;
	double	manjuliax;
	double	manjuliay;
	double	shipx;
	double	shipy;

	s = ((t_multi*)param);
	manjuliax = ((s->z_re + s->z_re)) * s->z_im;
	manjuliay = s->z_re2 - s->z_im2;
	if (s->mask & MANDELBROT)
		return ((w == 'x') ? (manjuliax + s->c_im) : manjuliay + s->c_re);
	else if (s->mask & JULIA)
	{
		return ((w == 'x') ? manjuliax + *julia_x() : manjuliay + *julia_y());
	}
	else if (s->mask & BURNINGSHIP)
	{
		shipx = ft_sq(s->z_re2);
		shipy = ft_sq(s->z_im2);
		return ((w == 'x') ? shipx + s->c_re : shipy + s->c_im);
	}
	else
		return (0);
}

