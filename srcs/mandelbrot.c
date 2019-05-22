/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 19:17:04 by gedemais          #+#    #+#             */
/*   Updated: 2019/05/22 20:53:50 by gedemais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/fractol.h"

int		ft_color_tree(int n, int max)
{
	int		tab[16];

	tab[0] = 0xFF0000;
	tab[1] = 0x00FF00;
	tab[2] = 0x0000FF;
	tab[3] = 0xFF17EA;
	tab[4] = 0xbf2f0c;
	tab[5] = 0x008539;
	tab[6] = 0x66FFFF;
	tab[7] = 0XFF33FF;
	tab[8] = 0x7F00FF;
	tab[9] = 0xFF8000;
	tab[10] = 0XFFFF33;
	tab[11] = 0x0080FF;
	tab[12] = 0x00FF80;
	tab[13] = 0xFFCCE5;
	tab[14] = 0xFF3399;
	tab[15] = 0x9999FF;
	if (n == max)
		return (0);
	return (tab[n % 16]);
}


char	*ft_mandelbrot(char *img, float left, float top, float xside, float yside) 
{ 
    float xscale, yscale, zx, zy, cx, tempx, cy; 
    int x, y, i, j; 
    int maxx, maxy, count; 
  
    maxx = WDT; 
    maxy = getmaxy(HGT); 
  
    xscale = xside / maxx; 
    yscale = yside / maxy; 
  
    // scanning every point in that rectangular area. 
    // Each point represents a Complex number (x + yi). 
    // Iterate that complex number 
    for (y = 1; y <= maxy - 1; y++) { 
        for (x = 1; x <= maxx - 1; x++) 
        { 
            // c_real 
            cx = x * xscale + left; 
  
            // c_imaginary 
            cy = y * yscale + top; 
  
            // z_real 
            zx = 0; 
  
            // z_imaginary 
            zy = 0; 
            count = 0; 
  
            // Calculate whether c(c_real + c_imaginary) belongs 
            // to the Mandelbrot set or not and draw a pixel 
            // at coordinates (x, y) accordingly 
            // If you reach the Maximum number of iterations 
            // and If the distance from the origin is 
            // greater than 2 exit the loop 
            while ((zx * zx + zy * zy < 4) && (count < MAXCOUNT)) 
            { 
                // Calculate Mandelbrot function 
                // z = z*z + c where z is a complex number 
  
                // tempx = z_real*_real - z_imaginary*z_imaginary + c_real 
                tempx = zx * zx - zy * zy + cx; 
  
                // 2*z_real*z_imaginary + c_imaginary 
                zy = 2 * zx * zy + cy; 
  
                // Updating z_real = tempx 
                zx = tempx; 
  
                // Increment count 
                count = count + 1; 
            } 
  
            // To display the created fractal 
            ft_fill_pixel(img, x, y, ft_color_tree(n, ));
        } 
    } 
} 
