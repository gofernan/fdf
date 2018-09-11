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

int			convert_map(t_data *pdata)
{
	int i;
	int j;

	i = -1;
	while (++i < pdata->mrows)
	{
		j = -1;
		while (++j < pdata->mcols)
		{
			(pdata->map_x)[i][j] = j * TILE_WIDTH;
			(pdata->map_y)[i][j] = i * TILE_HEIGHT;
			(pdata->map_z)[i][j] = (pdata->matrix)[i][j] * TILE_Z;
			if (pdata->rot_x || pdata->rot_y || pdata->rot_z)
				rotation(pdata, &(pdata->map_x)[i][j], &(pdata->map_y)[i][j], &(pdata->map_z)[i][j]);
			else
				iso(&(pdata->map_x)[i][j], &(pdata->map_y)[i][j], &(pdata->map_z)[i][j]);
			if (!pdata->def_data)
			{
				if (pdata->scaling)
					scaling(pdata, &pdata->map_x[i][j], &pdata->map_y[i][j]);
			}
		}
	}
	if (pdata->def_data)
		pdata->def_data = 0;
	return (0);
}

int			create_map(t_data *pdata)
{
	int i;
	int j;

	i = -1;
	j = -1;
	if (!(pdata->map_x = (int **)malloc(sizeof(int *) * pdata->mrows)))
		//freematrix
		exit(EXIT_FAILURE);
	if (!(pdata->map_y = (int **)malloc(sizeof(int *) * pdata->mrows)))
	{
		//freematrix
		free(pdata->map_x);
		exit(EXIT_FAILURE);
	}
	if (!(pdata->map_z = (int **)malloc(sizeof(int *) * pdata->mrows)))
	{
		//freematrix
		free(pdata->map_x);
		free(pdata->map_y);
		exit(EXIT_FAILURE);
	}
	while (++i < pdata->mrows)
	{
		if (!((pdata->map_x)[i] = (int *)malloc(sizeof(int) * pdata->mcols)))
		{
			while (++j < i)
			{
				free((pdata->map_x)[j]);
				free((pdata->map_y)[j]);
				free((pdata->map_z)[j]);
			}
			//freematrix
			free(pdata->map_x);
			free(pdata->map_y);
			free(pdata->map_z);
			exit(EXIT_FAILURE);
		}
		if (!((pdata->map_y)[i] = (int *)malloc(sizeof(int) * pdata->mcols)))
		{
			while (++j < i)
			{
				free((pdata->map_x)[j]);
				free((pdata->map_y)[j]);
				free((pdata->map_z)[j]);
			}
			//freematrix
			free((pdata->map_x)[j]);
			free(pdata->map_x);
			free(pdata->map_y);
			free(pdata->map_z);
			exit(EXIT_FAILURE);
		}
		if (!((pdata->map_z)[i] = (int *)malloc(sizeof(int) * pdata->mcols)))
		{
			while (++j < i)
			{
				free(pdata->map_x[j]);
				free(pdata->map_y[j]);
				free(pdata->map_z[j]);
			}
			free(pdata->map_x[j]);
			free(pdata->map_y[j]);
			free(pdata->map_x);
			free(pdata->map_y);
			free(pdata->map_z);
			exit(EXIT_FAILURE);
		}
	}
	return (0);
}
