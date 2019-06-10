/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 12:15:16 by gedemais          #+#    #+#             */
/*   Updated: 2019/06/10 22:47:24 by gedemais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		ft_palette_one(int n, int max, bool p)
{
	static int		tab[10] = {0x00ff00,
							0x20dd20,
							0x40bb20,
							0x609020,
							0x906020,
							0xbb4020,
							0xff2020,
							0xff9020,
							0xffdd20,
							0xffff90};

	if (n == max)
		return (0);
	return (tab[(n + (p ? max : 0)) % 10]);
}

int		ft_palette_two(int n, int max, bool p)
{
	static int		tab[16] = {0x000000,
								0xffffff,
								0x050505,
								0xfefefe,
								0x101010,
								0xeeeeee,
								0x151515,
								0xdedede,
								0x202020,
								0xdddddd,
								0x252525,
								0xcdcdcd,
								0x303030,
								0xcccccc,
								0x353535,
								0xbcbcbc};

	if (n == max)
		return (0);
	return (tab[(n + (p ? max : 0)) % 16]);
}

int		ft_palette_three(int n, int max, bool p)
{
	static int		tab[12] = {0x0000ff,
								0x1020ff,
								0x2040ff,
								0x3060ff,
								0x4080ff,
								0x50aaff,
								0x60ccff,
								0x70eeff,
								0x80ffff,
								0xddffaa,
								0xeebb90,
								0xff8080};

	if (n == max)
		return (0);
	return (tab[(n + (p ? max : 0)) % 12]);
}

int		ft_palette_four(int n, int max, bool p)
{
	static int		tab[10] = {0xff0000, 0x00ff00, 0x0000ff, 0xffff00, 0xff00ff,
		0x00ffff, 0xffdd00, 0x00ffdd, 0xdd00ff, 0xc3f23f};

	if (n == max)
		return (0);
	return (tab[(n + (p ? max : 0)) % 10]);
}

int		ft_palette_five(int n, int max, bool p)
{
	static int		tab[7] = {0x0000ff, 0x3399ff, 0x00ffff, 0x00ff00, 0xffff00,
		0x82004b, 0xe22b8a};

	if (n == max)
		return (0);
	return (tab[(n + (p ? max : 0)) % 7]);
}
