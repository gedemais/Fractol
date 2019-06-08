/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 18:39:36 by gedemais          #+#    #+#             */
/*   Updated: 2019/06/08 12:36:25 by gedemais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	ft_arrows(void *param, int key, double scale)
{
	if (key == 123)
	{
		((t_mlx*)param)->draw.MinRe += 0.01 * scale;
		((t_mlx*)param)->draw.MaxRe += 0.01 * scale;
	}
	else if (key == 124)
	{
		((t_mlx*)param)->draw.MinRe -= 0.01 * scale;
		((t_mlx*)param)->draw.MaxRe -= 0.01 * scale;
	}
	if (key == 125)
		((t_mlx*)param)->draw.MinIm += 0.01 * scale;
	else if (key == 126)
		((t_mlx*)param)->draw.MinIm -= 0.01 * scale;
	ft_memset(((t_mlx*)param)->img_data, 0, HGT * WDT * 4);
}

void	ft_place_bounds(void *param, int mask)
{
	if (mask == MANDELBROT)
	{
		((t_mlx*)param)->draw.MaxRe = 1.910770;
		((t_mlx*)param)->draw.MaxIm = 1.146398;
		((t_mlx*)param)->draw.MinRe = -2.152622;
		((t_mlx*)param)->draw.MinIm = -1.139259;
	}
	else if (mask == JULIA)
	{
		((t_mlx*)param)->draw.MinRe = -2.008659;
		((t_mlx*)param)->draw.MaxRe = 1.928331;
		((t_mlx*)param)->draw.MaxIm = 1.146398;
		((t_mlx*)param)->draw.MinIm = -1.080204;
	}
	else if (mask == BURNINGSHIP)
	{
		((t_mlx*)param)->draw.MaxRe = 1.910770;
		((t_mlx*)param)->draw.MaxIm = 1.146398;
		((t_mlx*)param)->draw.MinRe = -2.152622;
		((t_mlx*)param)->draw.MinIm = -1.139259;
	}
}

int		ft_switch_fractal(void *param, int mask)
{
	if (mask == MANDELBROT)
		mask = JULIA;
	else if (mask == JULIA)
		mask = BURNINGSHIP;
	else if (mask == BURNINGSHIP)
		mask = MANDELBROT;
	else
		return (0);
	ft_place_bounds(param, mask);
	ft_memset(((t_mlx*)param)->img_data, 0, HGT * WDT * 4);
	return (mask);
}

int		ft_keys_tree(void *param, int key)
{
	t_mlx			*s;

	s = ((t_mlx*)param);
	if (key == 123 || key == 124 || key == 125 || key == 126)
		ft_arrows(param, key, s->draw.scale);
	else if (key == 53)
		ft_exit();
	else if (key == 34)
		s->draw.MaxIterations++;
	else if (key == 8)
		*ft_palette() = (*ft_palette() < NB_PALETTES) ? *ft_palette() + 1 : 0;
	else if (key == 4)
		s->hud = (s->hud == false) ? true : false;
	else if (key == 0)
		s->automatic = (s->automatic == false) ? true : false;
	else if (key == 35)
	{
		s->psychedelic = (s->psychedelic == false) ? true : false;
		s->draw.psychedelic = s->psychedelic;
	}
	else if (key == 49)
		s->draw.mask = ft_switch_fractal(param, s->draw.mask);
	else
		return (0);
	return (1);
}

int		ft_deal_key(int key, void *param)
{
	t_mlx			*s;
	clock_t			t;
	double 			time;
	static int		palette = 0;

	s = ((t_mlx*)param);
	if (ft_keys_tree(param, key) == 0)
		return (1);
	t = clock();
	ft_memset(s->img_data, 0, HGT * WDT * 4);
	s->img_data = ft_mandelbrot(s->img_data, *ft_palette(), &s->draw);
	mlx_put_image_to_window(s, s->mlx_win, s->img_ptr, 0, 0);
	t = clock() - t; 
	time = ((double)t) / CLOCKS_PER_SEC;
	if (s->hud == true)
		ft_hud(param, time, s->draw.MaxIterations);
	s->draw.scale = (s->draw.MaxRe - s->draw.MinRe) * (double)((double)s->draw.MaxIterations / 80);
	return (1);
}
