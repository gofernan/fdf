/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gofernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 09:35:15 by gofernan          #+#    #+#             */
/*   Updated: 2018/09/11 09:59:59 by gofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static int		sign(int x)
{
	if (x > 0)
		return (1);
	else if (x < 0)
		return (-1);
	else
		return (0);
}

void			init_draw_line(t_data *pdata)
{
	int		temp;

	pdata->draw->x = pdata->draw->x1;
	pdata->draw->y = pdata->draw->y1;
	pdata->draw->dx = ft_abs(pdata->draw->x2 - pdata->draw->x1);
	pdata->draw->dy = ft_abs(pdata->draw->y2 - pdata->draw->y1);
	pdata->draw->s1 = sign(pdata->draw->x2 - pdata->draw->x1);
	pdata->draw->s2 = sign(pdata->draw->y2 - pdata->draw->y1);
	pdata->draw->swap = 0;
	//put_pixel(pdata, x, y, 0xFFFFFF);
	if (pdata->draw->dy > pdata->draw->dx)
	{
		temp = pdata->draw->dx;
		pdata->draw->dx = pdata->draw->dy;
		pdata->draw->dy = temp;
		pdata->draw->swap = 1;
	}
	pdata->draw->p = 2 * pdata->draw->dy - pdata->draw->dx;
}

void			draw_line(t_data *pdata)
{
	int i;

	init_draw_line(pdata);
	i = -1;
	while (++i < pdata->draw->dx)
	{
		if (i > 0)
		{
			put_pixel(pdata, pdata->draw->x, pdata->draw->y, 0x24FF00);
			//put_pixel(pdata, x, y, get_color(pdata, &i));
		}
		while (pdata->draw->p >= 0)
		{
			pdata->draw->p = pdata->draw->p - 2 * pdata->draw->dx;
			if (pdata->draw->swap)
				pdata->draw->x += pdata->draw->s1;
			else
				pdata->draw->y += pdata->draw->s2;
		}
		pdata->draw->p = pdata->draw->p + 2 * pdata->draw->dy;
		if (pdata->draw->swap)
			pdata->draw->y += pdata->draw->s2;
		else
			pdata->draw->x += pdata->draw->s1;
	}
//put_pixel(pdata, x, y, 0xFFFFFF);
}
