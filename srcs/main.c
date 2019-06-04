/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 18:43:03 by gedemais          #+#    #+#             */
/*   Updated: 2019/06/04 18:53:52 by gedemais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include "stdio.h"

void	ft_set_env(t_mlx *env)
{
	
}

int		ft_fractol(char *name)
{
	t_mlx	env;
	int		mask;

	if ((env.draw.mask = ft_name_tree(name)) == -1)
		return (-1);
	if (!(env.mlx_ptr = mlx_init()))
		return (-1);
	if (!(env.mlx_win = mlx_new_window(env.mlx_ptr, WDT, HGT, "Fractol du sale")))
		return (-1);
	if (!(env.img_ptr = mlx_new_image(env.mlx_ptr, WDT, HGT)))
		return (-1);
	if (!(env.img_data = mlx_get_data_addr(env.img_ptr, &env.bpp,
					&env.s_l, &env.endian)))
		return (-1);
	env.draw.scale = 1;
	env.hud = true;
	env.automatic = false;
	env.psychedelic = false;
	env.draw.MaxIterations = ITER_BASE;
	env.draw.MaxRe = 1.910770;
	env.draw.MaxIm = 1.146398;
	env.draw.MinRe = -2.152622;
	env.draw.MinIm = -1.139259;
	env.img_data = ft_mandelbrot(env.img_data, *ft_palette(), &(env.draw));
	mlx_put_image_to_window(&env, env.mlx_win, env.img_ptr, 0, 0);
	mlx_hook(env.mlx_win, KEY_PRESS, KEY_PRESS_MASK, ft_deal_key, &env);
	mlx_hook(env.mlx_win, 4, (1L<<2), ft_press, &env);
//	mlx_hook(env.mlx_win, 6, 0, ft_pos, &env);
	mlx_hook(env.mlx_win, 17, 1L << 17, ft_exit, &env);
	mlx_loop(env.mlx_ptr);
	return (0);
}

int		main(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_putstr_fd("Usage : ./fractol [fractal name]\n", 2);
		return (1);
	}
	else if (ft_fractol(argv[1]) == -1)
	{
		ft_putstr_fd("Wrong fracatal name.\n", 2);
		return (1);
	}
	return (0);
}
