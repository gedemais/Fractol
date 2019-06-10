/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 18:50:23 by gedemais          #+#    #+#             */
/*   Updated: 2019/06/08 20:53:22 by gedemais         ###   ########.fr       */
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

# define HGT 672
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
# include "/System/Library/Frameworks/OpenCL.framework/Versions/A/Headers/cl.h"
# include <stdbool.h>
# include <pthread.h>
# include <stdio.h>
# include <dirent.h>
# include <sys/types.h>

typedef struct			s_complex
{
	double	im;
	double	re;
}				t_complex;

typedef struct			s_opencl
{
	cl_device_id		device;
	cl_context			context;
	cl_command_queue	queue;
	cl_program			program;
	cl_kernel			kernel;
	cl_mem				buffer;
}						t_opencl;

typedef struct	s_multi
{
	pthread_t	thread;
	int			index;
	char		*img;
	double		maxre;
	double		minre;
	double		maxim;
	double		minim;
	double		c_im;
	double		c_re;
	double		z_re;
	double		z_re2;
	double		z_im;
	double		z_im2;
	double		re_factor;
	double		im_factor;
	unsigned	maxiterations;
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
	float		maxre;
	float		minre;
	float		maxim;
	float		minim;
	float		c_im;
	float		c_re;
	float		z_re;
	float		z_re2;
	float		z_im;
	float		z_im2;
	float		re_factor;
	float		im_factor;
	unsigned	maxiterations;
	int		n;
	int		x;
	int		y;
	float		scale;
	int	palette;
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
	bool		julia_m;
	t_fract		draw;
	t_opencl	s;
}				t_mlx;

int				ft_name_tree(char *name);
void			ft_fill_pixel(char *img_str, int x, int y, int color);
char			*ft_mandelbrot(char *img, int palette, t_fract *draw);

void			ft_hud(void *param, double time, int iterations);

int				ft_palette_one(int n, int max, bool psychedelic);
int				ft_palette_two(int n, int max, bool psychedelic);
int				ft_palette_three(int n, int max, bool psychedelic);
int				ft_palette_four(int n, int max, bool psychedelic);
int				ft_palette_five(int n, int max, bool psychedelic);

void			ft_place_bounds(void *param, int mask);
char			*ft_clear_image(void *param, char *img_data);

int				ft_exit(void);
double			ft_sq(double nb);
int				ft_palette_tree(int n, int max, int palette, bool psychedelic);
double			ft_fractals_tree(void *param, char w);
int				ft_deal_key(int key, void *param);

int				ft_press(int button, int x, int y, void *param);
int				ft_pos(int x, int y, void *param);

double			*julia_x(void);
double			*julia_y(void);
int			*gpu(void);
int			ft_screen_size(void);

int				ft_init_opencl(t_opencl *s, char *img);
char				*ft_run_kernel(t_mlx *env, t_opencl *s, char *img);

#endif
