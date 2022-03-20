/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-behc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 14:40:58 by mel-behc          #+#    #+#             */
/*   Updated: 2022/03/10 18:58:16 by mel-behc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/fractol.h"

void	mandelbrot(t_mlx v)
{
	t_complex	c;
	t_complex	z;

	v.xp = -1;
	while (++v.xp <= v.wd)
	{
		v.yp = -1;
		while (++v.yp <= v.hg)
		{
			c.real = ((double)v.xp / v.wd) * (v.mx_r - v.mn_r) + v.mn_r;
			c.igy = ((double)v.yp / v.hg) * (v.mx_i - v.mn_i) + v.mn_i;
			z.real = 0;
			z.igy = 0;
			v.iter = 0;
			while (pow(z.real, 2) + pow(z.igy, 2) < 4 && ++v.iter < v.mx_iter)
			{
				z = prod(z, z);
				z.real += c.real;
				z.igy += c.igy;
			}
			v.ig_addr[v.xp + v.yp * v.wd] = color(v.iter, v.mx_iter);
		}
	}
	mlx_put_image_to_window(v.mlx_p, v.wind_p, v.ig_p, 0, 0);
}
