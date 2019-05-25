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
	tab[13] = 0x000000;
	tab[14] = 0x000000;
	tab[15] = 0x000000;
	return (tab[n % 16]);
}

int		ft_palette_two(int n, int max)
{
	int		tab[16];
	if (n == max)
		return (0);
	tab[0] = 0x000000;
	tab[1] = 0x000000;
	tab[2] = 0x000000;
	tab[3] = 0x000000;
	tab[4] = 0x000000;
	tab[5] = 0x000000;
	tab[6] = 0x000000;
	tab[7] = 0x000000;
	tab[8] = 0x000000;
	tab[9] = 0x000000;
	tab[10] = 0x000000;
	tab[11] = 0x000000;
	tab[12] = 0x000000;
	tab[13] = 0x000000;
	tab[14] = 0x000000;
	tab[15] = 0x000000;
	return (tab[n % 16]);
}

int		ft_palette_three(int n, int max)
{
	int		tab[16];
	if (n == max)
		return (0);
	tab[0] = 0x000000;
	tab[1] = 0x000000;
	tab[2] = 0x000000;
	tab[3] = 0x000000;
	tab[4] = 0x000000;
	tab[5] = 0x000000;
	tab[6] = 0x000000;
	tab[7] = 0x000000;
	tab[8] = 0x000000;
	tab[9] = 0x000000;
	tab[10] = 0x000000;
	tab[11] = 0x000000;
	tab[12] = 0x000000;
	tab[13] = 0x000000;
	tab[14] = 0x000000;
	tab[15] = 0x000000;
	return (tab[n % 16]);
}

int		ft_palette_four(int n, int max)
{
	int		tab[16];
	if (n == max)
		return (0);
	tab[0] = 0x000000;
	tab[1] = 0x000000;
	tab[2] = 0x000000;
	tab[3] = 0x000000;
	tab[4] = 0x000000;
	tab[5] = 0x000000;
	tab[6] = 0x000000;
	tab[7] = 0x000000;
	tab[8] = 0x000000;
	tab[9] = 0x000000;
	tab[10] = 0x000000;
	tab[11] = 0x000000;
	tab[12] = 0x000000;
	tab[13] = 0x000000;
	tab[14] = 0x000000;
	tab[15] = 0x000000;
	return (tab[n % 16]);
}
