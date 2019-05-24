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
	tab[0] = 0xff5555;
	tab[1] = 0xee5555;
	tab[2] = 0xdd5555;
	tab[3] = 0xcc5555;
	tab[4] = 0xbb4444;
	tab[5] = 0xaa4444;
	tab[6] = 0x994444;
	tab[7] = 0x884444;
	tab[8] = 0x773333;
	tab[9] = 0x663333;
	tab[10] = 0x553333;
	tab[11] = 0x443333;
	tab[12] = 0x332222;
	tab[13] = 0x222222;
	tab[14] = 0x111111;
	tab[15] = 0x001111;
	return (tab[n % 16]);
}

int		ft_palette_two(int n, int max)
{
	int		tab[16];
	if (n == max)
		return (0);
	tab[0] = 0x20ff20;
	tab[1] = 0x20ee20;
	tab[2] = 0x20dd20;
	tab[3] = 0x20cc20;
	tab[4] = 0x15bb15;
	tab[5] = 0x15aa15;
	tab[6] = 0x159915;
	tab[7] = 0x158815;
	tab[8] = 0x107710;
	tab[9] = 0x106610;
	tab[10] = 0x105510;
	tab[11] = 0x104410;
	tab[12] = 0x053305;
	tab[13] = 0x052205;
	tab[14] = 0x051105;
	tab[15] = 0x05ff05;
	return (tab[n % 16]);
}

int		ft_palette_three(int n, int max)
{
	int		tab[16];
	if (n == max)
		return (0);
	tab[0] = 0x0000ff;
	tab[1] = 0x0120ff;
	tab[2] = 0x0140ff;
	tab[3] = 0x0160ff;
	tab[4] = 0x0180ff;
	tab[5] = 0x01a0ff;
	tab[6] = 0x01c0ff;
	tab[7] = 0x00ffff;
	tab[8] = 0x20e0ff;
	tab[9] = 0x40c0ff;
	tab[10] = 0x60a0ff;
	tab[11] = 0x8080ff;
	tab[12] = 0xa060ff;
	tab[13] = 0xc040ff;
	tab[14] = 0xe020ff;
	tab[15] = 0xff00ff;
	return (tab[n % 16]);
}

int		ft_palette_four(int n, int max)
{
	int		tab[16];
	if (n == max)
		return (0);
	tab[0] = 0x0000ff;
	tab[1] = 0x0020ff;
	tab[2] = 0x0040ff;
	tab[3] = 0x0060ff;
	tab[4] = 0x0080ff;
	tab[5] = 0x00a0ff;
	tab[6] = 0x00c0ff;
	tab[7] = 0x00e0ff;
	tab[8] = 0x00ffff;
	tab[9] = 0x20e0ff;
	tab[10] = 0x60a0ff;
	tab[11] = 0x8080ff;
	tab[12] = 0xa060ff;
	tab[13] = 0xc03dff;
	tab[14] = 0xe020ff;
	tab[15] = 0xffffff;
	return (tab[n % 16]);
}
