/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 19:17:04 by gedemais          #+#    #+#             */
/*   Updated: 2019/05/24 18:54:34 by gedemais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/fractol.h"

double	ft_sq(double nb)
{
	return (nb * nb);
}

int		ft_palette_tree(int n, int max, int palette)
{
	if (palette == 0)
		return (ft_palette_one(n, max));
	else if (palette == 1)
		return (ft_palette_two(n, max));
	else if (palette == 2)
		return (ft_palette_three(n, max));
	else if (palette == 3)
		return (ft_palette_four(n, max));
	else if (palette == 4)
		return (ft_palette_five(n, max));
	else
		return (0);
}

void	*ft_multibrot(void *param)
{
	int		loop;
	bool	is_inside;
	double	p;

	loop = ((((t_multi*)param)->index + 1) * (HGT / NB_THREADS));
	((t_multi*)param)->MaxIm = ((t_multi*)param)->MinIm + (((t_multi*)param)->MaxRe - ((t_multi*)param)->MinRe)*HGT/WDT;
	((t_multi*)param)->Re_factor = (((t_multi*)param)->MaxRe - ((t_multi*)param)->MinRe) / (WDT);
	((t_multi*)param)->Im_factor = (((t_multi*)param)->MaxIm - ((t_multi*)param)->MinIm)/(HGT);
	while (++((t_multi*)param)->y < loop)
	{
		((t_multi*)param)->x = 0;
		((t_multi*)param)->c_im = ((t_multi*)param)->MaxIm - ((t_multi*)param)->y * ((t_multi*)param)->Im_factor;
		while (++((t_multi*)param)->x < WDT)
		{
			((t_multi*)param)->c_re = ((t_multi*)param)->MinRe + ((t_multi*)param)->x * ((t_multi*)param)->Re_factor;
			((t_multi*)param)->z_re = ((t_multi*)param)->c_re;
			((t_multi*)param)->z_im = ((t_multi*)param)->c_im;
			is_inside= true;
			((t_multi*)param)->n = 0;
			while (((t_multi*)param)->n < ((t_multi*)param)->MaxIterations)
			{
				((t_multi*)param)->z_re2 = ((t_multi*)param)->z_re * ((t_multi*)param)->z_re;
				((t_multi*)param)->z_im2 = ((t_multi*)param)->z_im * ((t_multi*)param)->z_im;
				p = sqrt(ft_sq((((t_multi*)param)->z_re - (0.25))) + ((t_multi*)param)->z_im2);
				if (((t_multi*)param)->z_re2 + ((t_multi*)param)->z_im2 > 4 || ((t_multi*)param)->z_re < p - (2 * ft_sq(p) + 0.25))
				{
					is_inside = false;
					break;
				}
				((t_multi*)param)->z_im = (((t_multi*)param)->z_re + ((t_multi*)param)->z_re) * ((t_multi*)param)->z_im + ((t_multi*)param)->c_im;
				((t_multi*)param)->z_re = ((t_multi*)param)->z_re2 - ((t_multi*)param)->z_im2 + ((t_multi*)param)->c_re;
				((t_multi*)param)->n++;
			}
			if (is_inside)
				continue ;
			else
				ft_fill_pixel(((t_multi*)param)->img, ((t_multi*)param)->x, ((t_multi*)param)->y, ft_palette_tree(((t_multi*)param)->n, ((t_multi*)param)->MaxIterations, ((t_multi*)param)->palette));
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
