/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 18:28:38 by gedemais          #+#    #+#             */
/*   Updated: 2019/06/10 22:03:40 by gedemais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		ft_exit(void)
{
	exit(EXIT_SUCCESS);
}

double	ft_sq(double nb)
{
	return (nb * nb);
}

char	*ft_clear_image(void *param, char *img_data)
{
	ft_memset(((t_mlx*)param)->img_data, 0, HGT * WDT * 4);
	mlx_put_image_to_window((t_mlx*)param, ((t_mlx*)param)->mlx_win,
			((t_mlx*)param)->img_ptr, 0, 0);
	return (img_data);
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
	double	tx;
	double	ty;

	s = ((t_multi*)param);
	if (s->mask == MANDELBROT)
	{
		tx = (s->z_re + s->z_re) * s->z_im;
		ty = s->z_re2 - s->z_im2;
		return ((w == 'x') ? (tx + s->c_im) : ty + s->c_re);
	}
	else if (s->mask == JULIA)
	{
		tx = ((s->z_re + s->z_re)) * s->z_im;
		ty = s->z_re2 - s->z_im2;
		return ((w == 'x') ? tx + *julia_x() : ty + *julia_y());
	}
	else if (s->mask == BURNINGSHIP)
	{
		tx = 2 * fabs(s->z_re * s->z_im);
		ty = s->z_re2 - s->z_im2;
		return ((w == 'x') ? -tx + s->c_im : ty + s->c_re);
	}
	else
		return (0);
}
