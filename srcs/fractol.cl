#include "../includes/fractol.h"

__kernel void fractol(__global char *img, int maxiterations, __global char * result)
{
	unsigned int	id;

	id =  get_global_id(0);
	
}
