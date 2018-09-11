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

int			sign(int x)
{
	if (x > 0)
		return (1);
	else if (x < 0)
		return (-1);
	else
		return (0);
}

void		draw_line(t_data *pdata)
{
	int x;
	int y;
	int temp;
	int p;
	int i;

	x = pdata->draw->x1;
	y = pdata->draw->y1;
	pdata->draw->dx = abs(pdata->draw->x2 - pdata->draw->x1);
	pdata->draw->dy = abs(pdata->draw->y2 - pdata->draw->y1);
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
	p = 2 * pdata->draw->dy - pdata->draw->dx;
	// replace with while
	for (i = 0; i < pdata->draw->dx; i++)
	{
		if (i > 0)
			put_pixel(pdata, x, y, 0xFF00FF);
		while (p >= 0)
		{
			p = p - 2 * pdata->draw->dx;
			if (pdata->draw->swap)
				x += pdata->draw->s1;
			else
				y += pdata->draw->s2;
		}
		p = p + 2 * pdata->draw->dy;
		if (pdata->draw->swap)
			y += pdata->draw->s2;
		else
			x += pdata->draw->s1;
	}
//put_pixel(pdata, x, y, 0xFFFFFF);
}
