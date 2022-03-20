/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-behc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 14:08:00 by mel-behc          #+#    #+#             */
/*   Updated: 2022/03/10 18:58:07 by mel-behc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/fractol.h"

static int	key_press(int code, t_mlx *v)
{
	if (code == 53)
	{
		mlx_clear_window(v->mlx_p, v->wind_p);
		mlx_destroy_image(v->mlx_p, v->ig_p);
		mlx_destroy_window(v->mlx_p, v->wind_p);
		exit(0);
	}
	if (code == 125)
		v->mx_iter += v->mx_iter / 2;
	if (code == 126)
		v->mx_iter -= v->mx_iter / 2;
	mlx_clear_window(v->mlx_p, v->wind_p);
	mandelbrot(*v);
	return (0);
}

static int	interaction_with_mouse(int x, int y, t_mlx *v)
{
	v->c.real = (v->mx_r - v->mn_r) * ((double)x / v->wd) + (v->mn_r);
	v->c.igy = (v->mx_i - v->mn_i) * ((double)y / v->hg) + (v->mn_i);
	mlx_clear_window(v->mlx_p, v->wind_p);
	julia(*v);
	return (0);
}

static int	fractal_check(char c, t_mlx v)
{
	if (c == 'M')
	{
		mandelbrot(v);
		mlx_hook(v.wind_p, 2, 0, &key_press, &v);
		mlx_hook(v.wind_p, 4, 0, &zoom_mdt, &v);
		mlx_loop(v.mlx_p);
	}
	else if (c == 'J')
	{
		julia(v);
		mlx_hook(v.wind_p, 6, 0, &interaction_with_mouse, &v);
		mlx_hook(v.wind_p, 2, 0, &key_press, &v);
		mlx_hook(v.wind_p, 4, 0, &zoom_julia, &v);
		mlx_loop(v.mlx_p);
	}
	else
		print_msg();
	return (1);
}

int	main(int ac, char **av)
{
	t_mlx	v;

	if (ac != 2)
		print_msg();
	else
	{
		v.wd = 500;
		v.hg = 500;
		v.mlx_p = mlx_init();
		v.wind_p = mlx_new_window(v.mlx_p, v.wd, v.hg, "fractol");
		v.ig_p = mlx_new_image(v.mlx_p, v.wd, v.hg);
		v.ig_addr = (int *)mlx_get_data_addr(v.ig_p, &v.bpp, &v.ln, &v.ed);
		v.mx_iter = 100;
		v.mx_i = 2;
		v.mn_i = -2;
		v.mx_r = 2;
		v.mn_r = -2;
		v.c.real = 0;
		v.c.igy = 0;
		fractal_check(*av[1], v);
	}
	return (0);
}
