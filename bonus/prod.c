/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prod.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-behc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 14:43:20 by mel-behc          #+#    #+#             */
/*   Updated: 2022/03/10 19:00:35 by mel-behc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/fractol.h"

t_complex	prod(t_complex a, t_complex b)
{
	t_complex	ret;

	ret.real = a.real * b.real - a.igy * b.igy;
	ret.igy = a.real * b.igy + a.igy * b.real;
	return (ret);
}
