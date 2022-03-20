/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-behc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 14:44:11 by mel-behc          #+#    #+#             */
/*   Updated: 2022/03/10 19:01:37 by mel-behc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <math.h>
# include "../../minilibx/mlx.h"
# include <unistd.h>

typedef struct s_complex
{
	double	real;
	double	igy;
}				t_complex;

typedef struct s_mlx
{
	void		*mlx_p;
	void		*wind_p;
	void		*ig_p;
	int			*ig_addr;
	int			bpp;
	int			ln;
	int			ed;
	int			xp;
	int			yp;
	int			mx_iter;
	int			iter;
	double		tmp;
	int			wd;
	int			hg;
	double		mx_i;
	double		mn_i;
	double		mx_r;
	double		mn_r;
	t_complex	c;
}				t_mlx;

int			color(int iter, int max_iter);
t_complex	prod(t_complex a, t_complex b);
void		mandelbrot(t_mlx v);
void		julia(t_mlx v);
int			zoom_mdt(int code, int x, int y, t_mlx *v);
int			zoom_julia(int code, int x, int y, t_mlx *v);
void		print_msg(void);

#endif
