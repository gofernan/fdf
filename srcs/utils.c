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

int		matrix_error(t_data *pdata, char **line, char ***rowstr, int createdl)
{
	free_retr(line, rowstr);
	free_matrix(pdata, createdl);
	return (specific_error("Matrix input malformed\n"));
}
