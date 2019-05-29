/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 19:02:07 by gedemais          #+#    #+#             */
/*   Updated: 2019/05/29 13:56:08 by gedemais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/fractol.h"

int		ft_uncase_strncmp(char *s1, char *s2, int size)
{
	int		i;

	i = 0;
	if (!s1[i] && !s2[i])
		return (0);
	while (s1[i] && s2[i] && (s1[i] == s2[i] || ((s1[i] == s2[i] - 32
					|| s1[i] == s2[i] + 32) && ft_isalpha(s1[i]) == 1
					&& ft_isalpha(s2[i]) == 1)))
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int		ft_name_tree(char *name)
{
	if (ft_uncase_strncmp(name, "mandelbrot", 10) == 0)
		return (MANDELBROT);
	else if (ft_uncase_strncmp(name, "julia", 5) == 0)
		return (JULIA);
	else if (ft_uncase_strncmp(name, "burningship", 11) == 0)
		return (BURNINGSHIP);
	else
		return (-1);
	return (0);
}
