/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom_mdt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-behc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 19:01:00 by mel-behc          #+#    #+#             */
/*   Updated: 2022/03/10 19:01:12 by mel-behc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/fractol.h"

int	zoom_mdt(int code, int x, int y, t_mlx *v)
{
	t_complex	c;

	c.real = (v->mx_r - v->mn_r) * ((double)x / v->wd) + (v->mn_r);
	c.igy = (v->mx_i - v->mn_i) * ((double)y / v->hg) + (v->mn_i);
	if (code == 4)
	{
		v->mx_i = (v->mx_i - c.igy) * 0.8 + c.igy;
		v->mx_r = (v->mx_r - c.real) * 0.8 + c.real;
		v->mn_i = (v->mn_i - c.igy) * 0.8 + c.igy;
		v->mn_r = (v->mn_r - c.real) * 0.8 + c.real;
		mandelbrot(*v);
	}
	else if (code == 5)
	{
		v->mx_i = (v->mx_i - c.igy) * 1.2 + c.igy;
		v->mx_r = (v->mx_r - c.real) * 1.2 + c.real;
		v->mn_i = (v->mn_i - c.igy) * 1.2 + c.igy;
		v->mn_r = (v->mn_r - c.real) * 1.2 + c.real;
		mandelbrot(*v);
	}
	return (0);
}
