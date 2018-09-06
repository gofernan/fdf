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
			iso(&(pdata->map_x)[i][j], &(pdata->map_y)[i][j], &(pdata->matrix)[i][j]);
			//scaling(&pdata->map_x[i][j], &pdata->map_y[i][j]);
			//(pdata->map_x)[i][j] = rotation(pdata, (pdata->map_x)[i][j], (pdata->map_y[i][j]), 1);
			//(pdata->map_y)[i][j] = rotation(pdata, (pdata->map_x)[i][j], (pdata->map_y[i][j]), 0);
		}
	}
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
	while (++i < pdata->mrows)
	{
		if (!((pdata->map_x)[i] = (int *)malloc(sizeof(int) * pdata->mcols)))
		{
			while (++j < i - 1)
			{
				free((pdata->map_x)[j]);
				free((pdata->map_y)[j]);
			}
			//freematrix
			free(pdata->map_x);
			free(pdata->map_y);
			exit(EXIT_FAILURE);
		}
		if (!((pdata->map_y)[i] = (int *)malloc(sizeof(int) * pdata->mcols)))
		{
			while(++j < i - 1)
			{
				free((pdata->map_x)[j]);
				free((pdata->map_y)[j]);
			}
			//freematrix
			free((pdata->map_x)[j]);
			free(pdata->map_x);
			free(pdata->map_y);
			exit(EXIT_FAILURE);
		}
	}
	return (0);
}
