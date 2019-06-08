#include "../includes/fractol.h"

char	*ft_read(int fd)
{
	char	buff[BUFF_READ + 1];
	char	*dest;
	int		ret;
	int		size;
	int		i;

	i = 0;
	size = 0;
	if (!(dest = ft_strnew(0)))
		return (NULL);
	while ((ret = read(fd, buff, BUFF_READ)) > 0)
	{

		size += ret;
		if (ret == -1 || !(dest = ft_strrealloc(dest, size)))
			return (NULL);
		buff[ret] = '\0';
		dest = ft_strcat(dest, buff);
		i++;
	}
	return (dest);
}

int		ft_init_opencl(t_opencl *s, char *img)
{
	char	*source;
	int		fd;

	if ((fd = open("fractol.cl", O_RDONLY)) == -1)
		return (-1);
	if (!(source = ft_read(fd)))
		return (-1);
	clGetDeviceIDs(NULL, CL_DEVICE_TYPE_GPU, 1, &(s->device), NULL); // Repere le GPU et obtient son ID
	s->context = clCreateContext(NULL, 1, &(s->device), NULL, NULL, NULL); // Cree un contexte de compilation / execution 
	s->queue = clCreateCommandQueue(s->context, s->device, 0, NULL); // Cree la queue de commande
	s->program = clCreateProgramWithSource(s->context, 1, (const char**)&source, NULL, NULL); // Cree le programme a partir du .cl
	clBuildProgram(s->program, 0, NULL, NULL, NULL, NULL); // Compile le programme
	s->kernel = clCreateKernel(s->program, "Fract'ol", NULL); // Cree le kernel a partir du programme
	s->buffer = clCreateBuffer(s->context, CL_MEM_READ_WRITE, ((HGT * WDT) * 4), NULL, NULL); // Cree un objet memoire dans le GPU
	clEnqueueWriteBuffer(s->queue, s->buffer, CL_FALSE, 0, ((HGT * WDT) * 4), img, 0, NULL, NULL);
	return (0);
}

char	*ft_run_kernel(t_opencl	*s, char *img)
{
	size_t	global_dimensions[] = {(HGT * WDT), 0, 0};
	clSetKernelArg(s->kernel, 0, sizeof(s->buffer), &(s->buffer));
	clEnqueueNDRangeKernel(s->queue, s->kernel, 1, NULL, global_dimensions, NULL, 0, NULL, NULL);
	clEnqueueReadBuffer(s->queue, s->buffer, CL_FALSE, 0, sizeof(char) * (HGT * WDT), img, 0, NULL, NULL);
	clFinish(s->queue);
	return (img);
}
