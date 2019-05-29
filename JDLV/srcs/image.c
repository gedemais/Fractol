#include "../includes/jdlv.h"

char	*ft_clear_image(void *param)
{
	ft_memset(((t_mlx*)param)->img_data, 0, ((t_mlx*)param)->hgt * ((t_mlx*)param)->wdt * 4);
	mlx_put_image_to_window((t_mlx*)param, ((t_mlx*)param)->mlx_win, ((t_mlx*)param)->img_ptr, 0, 0);
	return (((t_mlx*)param)->img_data);
}

char	*ft_draw_tale(void *param, int i, int j, int tale_size)
{
	int		k = 0;
	int		l;
	int		y = i * (tale_size + 1);
	int		x = j * (tale_size + 1);
	int		tx = x;

	while (k < tale_size)
	{
		l = 0;
		x = tx;
		while (l < tale_size)
		{
			ft_fill_pixel(((t_mlx*)param)->img_data, x, y, (((t_mlx*)param)->map[i][j]) ? 0 : 0xFFFFFF);
			x++;
			l++;
		}
		y++;
		k++;
	}
	return (((t_mlx*)param)->img_data);
}

char	*ft_print_image(void *param)
{
	int		tale_size = ((t_mlx*)param)->wdt / ((t_mlx*)param)->size;
	int		i = 0;
	int		j;

	while (i < ((t_mlx*)param)->size) // Loop iterating through every tales
	{
		j = -1;
		while (++j < ((t_mlx*)param)->size)
			((t_mlx*)param)->img_data = ft_draw_tale(param, i, j, tale_size);
		i++;
	}
	return (((t_mlx*)param)->img_data);
}
