/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 16:59:52 by gedemais          #+#    #+#             */
/*   Updated: 2019/05/29 13:37:35 by gedemais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void		ft_hud(void *param, double time, int iterations)
{
	mlx_string_put(((t_mlx*)param)->mlx_ptr, ((t_mlx*)param)->mlx_win, 10, 10, 0xFFFFFF, "FPS : ");
	mlx_string_put(((t_mlx*)param)->mlx_ptr, ((t_mlx*)param)->mlx_win, 65, 10, 0xFFFFFF, ft_itoa((double)(1 / time)));
	mlx_string_put(((t_mlx*)param)->mlx_ptr, ((t_mlx*)param)->mlx_win, 10, 30, 0xFFFFFF, "Iterations : ");
	mlx_string_put(((t_mlx*)param)->mlx_ptr, ((t_mlx*)param)->mlx_win, 140, 30, 0xFFFFFF, ft_itoa(iterations));
	mlx_string_put(((t_mlx*)param)->mlx_ptr, ((t_mlx*)param)->mlx_win, 10, 50, 0xFFFFFF, "Switch colors : c");
	mlx_string_put(((t_mlx*)param)->mlx_ptr, ((t_mlx*)param)->mlx_win, 10, 70, 0xFFFFFF, "HUD On / Off : h");
	mlx_string_put(((t_mlx*)param)->mlx_ptr, ((t_mlx*)param)->mlx_win, 10, 90, 0xFFFFFF, "Automatic mode : a");
	mlx_string_put(((t_mlx*)param)->mlx_ptr, ((t_mlx*)param)->mlx_win, 10, 110, 0xFFFFFF, "Psychedelic mode : p");
	mlx_string_put(((t_mlx*)param)->mlx_ptr, ((t_mlx*)param)->mlx_win, 10, 130, 0xFFFFFF, "Switch fractals : Space");
}
