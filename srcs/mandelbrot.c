/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 19:17:04 by gedemais          #+#    #+#             */
/*   Updated: 2019/06/08 12:26:16 by gedemais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

bool	ft_check(void *param)
{
	t_multi	*s;
	double	tmp;
	double	p;

	s = ((t_multi*)param);
	s->z_re2 = s->z_re * s->z_re;
	s->z_im2 = s->z_im * s->z_im;
	p = sqrt(ft_sq((s->z_re - (0.25))) + s->z_im2);
	tmp = ft_sq(p);
	if (s->z_re2 + s->z_im2 > 4 || s->z_re < p - (tmp + tmp + 0.25))
		return (false);
	s->z_im = ft_fractals_tree(param, 'x');
	s->z_re = ft_fractals_tree(param, 'y');
	return (true);
}

bool	ft_is_inside(void *param)
{
	t_multi	*s;

	s = ((t_multi*)param);
	s->c_re = s->MinRe + s->x * s->Re_factor;
	s->z_re = s->c_re;
	s->z_im = s->c_im;
	s->n = 0;
	while (s->n < s->MaxIterations)
	{
		if (ft_check(param) == false)
			return (false);
		s->n++;
	}
	return (true);
}

void	*ft_multibrot(void *param)
{
	t_multi	*s;
	int		loop;
	double	tmp;

	s = ((t_multi*)param);
	loop = ((s->index + 1) * (HGT / NB_THREADS));
	s->MaxIm = s->MinIm + (s->MaxRe - s->MinRe) * HGT / WDT;
	s->Re_factor = (s->MaxRe - s->MinRe) / WDT;
	s->Im_factor = (s->MaxIm - s->MinIm) / HGT;
	while (++s->y < loop)
	{
		s->x = 0;
		s->c_im = s->MaxIm - s->y * s->Im_factor;
		while (++s->x < WDT)
		{
			if (ft_is_inside(param))
				continue ;
			else
				ft_fill_pixel(s->img, s->x, s->y, ft_palette_tree(s->n,
					s->MaxIterations, s->palette, s->psychedelic));
		}
	}
	pthread_exit(NULL);
}

void	ft_init_thread(t_multi *thread, t_fract *draw, int i)
{
	thread->MaxRe = draw->MaxRe;
	thread->MinRe = draw->MinRe;
	thread->MaxIm = draw->MaxIm;
	thread->MinIm = draw->MinIm;
	thread->c_im = draw->c_im;
	thread->c_re = draw->c_re;
	thread->z_re = draw->z_re;
	thread->z_re2 = draw->z_re2;
	thread->z_im = draw->z_im;
	thread->z_im2 = draw->z_im2;
	thread->Re_factor = draw->Re_factor;
	thread->Im_factor = draw->Im_factor;
	thread->MaxIterations = draw->MaxIterations;
	thread->n = draw->n;
	thread->x = 0;
	thread->y = i * ((HGT - 1) / NB_THREADS);
	thread->scale = draw->scale;
	thread->index = i;
	thread->psychedelic = draw->psychedelic;
	thread->mask = draw->mask;
}

char	*ft_mandelbrot(char *img, int palette, t_fract *draw)
{
	t_multi	multi[NB_THREADS];
	int		i;

	i = 0;
	while (i < NB_THREADS)
	{
		ft_init_thread(&multi[i], draw, i);
		multi[i].img = img;
		multi[i].palette = palette;
		if (pthread_create(&multi[i].thread, NULL, ft_multibrot, &multi[i]))
			return (NULL);
		i++;
	}
	i = 0;
	while (i < NB_THREADS)
	{
		if (pthread_join(multi[i].thread, NULL))
			return (NULL);
		i++;
	}
	return (img);
}
