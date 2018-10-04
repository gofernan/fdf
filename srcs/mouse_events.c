/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_events.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gofernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 16:12:18 by gofernan          #+#    #+#             */
/*   Updated: 2018/09/28 16:12:19 by gofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int			mouse_press(int button, int x, int y, t_data *pdata)
{
	if (button == 1)
	{
		pdata->mouse_press = 1;
		pdata->mouse_x = x;
		pdata->mouse_y = y;
	}
	return (0);
}

int			mouse_move(int x, int y, t_data *pdata)
{
	if (pdata->mouse_press)
	{
		if (pdata->mouse_y != y)
		{
			pdata->rot_x += y - pdata->mouse_y;
			pdata->rot_radx = pdata->rot_x * 3.1415 / 180;
			pdata->mouse_y = y;
			pdata->action = 1;
		}
		if (pdata->mouse_x != x)
		{
			pdata->rot_y -= x - pdata->mouse_x;
			pdata->rot_rady = pdata->rot_y * 3.1415 / 180;
			pdata->mouse_x = x;
			pdata->action = 1;
		}
	}
	return (0);
}

int			mouse_release(int button, int x, int y, t_data *pdata)
{
	x = 0;
	y = 0;
	if (button == 1)
	{
		pdata->mouse_press = 0;
		pdata->action = 0;
	}
	return (0);
}
