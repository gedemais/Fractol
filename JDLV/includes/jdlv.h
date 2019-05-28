/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 18:50:23 by gedemais          #+#    #+#             */
/*   Updated: 2019/05/28 18:45:13 by gedemais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define KEY_PRESS 2
# define KEY_PRESS_MASK (1L<<0)

# define NB_THREADS 8

# include "../libft/libft.h"
# include "mlx.h"
# include <stdbool.h>
# include <pthread.h>

typedef struct	s_mlx
{

	void		*mlx_ptr;
	void		*mlx_win;
	void		*img_ptr;
	char		*img_data;
	int			bpp;
	int			s_l;
	int			endian;
	int			size;
	int			hgt;
	int			wdt;
	bool		**map;
	bool		**tmp;
}				t_mlx;

void	ft_fill_pixel(char *img_str, int x, int y, int color);
int		ft_init_map(t_mlx *env, int size);

int		*ft_wdt(void);
int		*ft_hgt(void);

char	*ft_clear_image(void *param);
char	*ft_draw_tale(void *param, int i, int j, int tale_size);
char	*ft_print_image(void *param);

void	*ft_process(void *param);

#endif
