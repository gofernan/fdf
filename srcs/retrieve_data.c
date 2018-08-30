#include "../include/fdf.h"
#include "../include/get_next_line.h"

int		create_columns(int **matrix, char **rowstr, int clines, int *colsn)
{
	int		i;
	int		colsnum;

	i = -1;
	colsnum = 0;
	while (rowstr[++i] != 0)
		colsnum++;
	if (clines == 0)
		*colsn = colsnum;
	if (colsnum != *colsn)
		return (1);
	if (!(matrix[clines] = (int *)malloc(sizeof(int) * colsnum)))
		exit(EXIT_FAILURE);
	return (0);
}

void	store_matrix(char **rowstr, int **matrix, int colsn, int clines)
{
	int i;

	i = -1;
	while (++i < colsn)
		matrix[clines][i] = ft_atoi(rowstr[i]);
}

int		matrix_error(char **line, int ***matrix, char ***rowstr, int createdl)
{
	int i;

	i = -1;
	ft_strdel(line);
	while (createdl > 0)
		free((*matrix)[--createdl]);
	free(*matrix);
	*matrix = NULL;
	while ((*rowstr)[++i] != 0)
	{
		free((*rowstr)[i]);
		(*rowstr)[i] = NULL;
	}
	free(*rowstr);
	*rowstr = NULL;
	return (specific_error("Matrix input malformed\n"));
}

int		read_rows(int **matrix, int fd, int *content, int clines)
{
	char		*line;
	char		**rowstr;
	int			colsn;
	int			i;
	int			j;

	while ((*content = get_next_line(fd, &line)) == 1)
	{
		rowstr = ft_strsplit(line, ' ');
		if (create_columns(matrix, rowstr, clines, &colsn))
			return (matrix_error(&line, &matrix, &rowstr, clines));
		i = -1;
		while (rowstr[++i] != 0)
		{
			j = -1;
			while (rowstr[i][++j] != '\0')
			{
				if (!isdigit(rowstr[i][j]) && !(rowstr[i][0] == '-' &&
					isdigit(rowstr[i][1])))
					return (matrix_error(&line, &matrix, &rowstr, clines + 1));
			}
		}
		store_matrix(rowstr, matrix, colsn, clines);
		clines++;
	}
	return (0);
}

int		count_rows(char *file)
{
	int		fd;
	char	*str;
	int		res;
	int		counter;
	int		i;

	counter = 0;
	if (!(str = (char *)malloc(sizeof(char) * 1000)))
		exit(EXIT_FAILURE);
	if ((fd = open(file, O_RDONLY)) < 0)
		error_msg_clean(&str);
	while ((res = read(fd, str, 1000)) > 0)
	{
		i = -1;
		while (++i < res)
			if (str[i] == '\n')
				counter++;
	}
	if (res < 0)
		error_msg_clean(&str);
	if (close(fd) < 0)
		error_msg_clean(&str);
	ft_strdel(&str);
	return (counter);
}

int		retrieve_data(char *file, int ***matrix)
{
	int		fd;
	int		rowsn;
	int		clines;
	int		content;

	clines = 0;
	if (!(*matrix = (int **)malloc(sizeof(int *) * (rowsn = count_rows(file)))))
		exit(EXIT_FAILURE);
	if ((fd = open(file, O_RDONLY)))
		//error_msg_clean(&matrix); modify
	if (read_rows(*matrix, fd, &content, clines))
		return (1);
	if (content == -1)
		exit(EXIT_FAILURE);
	return (0);
}
