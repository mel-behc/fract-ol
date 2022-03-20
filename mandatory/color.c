/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-behc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 15:25:03 by mel-behc          #+#    #+#             */
/*   Updated: 2022/03/09 15:25:43 by mel-behc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/fractol.h"

int	color(int iter, int max_iter)
{
	double			per;
	int				ret;
	unsigned char	*rgb;
	int				*ptr;

	if (iter == max_iter)
		return (0);
	per = (double)iter / max_iter;
	ptr = &ret;
	rgb = (unsigned char *)ptr;
	rgb[1] = (char)(9 * (1 - per) * pow(per, 3) * 255);
	rgb[2] = (char)(15 * pow((1 - per), 2) * pow(per, 2) * 255);
	rgb[0] = (char)(8.5 * pow((1 - per), 3) * per * 255);
	rgb[3] = 0;
	return (ret);
}
