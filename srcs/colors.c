/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 12:15:16 by gedemais          #+#    #+#             */
/*   Updated: 2019/06/04 18:37:21 by gedemais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		ft_palette_one(int n, int max, bool p)
{
	static int		tab[16] = {0xff0000, 0xff1010, 0xff2010, 0xff3020, 0xff4020,
		0xff5030, 0xff6030, 0xff7040, 0xff8040, 0xff9050, 0xffa050, 0xffb060,
		0xffc060, 0xffd070, 0xffe070, 0xfff070};

	if (n == max)
		return (0);
	return (tab[(n + (p ? max : 0)) % 16]);
}

int		ft_palette_two(int n, int max, bool p)
{
	int		tab[16] = {0x0000ff, 0x1010ff, 0x2010ff, 0x3020ff, 0x4020ff, 0x5030ff,
		0x6030ff, 0x7040ff, 0x8040ff, 0x9050ff, 0xa050ff, 0xb060ff, 0xc060ff,
		0xd070ff, 0xe070ff, 0xf070ff};

	if (n == max)
		return (0);
	return (tab[(n + (p ? max : 0)) % 16]);
}

int		ft_palette_three(int n, int max, bool p)
{
	int		tab[16] = {0x00ff00, 0x10ff10, 0x20ff10, 0x30ff20, 0x40ff20,
		0x50ff30, 0x60ff30, 0x70ff40, 0x80ff40, 0x90ff50, 0xa0ff50, 0xa5ff60,
		0xb0ff60, 0xb5ff70, 0xc0ff70, 0xc5ff70};

	if (n == max)
		return (0);
	return (tab[(n + (p ? max : 0)) % 16]);
}

int		ft_palette_four(int n, int max, bool p)
{
	int		tab[10] = {0xff0000, 0x00ff00, 0x0000ff, 0xffff00, 0xff00ff,
		0x00ffff, 0xffdd00, 0x00ffdd, 0xdd00ff, 0xc3f23f};

	if (n == max)
		return (0);
	return (tab[(n + (p ? max : 0)) % 10]);
}

int		ft_palette_five(int n, int max, bool p)
{
	int		tab[7] = {0x0000ff, 0x3399ff, 0x00ffff, 0x00ff00, 0xffff00,
		0x82004b, 0xe22b8a};

	if (n == max)
		return (0);
	return (tab[(n + (p ? max : 0)) % 7]);
}
