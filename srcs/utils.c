/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gofernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 09:36:39 by gofernan          #+#    #+#             */
/*   Updated: 2018/09/11 09:58:37 by gofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void		free_retr(char **line, char ***rowstr)
{
	int i;

	i = -1;
	ft_strdel(line);
	while ((*rowstr)[++i] != 0)
	{
		free((*rowstr)[i]);
		(*rowstr)[i] = NULL;
	}
	free(*rowstr);
	*rowstr = NULL;
}

void		free_matrix(t_data *pdata, int createdl)
{
	while (createdl > 0)
		free((pdata->matrix)[--createdl]);
	free(pdata->matrix);
	pdata->matrix = NULL;
}

void		free_map(t_data *pdata, int opt, int index)
{
	int value;

	value = 0;
	while ((opt >= 3 && opt <= 5) && value <= index)
	{
		free(pdata->map_x[value]);
		free(pdata->map_y[value]);
		free(pdata->map_z[value]);
		value++;
	}
	if (opt == 4 || opt == 5) 
		free(pdata->map_x[value]);
	if (opt == 5)
		free(pdata->map_y[value]);
	if (opt >= 1 && opt <= 5)
		free(pdata->map_x);
	if (opt >= 2 && opt <= 5)
		free(pdata->map_y);
	if (opt >= 3 && opt <= 5)
		free(pdata->map_z);
	free_matrix(pdata, pdata->mrows);
	exit(EXIT_FAILURE);
}

int			clear_img(t_data *pdata)
{
	int i;
	int j;
	int pixel;

	i = -1;
	while (++i <= pdata->tlimit)
		(pdata->img_data)[i] = 0;
	return (0);
}
