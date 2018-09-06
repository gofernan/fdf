#include "../include/fdf.h"

int			stored_correctly(t_data *pdata)
{
	int i;
	int j;

	i = -1;
	while (++i < pdata->mrows)
	{
		j = -1;
		while (++j < pdata->mcols)
		{
			printf("%4d", (pdata->matrix)[i][j]);
		}
		printf("\n");
	}
	return (0);
}
