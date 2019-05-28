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

int		ft_deal_key(int key, void *param)
{
	if (key == 53)
		ft_exit();
	((t_mlx*)param)->img_data = ft_clear_image(param);
	param = ft_process(param);
	((t_mlx*)param)->img_data = ft_print_image(param);
	mlx_put_image_to_window((t_mlx*)param, ((t_mlx*)param)->mlx_win, ((t_mlx*)param)->img_ptr, 0, 0);
	return (1);
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

	env.map[0][0] = true;
	env.map[0][1] = true;
	env.map[0][2] = true;
	env.map[0][3] = true;
	env.map[0][4] = true;
	env.map[0][5] = true;

	env.img_data = ft_print_image((void*)&env);
	mlx_put_image_to_window(&env, env.mlx_win, env.img_ptr, 0, 0);
	mlx_hook(env.mlx_win, KEY_PRESS, KEY_PRESS_MASK, ft_deal_key, &env);
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
