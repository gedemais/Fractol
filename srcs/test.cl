
__kernel void	ft_test(__global char *buff)
{
	int	x = get_global_id(1);
	int	y = get_global_id(0);
	int	pos = ((y - 1) * 1080 + x) * 4;

	if (x > 100 && x < 200 && y > 100 && y < 200)
	{
		buff[pos] = 55;
		buff[pos + 1] = 55;
		buff[pos + 2] = 55;
	}
}
