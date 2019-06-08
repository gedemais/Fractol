/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 19:02:07 by gedemais          #+#    #+#             */
/*   Updated: 2019/06/08 12:22:04 by gedemais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

char	*ft_lowercase(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] > 'A' && str[i] < 'Z')
			str[i] = str[i] + 32;
		i++;
	}
	return (str);
}

int		ft_name_tree(char *name)
{
	if (ft_strncmp(ft_lowercase(name), "mandelbrot", 10) == 0)
		return (MANDELBROT);
	else if (ft_strncmp(ft_lowercase(name), "julia", 5) == 0)
		return (JULIA);
	else if (ft_strncmp(ft_lowercase(name), "burningship", 11) == 0)
		return (BURNINGSHIP);
	else
		return (-1);
	return (0);
}
