/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   press.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 18:50:26 by gedemais          #+#    #+#             */
/*   Updated: 2019/06/04 19:08:19 by gedemais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	ft_zoom(void *param, double ratio_x, double ratio_y)
{
	t_mlx			*s;

	s = ((t_mlx*)param);
	s->draw.MinRe += (ratio_x / 10) * s->draw.scale;
	s->draw.MaxRe -= ((1 - ratio_x) / 10) * s->draw.scale;
	s->draw.MinIm += ((1 - ratio_y) / 10) * s->draw.scale;
	s->draw.MaxIm -= (ratio_y / 10) * s->draw.scale;
	if (s->automatic)
		s->draw.MaxIterations++;
}

void	ft_dezoom(void *param, double ratio_x, double ratio_y)
{
	t_mlx			*s; 
	
	s = ((t_mlx*)param);
	s->draw.MinRe -= ratio_x / 10 * s->draw.scale;
	s->draw.MaxRe += (1 - ratio_x) / 10 * s->draw.scale;
	s->draw.MinIm -= (1 - ratio_y) / 10 * s->draw.scale;
	s->draw.MaxIm += ratio_y / 10 * s->draw.scale;
	if (s->automatic)
		s->draw.MaxIterations--;
}

int 	ft_pos(int x, int y, void *param)
{
	t_mlx	*s;
	clock_t	t;
	double	time;

	s = ((t_mlx*)param);
	if (s->julia_m == false)
		return (1);
	t = clock();
	*julia_x() = (x - WDT) / (double)WDT;
	*julia_y() = (y - HGT) / (double)HGT;
	ft_memset(((t_mlx*)param)->img_data, 0, HGT * WDT * 4);
	((t_mlx*)param)->img_data = ft_mandelbrot(((t_mlx*)param)->img_data, *ft_palette(), &((t_mlx*)param)->draw);
	mlx_put_image_to_window((t_mlx*)param, ((t_mlx*)param)->mlx_win, ((t_mlx*)param)->img_ptr, 0, 0);
	t = clock() - t; 
	time = ((double)t) / CLOCKS_PER_SEC;
	if (s->hud)
		ft_hud(param, time, s->draw.MaxIterations);
	return (1);
}

int 	ft_press(int button, int x, int y, void *param)
{
	t_mlx			*s;
	clock_t 		t;
	double 			time;
	double			ratio_x;
	double			ratio_y;

	s = ((t_mlx*)param);
	ratio_x = (double)((double)x / WDT);
	ratio_y = (double)((double)y / HGT);
	if ((button == 1 || button == 4) && s->draw.MaxIterations > 10)
		ft_zoom(param, ratio_x, ratio_y);
	else if (button == 2)
		s->julia_m = (s->julia_m) ? false : true;
	else if (button == 5)
		ft_dezoom(param, ratio_x, ratio_y);
	t = clock(); 
	ft_memset(((t_mlx*)param)->img_data, 0, HGT * WDT * 4);
	s->img_data = ft_mandelbrot(s->img_data, *ft_palette(), &s->draw);
	mlx_put_image_to_window((t_mlx*)param, s->mlx_win, s->img_ptr, 0, 0);
	t = clock() - t;
	time = ((double)t) / CLOCKS_PER_SEC;
	if (s->hud)
		ft_hud(param, time, s->draw.MaxIterations);
	s->draw.scale = (s->draw.MaxRe - s->draw.MinRe) * (double)((double)s->draw.MaxIterations / 80);
	return (1);
}
