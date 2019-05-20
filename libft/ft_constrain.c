/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_constrain.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 15:14:13 by gedemais          #+#    #+#             */
/*   Updated: 2019/01/10 15:22:02 by gedemais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_constrain(int val, int min, int max)
{
	if (val > max)
		val -= max * (val / max);
	else if (val < min)
		val += max * -(val / max);
	return (val);
}
