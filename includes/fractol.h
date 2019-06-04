/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 18:50:23 by gedemais          #+#    #+#             */
/*   Updated: 2019/06/04 18:50:54 by gedemais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define PUT ft_putstr("There\n");
# define PUT1 ft_putstr("There\n");
# define PUT2 ft_putstr("There\n");
# define PUT3 ft_putstr("There\n");
# define PUT4 ft_putstr("There\n");
# define PUT5 ft_putstr("There\n");
# define PUT6 ft_putstr("There\n");
# define PUT7 ft_putstr("There\n");
# define PUT8 ft_putstr("There\n");
# define PUT9 ft_putstr("There\n");

# define HGT 600
# define WDT 1080
# define KEY_PRESS 2
# define KEY_PRESS_MASK (1L<<0)
# define ITER_BASE 30
# define BUFF_READ 8192

# define MANDELBROT 2
# define JULIA 4
# define BURNINGSHIP 8

# define NB_PALETTES 4

# define NB_THREADS 8

# include "../libft/libft.h"
# include "mlx.h"
# include <stdbool.h>
# include <pthread.h>
# include <stdio.h>
# include <dirent.h>
#include "/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/System/Library/Frameworks/OpenCL.framework/Versions/A/Headers/cl.h"
# include <sys/types.h>

typedef struct		s_multiclear
{
	pthread_t		thread;
	char			*img;
	int				pos;
	int				len;
}					t_multiclear;

typedef struct		s_opencl
{
	cl_device_id		device;
	cl_context			context;
	cl_command_queue	queue;
	cl_program			program;
	cl_kernel			kernel;
	cl_mem				buffer;
	char				**sources;
	int					index;
}					t_opencl;

typedef struct		s_kernel
{
	DIR				*d;
	struct dirent	*dir;
	char			*f_path;
	int				len;
	int				fd;
	int				i;
}					t_kernel;

typedef struct	s_multi
{
	pthread_t	thread;
	int			index;
	char		*img;
	double		MaxRe;
	double		MinRe;
	double 		MaxIm;
	double		MinIm;
	double 		c_im;
	double 		c_re;
	double 		z_re;
	double 		z_re2;
	double 		z_im;
	double 		z_im2;
	double 		Re_factor;
	double 		Im_factor;
	unsigned 	MaxIterations;
	int			n;
	int			x;
	int			y;
	float		scale;
	int			palette;
	bool		psychedelic;
	int			mask;
}				t_multi;

typedef struct	s_fract
{
	double		MaxRe;
	double		MinRe;
	double 		MaxIm;
	double		MinIm;
	double 		c_im;
	double 		c_re;
	double 		z_re;
	double 		z_re2;
	double 		z_im;
	double 		z_im2;
	double 		Re_factor;
	double 		Im_factor;
	unsigned 	MaxIterations;
	int			n;
	int			x;
	int			y;
	float		scale;
	bool		psychedelic;
	int			mask;
}				t_fract;

typedef struct	s_mlx
{

	void		*mlx_ptr;
	void		*mlx_win;
	void		*img_ptr;
	char		*img_data;
	int			bpp;
	int			s_l;
	int			endian;
	bool		hud;
	bool		automatic;
	bool		psychedelic;
	t_fract		draw;
}				t_mlx;

int		ft_name_tree(char *name);
void	ft_fill_pixel(char *img_str, int x, int y, int color);
char	*ft_mandelbrot(char *img, int palette, t_fract *draw);

void	ft_hud(void *param, double time, int iterations);


int		ft_palette_one(int n, int max, bool psychedelic);
int		ft_palette_two(int n, int max, bool psychedelic);
int		ft_palette_three(int n, int max, bool psychedelic);
int		ft_palette_four(int n, int max, bool psychedelic);
int		ft_palette_five(int n, int max, bool psychedelic);

int		ft_count_files(char *path);
char	**ft_load_kernels(char *path);

int	ft_exit(void);
double	ft_sq(double nb);
int		ft_palette_tree(int n, int max, int palette, bool psychedelic);
double	ft_fractals_tree(void *param, char w);
int		ft_deal_key(int key, void *param);

int 	ft_press(int button, int x, int y, void *param);

double	*julia_x(void);
double	*julia_y(void);
int		*ft_palette(void);
#endif
