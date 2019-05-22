/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 18:50:23 by gedemais          #+#    #+#             */
/*   Updated: 2019/05/20 21:37:30 by gedemais         ###   ########.fr       */
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

# define HGT 720
# define WDT 1280
# define KEY_PRESS 2
# define KEY_PRESS_MASK (1L<<0)
# define ITER_BASE 10

# define MANDELBROT 2

# include "../libft/libft.h"
# include "mlx.h"
# include <stdbool.h>
# include <pthread.h>

typedef struct	s_fract
{
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
	float		zoom;
	t_fract		draw;
}				t_mlx;

int		ft_name_tree(char *name);
void	ft_fill_pixel(char *img_str, int x, int y, int color);
char	*ft_mandelbrot(char *img, double MaxRe, t_fract *draw);

#endif
