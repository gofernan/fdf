/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_img.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gofernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 09:35:30 by gofernan          #+#    #+#             */
/*   Updated: 2018/09/11 09:45:18 by gofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int			clear_img(t_data *pdata)
{
	int i;
	int j;
	int pixel;

	i = -1;
	while (++i <= pdata->tlimit)
	{
		(pdata->img_data)[i] = 0;
	}
	return (0);
}
