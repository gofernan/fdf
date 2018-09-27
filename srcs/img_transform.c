/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_transform.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gofernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 09:36:07 by gofernan          #+#    #+#             */
/*   Updated: 2018/09/11 09:52:32 by gofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int			img_transform(t_data *pdata)
{
	if (pdata->action)
	{
		clear_img(pdata);
		if (pdata->rot_x || pdata->rot_y || pdata->rot_z)
			pre_convert_map(pdata);
		//map_size(pdata);
		convert_map(pdata);
		draw_map(pdata);
		mlx_put_image_to_window(pdata->mlx_ptr, pdata->win_ptr, pdata->img_ptr, 0, 0);
		if (pdata->info && W_WIDTH >= 400 && W_HEIGHT >= 140)
			draw_info(pdata);
		pdata->action = 0;
		if (pdata->reset)
			pdata->reset = 0;
	}
	return (0);
}
