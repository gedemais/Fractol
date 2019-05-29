#include "../includes/jdlv.h"
#include "stdio.h"

int	ft_exit(void)
{
	exit(EXIT_SUCCESS);
}

int		*ft_palette(void)
{
	static int	val = 0;

	return (&val);
}
/*
void	*ft_add_cell(void *param, int x, int y)
{
	int	i = x / 
}

int     ft_press(int button, int x, int y, void *param)
{
	if (button == 1)
		param = ft_add_cell(param, x, y);
//	else if (button == 2)
//		param = ft_kill_cell(param, x, y);
	return (1);
}*/

int		ft_deal_key(int key, void *param)
{
	static int	gen = 0;
	char		*generation;

	if (key == 53)
		ft_exit();
	param = ft_process(param);
	((t_mlx*)param)->img_data = ft_print_image(param);
	mlx_put_image_to_window((t_mlx*)param, ((t_mlx*)param)->mlx_win, ((t_mlx*)param)->img_ptr, 0, 0);
	mlx_string_put(((t_mlx*)param)->mlx_ptr, ((t_mlx*)param)->mlx_win, 10, 10, 0, "Generation");
	mlx_string_put(((t_mlx*)param)->mlx_ptr, ((t_mlx*)param)->mlx_win, 120, 10, 0, (generation = ft_itoa(gen)));
	ft_strdel(&generation);
	gen++;
	return (1);
}

void		ft_set_rand(void *param)
{
	int	i = 0;

	while (i < ((t_mlx*)param)->wdt * 10)
	{
		((t_mlx*)param)->map[rand() % ((t_mlx*)param)->size][rand() % ((t_mlx*)param)->size] = true;
		i++;
	}
}

int		ft_jdlv(int size, int hgt, int wdt)
{
	t_mlx	env;
	int		mask;

	if (size < 1 || hgt != wdt || hgt < 10)
	{
		ft_putstr_fd("Wrong Argument\n", 2);
		return (-1);
	}
	if (!(env.mlx_ptr = mlx_init()))
		return (-1);
	if (!(env.mlx_win = mlx_new_window(env.mlx_ptr, wdt, hgt, "Game of Life")))
		return (-1);
	if (!(env.img_ptr = mlx_new_image(env.mlx_ptr, wdt, hgt)))
		return (-1);
	if (!(env.img_data = mlx_get_data_addr(env.img_ptr, &env.bpp,
					&env.s_l, &env.endian)))
		return (-1);
	if (ft_init_map(&env, size) == -1)
		return (-1);
	env.size = size;
	env.hgt = hgt;
	env.wdt = wdt;
	*ft_hgt() = hgt;
	*ft_wdt() = wdt;

	ft_set_rand((void*)&env);
/*	env.map[20][120] = true;

	env.map[20][122] = true;
	env.map[21][122] = true;

	env.map[22][124] = true;
	env.map[23][124] = true;
	env.map[24][124] = true;

	env.map[23][126] = true;
	env.map[24][126] = true;
	env.map[24][127] = true;
	env.map[25][126] = true;*/
	env.img_data = ft_print_image((void*)&env);
	mlx_put_image_to_window(&env, env.mlx_win, env.img_ptr, 0, 0);
	mlx_hook(env.mlx_win, KEY_PRESS, KEY_PRESS_MASK, ft_deal_key, &env);
//	mlx_hook(env.mlx_win, 4, (1L<<2), ft_press, &env);
	mlx_hook(env.mlx_win, 17, 1L << 17, ft_exit, &env);
	mlx_loop(env.mlx_ptr);
	return (0);
}

int		main(int argc, char **argv)
{
	if (argc != 4)
	{
		ft_putstr_fd("Usage : ./jdlv [map size] [window_x_size] [window_y_size]\n", 2);
		return (1);
	}
	else if (ft_jdlv(ft_atoi(argv[1]), ft_atoi(argv[2]), ft_atoi(argv[3])) == -1)
		return (1);
	return (0);
}
