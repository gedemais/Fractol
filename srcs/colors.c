/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 12:15:16 by gedemais          #+#    #+#             */
/*   Updated: 2019/05/23 17:08:50 by gedemais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		ft_palette_one(int n, int max)
{
	int		tab[16];
	if (n == max)
		return (0);
	tab[0] = 0xff0000;
	tab[1] = 0xff1010;
	tab[2] = 0xff2010;
	tab[3] = 0xff3020;
	tab[4] = 0xff4020;
	tab[5] = 0xff5030;
	tab[6] = 0xff6030;
	tab[7] = 0xff7040;
	tab[8] = 0xff8040;
	tab[9] = 0xff9050;
	tab[10] = 0xffa050;
	tab[11] = 0xffb060;
	tab[12] = 0xffc060;
	tab[13] = 0xffd070;
	tab[14] = 0xffe070;
	tab[15] = 0xfff070;
	return (tab[n % 16]);
}

int		ft_palette_two(int n, int max)
{
	int		tab[16];
	if (n == max)
		return (0);
	tab[0] = 0x0000ff;
	tab[1] = 0x1010ff;
	tab[2] = 0x2010ff;
	tab[3] = 0x3020ff;
	tab[4] = 0x4020ff;
	tab[5] = 0x5030ff;
	tab[6] = 0x6030ff;
	tab[7] = 0x7040ff;
	tab[8] = 0x8040ff;
	tab[9] = 0x9050ff;
	tab[10] = 0xa050ff;
	tab[11] = 0xb060ff;
	tab[12] = 0xc060ff;
	tab[13] = 0xd070ff;
	tab[14] = 0xe070ff;
	tab[15] = 0xf070ff;
	return (tab[n % 16]);
}

int		ft_palette_three(int n, int max)
{
	int		tab[16];
	if (n == max)
		return (0);
	tab[0] = 0x00ff00;
	tab[1] = 0x10ff10;
	tab[2] = 0x20ff10;
	tab[3] = 0x30ff20;
	tab[4] = 0x40ff20;
	tab[5] = 0x50ff30;
	tab[6] = 0x60ff30;
	tab[7] = 0x70ff40;
	tab[8] = 0x80ff40;
	tab[9] = 0x90ff50;
	tab[10] = 0xa0ff50;
	tab[11] = 0xa5ff60;
	tab[12] = 0xb0ff60;
	tab[13] = 0xb5ff70;
	tab[14] = 0xc0ff70;
	tab[15] = 0xc5ff70;
	return (tab[n % 16]);
}

int		ft_palette_four(int n, int max)
{
	int		tab[16];
	if (n == max)
		return (0);
	tab[0] = 0xff0000;
	tab[1] = 0x00ff00;
	tab[2] = 0x0000ff;
	tab[3] = 0xffff00;
	tab[4] = 0xff00ff;
	tab[5] = 0x00ffff;
	tab[6] = 0xffdd00;
	tab[7] = 0x00ffdd;
	tab[8] = 0xdd00ff;
	tab[9] = 0xc3f23f;
	tab[10] = 0x000000;
	tab[11] = 0x000000;
	tab[12] = 0x000000;
	tab[13] = 0x000000;
	tab[14] = 0x000000;
	tab[15] = 0x000000;
	return (tab[(n + max) % 10]);
}

int		ft_palette_five(int n, int max)
{
	int		tab[14];
	if (n == max)
		return (0);
	tab[0] = 0x0000ff;
	tab[1] = 0x3030ff;
	tab[2] = 0x00ff7f;
	tab[3] = 0x30ff9f;
	tab[4] = 0x00ffff;
	tab[5] = 0x30ffff;
	tab[6] = 0x00ff00;
	tab[7] = 0x30ff30;
	tab[8] = 0xff0000;
	tab[9] = 0xff3030;
	tab[10] = 0x824b00;
	tab[11] = 0x904f10;
	tab[12] = 0x00ff8b;
	tab[13] = 0x10ff9c;
	return (tab[(n + max) % 14]);
}
