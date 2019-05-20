/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 19:17:04 by gedemais          #+#    #+#             */
/*   Updated: 2019/05/20 21:37:49 by gedemais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/fractol.h"

char	*ft_mandelbrot(char *img, double MaxRe, t_fract *draw)
{
	draw->MaxIm = draw->MinIm+(MaxRe-draw->MinRe)*HGT/WDT;
	draw->Re_factor = (MaxRe-draw->MinRe)/(WDT-1);
	draw->Im_factor = (draw->MaxIm-draw->MinIm)/(HGT-1);
	draw->MaxIterations = 30;

	for(unsigned y=0; y < HGT; ++y)
	{
		draw->c_im = draw->MaxIm - y*draw->Im_factor;
		for(unsigned x=0; x<WDT; ++x)
		{
			draw->c_re = draw->MinRe + x*draw->Re_factor;
			draw->z_re = draw->c_re, draw->z_im = draw->c_im;
			bool isInside = true;
			for(unsigned n=0; n<draw->MaxIterations; ++n)
			{

				draw->z_re2 = draw->z_re*draw->z_re, draw->z_im2 = draw->z_im*draw->z_im;
				if(draw->z_re2 + draw->z_im2 > 4)
				{
					isInside = false;
					break;
				}
				draw->z_im = 2*draw->z_re*draw->z_im + draw->c_im;
				draw->z_re = draw->z_re2 - draw->z_im2 + draw->c_re;
			}
			if (isInside)
				ft_fill_pixel(img, x, y, 0xFFFFFF);
		}
	}
	return (img);
}
