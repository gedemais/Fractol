/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 18:50:23 by gedemais          #+#    #+#             */
/*   Updated: 2019/05/28 14:03:07 by gedemais         ###   ########.fr       */
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

# define HGT 1080
# define WDT 1920
# define KEY_PRESS 2
# define KEY_PRESS_MASK (1L<<0)
# define ITER_BASE 50

# define MANDELBROT 2
# define NB_PALETTES 4

# define NB_THREADS 8

# include "../libft/libft.h"
# include "mlx.h"
# include <stdbool.h>
# include <pthread.h>

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
	t_fract		draw;
}				t_mlx;

int		ft_name_tree(char *name);
void	ft_fill_pixel(char *img_str, int x, int y, int color);
char	*ft_mandelbrot(char *img, int palette, t_fract *draw);

void	ft_hud(void *param, double time, int iterations);

int		ft_palette_one(int n, int max);
int		ft_palette_two(int n, int max);
int		ft_palette_three(int n, int max);
int		ft_palette_four(int n, int max);
int		ft_palette_five(int n, int max);

#endif
