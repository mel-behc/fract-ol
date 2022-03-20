/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-behc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 18:58:29 by mel-behc          #+#    #+#             */
/*   Updated: 2022/03/10 19:00:22 by mel-behc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/fractol.h"

static void	ft_putchar(char c)
{
	write(1, &c, 1);
}

static void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}

void	print_msg(void)
{
	ft_putstr("[farawcatoul_mandatory] \
			Error: commande for mandelbrot farawcatoul_m M\n");
	ft_putstr("[farawcatoul_mandatory] \
			Error: commande for julia farawcatoul_m J\n");
}
