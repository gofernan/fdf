#include "../include/fdf.h"

/*void		free_rows(int **rows, int rowsnum)
{
	while (rowsnum--)
		free(rows[rowsnum]);
	rows = NULL;
}*/

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
	free (*rowstr);
	*rowstr = NULL;
}

void		free_matrix(t_data *pdata, int createdl)
{
	while (createdl > 0)
		free((pdata->matrix)[--createdl]);
	free(pdata->matrix);
	pdata->matrix = NULL;
}
