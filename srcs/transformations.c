/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gofernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 09:36:35 by gofernan          #+#    #+#             */
/*   Updated: 2018/09/11 10:08:55 by gofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void		rotation_x(t_data *pdata, float *y, float *z)
{
	float temp_y;

	temp_y = *y;
	*y = (*y * cos(pdata->rot_radx) + (*z * -sin(pdata->rot_radx)));
	*z = (temp_y * sin(pdata->rot_radx) + (*z * cos(pdata->rot_radx)));
}

void		rotation_y(t_data *pdata, float *x, float *z)
{
	float temp_x;

	temp_x = *x;
	*x = (*x * cos(pdata->rot_rady) + (*z * sin(pdata->rot_rady)));
	*z = (temp_x * -sin(pdata->rot_rady) + (*z * cos(pdata->rot_rady)));
}

void		rotation_z(t_data *pdata, float *x, float *y)
{
	float temp_x;

	temp_x = *x;
	*x = (*x * cos(pdata->rot_radz) + (*y * -sin(pdata->rot_radz)));
	*y = (temp_x * sin(pdata->rot_radz) + (*y * cos(pdata->rot_radz)));
}

void		rotation(t_data *pdata, int *i, int *j)
{
	float fx;
	float fy;
	float fz;

	pdata->map_x[*i][*j] -= pdata->mcols / 2 * TILE_WIDTH;
	pdata->map_y[*i][*j] -= pdata->mrows / 2 * TILE_HEIGHT;
	fx = pdata->map_x[*i][*j];
	fy = pdata->map_y[*i][*j];
	fz = pdata->map_z[*i][*j];
	if (pdata->rot_x)
		rotation_x(pdata, &fy, &fz);
	if (pdata->rot_y)
		rotation_y(pdata, &fx, &fz);
	if (pdata->rot_z)
		rotation_z(pdata, &fx, &fy);
	pdata->map_x[*i][*j] = fx;
	pdata->map_y[*i][*j] = fy;
	pdata->map_z[*i][*j] = fz;
	pdata->map_x[*i][*j] += pdata->mcols / 2 * TILE_WIDTH;
	pdata->map_y[*i][*j] += pdata->mrows / 2 * TILE_HEIGHT;
}

void		scaling(t_data *pdata, int *x, int *y)
{
		*x = *x * pdata->scaling;
		*y = *y * pdata->scaling;
}
