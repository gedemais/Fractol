/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 16:59:52 by gedemais          #+#    #+#             */
/*   Updated: 2019/06/08 15:59:58 by gedemais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void		ft_print_fps(t_mlx *s, double time)
{
	char	*tim;

	if (!(tim = ft_itoa((int)(1 / time) * 2)))
		return ;
	mlx_string_put(s->mlx_ptr, s->mlx_win, 10, 10, 0xFFFFFF, "FPS : ");
	mlx_string_put(s->mlx_ptr, s->mlx_win, 65, 10, 0xFFFFFF, tim);
	ft_strdel(&tim);
}

void		ft_print_iterations(t_mlx *s, int iterations)
{
	char	*iter;

	if (!(iter = ft_itoa(iterations)))
		return ;
	mlx_string_put(s->mlx_ptr, s->mlx_win, 10, 30, 0xFFFFFF, "Iterations : ");
	mlx_string_put(s->mlx_ptr, s->mlx_win, 140, 30, 0xFFFFFF, iter);
	ft_strdel(&iter);
}

void		ft_hud(void *param, double time, int iterations)
{
	t_mlx	*s;

	s = ((t_mlx*)param);
	if (!param)
		return ;
	ft_print_fps(param, time);
	ft_print_iterations(param, iterations);
	mlx_string_put(s->mlx_ptr, s->mlx_win, 10, 50, 0xFFFFFF,
			"Switch colors : c");
	mlx_string_put(s->mlx_ptr, s->mlx_win, 10, 70, 0xFFFFFF,
			"HUD On / Off : h");
	mlx_string_put(s->mlx_ptr, s->mlx_win, 10, 90, 0xFFFFFF,
			"Automatic mode : a");
	mlx_string_put(s->mlx_ptr, s->mlx_win, 10, 110, 0xFFFFFF,
			"Psychedelic mode : p");
	mlx_string_put(s->mlx_ptr, s->mlx_win, 10, 130, 0xFFFFFF,
			"Switch fractals : Space");
	mlx_string_put(s->mlx_ptr, s->mlx_win, 10, 150, 0xFFFFFF,
			"Switch GPU / CPU : g");
}
