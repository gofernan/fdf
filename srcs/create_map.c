/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gofernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 09:35:34 by gofernan          #+#    #+#             */
/*   Updated: 2018/09/11 10:00:46 by gofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void		fill_values(t_data *pdata, int *i, int *j)
{
	(pdata->map_x)[*i][*j] = *j * pdata->xtile;
	(pdata->map_y)[*i][*j] = *i * pdata->ytile;
	(pdata->map_z)[*i][*j] = (pdata->matrix)[*i][*j] * pdata->ztile;
	(pdata->map_col)[*i][*j] = (pdata->matrix)[*i][*j] * pdata->ztile;
	if (pdata->map_col[*i][*j] < pdata->z_min)
		pdata->z_min = pdata->map_col[*i][*j];
	if (pdata->map_col[*i][*j] > pdata->z_max)
		pdata->z_max = pdata->map_col[*i][*j];
}

void		convert_map(t_data *pdata)
{
	int i;
	int j;

	i = -1;
	pdata->z_min = 0;
	pdata->z_max = 0;
	while (++i < pdata->mrows)
	{
		j = -1;
		while (++j < pdata->mcols)
		{
			fill_values(pdata, &i, &j);
			if (!pdata->reset || pdata->proj)
			{
				if (pdata->rot_x || pdata->rot_y || pdata->rot_z)
					rotation(pdata, &i, &j);
				if (pdata->proj)
					iso(pdata, &i, &j);
				if (pdata->move_x || pdata->move_y)
					move_xy(pdata, &i, &j);
				if (pdata->scaling != 1.0)
					scaling(pdata, &pdata->map_x[i][j], &pdata->map_y[i][j]);
			}
		}
	}
}

int			create_map(t_data *pdata)
{
	int i;

	i = 0;
	if (!(pdata->map_x = (int **)malloc(sizeof(int *) * pdata->mrows)))
		free_map(pdata, 0, 0);
	if (!(pdata->map_y = (int **)malloc(sizeof(int *) * pdata->mrows)))
		free_map(pdata, 1, 0);
	if (!(pdata->map_z = (int **)malloc(sizeof(int *) * pdata->mrows)))
		free_map(pdata, 2, 0);
	if (!(pdata->map_col = (int **)malloc(sizeof(int *) * pdata->mrows)))
		free_map(pdata, 3, 0);
	while (i < pdata->mrows)
	{
		if (!((pdata->map_x)[i] = (int *)malloc(sizeof(int) * pdata->mcols)))
			free_map(pdata, 4, i - 1);
		if (!((pdata->map_y)[i] = (int *)malloc(sizeof(int) * pdata->mcols)))
			free_map(pdata, 5, i - 1);
		if (!((pdata->map_z)[i] = (int *)malloc(sizeof(int) * pdata->mcols)))
			free_map(pdata, 6, i - 1);
		if (!((pdata->map_col)[i] = (int *)malloc(sizeof(int) * pdata->mcols)))
			free_map(pdata, 7, i - 1);
		i++;
	}
	return (0);
}

void		pre_convert_map(t_data *pdata)
{
	if (pdata->rot_y)
		pdata->rot_rady = pdata->rot_y * 3.1415 / 180;
	if (pdata->rot_x)
		pdata->rot_radx = pdata->rot_x * 3.1415 / 180;
	if (pdata->rot_z)
		pdata->rot_radz = pdata->rot_z * 3.1415 / 180;
}
