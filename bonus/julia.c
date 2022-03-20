/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-behc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 13:59:25 by mel-behc          #+#    #+#             */
/*   Updated: 2022/03/09 14:40:54 by mel-behc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/fractol.h"

static void	julia_draw(t_mlx *v)
{
	t_complex	z;

	v->xp = -1;
	while (++v->xp < v->wd)
	{
		v->yp = -1;
		while (++v->yp < v->hg)
		{
			z.real = ((v->mx_r - v->mn_r) * ((double)v->xp / v->wd) + v->mn_r);
			z.igy = ((v->mx_i - v->mn_i) * ((double)v->yp / v->hg) + v->mn_i);
			v->iter = 0;
			while (pow(z.real, 2) + pow(z.igy, 2) < 4 && ++v->iter < v->mx_iter)
			{
				z = prod(z, z);
				z.real += v->c.real;
				z.igy += v->c.igy;
			}
			v->ig_addr[v->xp + v->yp * v->wd] = color(v->iter, v->mx_iter);
		}
		mlx_put_image_to_window(v->mlx_p, v->wind_p, v->ig_p, 0, 0);
	}
}

void	julia(t_mlx v)
{
	julia_draw(&v);
}
