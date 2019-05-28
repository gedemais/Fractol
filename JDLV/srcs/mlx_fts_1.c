/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_fts_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 14:44:56 by gedemais          #+#    #+#             */
/*   Updated: 2019/05/28 18:10:09 by gedemais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/jdlv.h"

int		*ft_wdt(void)
{
	static int	wdt = 0;

	return (&wdt);
}

int		*ft_hgt(void)
{
	static int	hgt = 0;

	return (&hgt);
}

void	ft_fill_pixel(char *img_str, int x, int y, int color)
{
	int		pos;

	if (x >= *ft_wdt() || x < 0 || y >= *ft_hgt() || y < 0)
		return ;
	pos = ((y - 1) * *ft_wdt() + x) * 4;
	img_str[pos] = color >> 16 & 255;
	img_str[pos + 1] = color >> 8 & 255;
	img_str[pos + 2] = color & 255;
}
