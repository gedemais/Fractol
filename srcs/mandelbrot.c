/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 19:17:04 by gedemais          #+#    #+#             */
/*   Updated: 2019/06/04 18:38:35 by gedemais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/fractol.h"

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
	s->z_im =  ft_fractals_tree(param, 'x');
	s->z_re =  ft_fractals_tree(param, 'y');
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
				ft_fill_pixel(s->img, s->x, s->y, ft_palette_tree(s->n, s->MaxIterations, s->palette, s->psychedelic));
		}
	}
	pthread_exit(NULL);
}

char	*ft_mandelbrot(char *img, int palette, t_fract *draw)
{
	t_multi	multi[NB_THREADS];
	int		i;

	i = 0;
	while (i < NB_THREADS)
	{
		multi[i].MaxRe = draw->MaxRe;
		multi[i].MinRe = draw->MinRe;
		multi[i].MaxIm = draw->MaxIm;
		multi[i].MinIm = draw->MinIm;
		multi[i].c_im = draw->c_im;
		multi[i].c_re = draw->c_re;
		multi[i].z_re = draw->z_re;
		multi[i].z_re2 = draw->z_re2;
		multi[i].z_im = draw->z_im;
		multi[i].z_im2 = draw->z_im2;
		multi[i].Re_factor = draw->Re_factor;
		multi[i].Im_factor = draw->Im_factor;
		multi[i].MaxIterations = draw->MaxIterations;
		multi[i].n = draw->n;
		multi[i].x = 0;
		multi[i].y = i * ((HGT - 1) / NB_THREADS);
		multi[i].scale = draw->scale;
		multi[i].img = img;
		multi[i].index = i;
		multi[i].palette = palette;
		multi[i].psychedelic = draw->psychedelic;
		multi[i].mask = draw->mask;
		if (pthread_create(&multi[i].thread, NULL, ft_multibrot, (void*)&multi[i]))
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
