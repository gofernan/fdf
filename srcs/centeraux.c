/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   centeraux.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gofernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 16:50:54 by gofernan          #+#    #+#             */
/*   Updated: 2018/10/05 16:50:59 by gofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int			big_small(t_data *pdata, int **map, int opt)
{
	int i;
	int j;
	int bgosm;

	i = -1;
	bgosm = map[0][0];
	while (++i < pdata->mrows)
	{
		j = -1;
		while (++j < pdata->mcols)
		{
			if (opt)
			{
				if (map[i][j] > bgosm)
					bgosm = map[i][j];
			}
			else
			{
				if (map[i][j] < bgosm)
					bgosm = map[i][j];
			}
		}
	}
	return (bgosm);
}
