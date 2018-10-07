/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gofernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 00:35:59 by gofernan          #+#    #+#             */
/*   Updated: 2018/10/07 16:25:31 by gofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int				get_light(int start, int end, double percent)
{
	return ((int)((1 - percent) * start + percent * end));
}

int				get_gradient(float percent, int color1, int color2)
{
	int red;
	int green;
	int blue;

	red = get_light((color1 >> 16 & 0xff), (color2 >> 16 & 0xff), percent);
	green = get_light((color1 >> 8 & 0xff), (color2 >> 8 & 0xff), percent);
	blue = get_light((color1 & 0xff), (color2 & 0xff), percent);
	return ((red << 16) | (green << 8) | blue);
}

float			percent(int start, int end, int current)
{
	float percent;

	percent = (float)(current - start) / (end - start);
	return (percent);
}

int				point_color(t_data *pdata, int current, int opt)
{
	int		color1;
	int		color2;
	float	prc;

	if (!opt)
	{
		color1 = 0x463300;
		color2 = 0xc3b180;
	}
	else
	{
		color1 = pdata->draw->color[0];
		color2 = pdata->draw->color[1];
		if (color1 == color2)
			return (color1);
	}
	if (pdata->z_min == pdata->z_max)
		return (color1);
	if (!opt)
		prc = percent(pdata->z_min, pdata->z_max, current);
	else
		prc = percent(pdata->z_min, pdata->draw->dx, current);
	return (get_gradient(prc, color1, color2));
}
