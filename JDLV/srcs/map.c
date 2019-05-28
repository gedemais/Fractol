#include "../includes/jdlv.h"
#include "stdio.h"

int		ft_init_map(t_mlx *env, int size)
{
	int		i;

	i = 0;
	if (!(env->map = (bool**)malloc(sizeof(bool*) * size)))
		return (-1);
	if (!(env->tmp = (bool**)malloc(sizeof(bool*) * size)))
		return (-1);
	while (i < size)
	{
		if (!(env->map[i] = (bool*)malloc(sizeof(bool) * size)))
			return (-1);
		if (!(env->tmp[i] = (bool*)malloc(sizeof(bool) * size)))
			return (-1);
		ft_memset(env->map[i], false, sizeof(bool) * size);
		ft_memset(env->tmp[i], false, sizeof(bool) * size);
		i++;
	}
	return (0);
}

bool	**ft_cpy_map(bool **dest, bool **src, int size)
{
	int		i;
	int		j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			dest[i][j] = src[i][j];
			j++;
		}
		i++;
	}
	return (dest);
}

int		ft_count_neighbours(bool **map, int i, int j, int size)
{
	int		ret;

	ret = 0;
	if (i > 0 && map[i - 1][j])
		ret++;
	if (i < size - 1 && map[i + 1][j])
		ret++;
	if (j > 0 && map[i][j - 1])
		ret++;
	if (j < size - 1 && map[i][j + 1])
		ret++;
	if (i > 0 && j > 0 && map[i - 1][j - 1])
		ret++;
	if (i > 0 && j < size - 1 && map[i - 1][j + 1])
		ret++;
	if (i < size - 1 && j > 0 && map[i + 1][j - 1])
		ret++;
	if (i < size - 1 && j < size - 1 && map[i + 1][j + 1])
		ret++;
	return (ret);
}

void	*ft_process(void *param)
{
	int		i = 0;
	int		j;
	int		neighbours;

	((t_mlx*)param)->tmp = ft_cpy_map(((t_mlx*)param)->tmp, ((t_mlx*)param)->map, ((t_mlx*)param)->size);
	if (neighbours > 0)
		printf("%d\n", neighbours);
	while (i < ((t_mlx*)param)->size)
	{
		j = 0;
		while (j < ((t_mlx*)param)->size)
		{
//			neighbours = ft_count_neighbours(((t_mlx*)param)->tmp, i, j, ((t_mlx*)param)->size);
			if (neighbours == 3)
				((t_mlx*)param)->map[i][j] = true;
			else if (neighbours == 2)
				continue ;
			else if (neighbours < 2 || neighbours > 3)
				((t_mlx*)param)->map[i][j] = false;
			j++;
		}
		i++;
	}
	return (param);
}
