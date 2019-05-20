/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 18:43:03 by gedemais          #+#    #+#             */
/*   Updated: 2019/05/20 21:42:48 by gedemais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include "stdio.h"

char	*ft_clear_image(void *param)
{
	ft_memset(((t_mlx*)param)->img_data, 0, HGT * WDT * 4);
	mlx_put_image_to_window((t_mlx*)param, ((t_mlx*)param)->mlx_win, ((t_mlx*)param)->img_ptr, 0, 0);
	return (((t_mlx*)param)->img_data);
}

void	ft_arrows(void *param, int key)
{
	if (key == 123)
		((t_mlx*)param)->draw.MinRe -= 0.1;
	else if (key == 124)
		((t_mlx*)param)->draw.MinRe += 0.1;
//	else if (key == 125)
//	else if (key == 126)
}

int		ft_deal_key(int key, void *param)
{
	static int	x = 100;

	x++;
	(void)key;
	if (key == 69)
		((t_mlx*)param)->zoom -= 0.1;
	else if (key == 78)
		((t_mlx*)param)->zoom += 0.1;
	else if (key == 123 || key == 124 || key == 125 || key == 126)
		ft_arrows(param, key);
	((t_mlx*)param)->img_data = ft_clear_image(param);
	((t_mlx*)param)->img_data = ft_mandelbrot(((t_mlx*)param)->img_data, ((t_mlx*)param)->zoom, &((t_mlx*)param)->draw);
	mlx_put_image_to_window((t_mlx*)param, ((t_mlx*)param)->mlx_win, ((t_mlx*)param)->img_ptr, 0, 0);
	return (1);
}

int		ft_fractol(char *name)
{
	t_mlx	env;
	int		mask;

	if (!(env.mlx_ptr = mlx_init()))
		return (-1);
	if (!(env.mlx_win = mlx_new_window(env.mlx_ptr, WDT, HGT, "Fractol du sale")))
		return (-1);
	if ((mask = ft_name_tree(name)) == -1)
		return (-1);
	if (!(env.img_ptr = mlx_new_image(env.mlx_ptr, WDT, HGT)))
		return (-1);
	if (!(env.img_data = mlx_get_data_addr(env.img_ptr, &env.bpp,
				&env.s_l, &env.endian)))
		return (-1);
	env.zoom = 1;
	env.draw.MinRe = -1.5;
	env.draw.MinIm = -1.1;
	mlx_put_image_to_window(&env, env.mlx_win, env.img_ptr, 0, 0);
	mlx_hook(env.mlx_win, KEY_PRESS, KEY_PRESS_MASK, ft_deal_key, &env);
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
