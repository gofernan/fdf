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
		convert_map(pdata);
		draw_map(pdata);
		mlx_put_image_to_window(pdata->mlx_ptr, pdata->win_ptr, pdata->img_ptr, 0, 0);
		draw_info(pdata);
		pdata->action = 0;
	}
	return (0);
}
