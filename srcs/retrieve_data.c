/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   retrieve_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gofernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 09:36:24 by gofernan          #+#    #+#             */
/*   Updated: 2018/09/28 16:29:15 by gofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"
#include "../include/get_next_line.h"

int		create_columns(t_data *pdata, char **rowstr, int clines)
{
	int		i;
	int		colsnum;

	i = -1;
	colsnum = 0;
	while (rowstr[++i] != 0)
		colsnum++;
	if (clines == 0)
		pdata->mcols = colsnum;
	if (colsnum != pdata->mcols)
		return (1);
	if (!((pdata->matrix)[clines] = (int *)malloc(sizeof(int) * colsnum)))
		exit(EXIT_FAILURE);
	return (0);
}

void	store_matrix(t_data *pdata, char **rowstr, int clines)
{
	int i;

	i = -1;
	while (++i < pdata->mcols)
		(pdata->matrix)[clines][i] = ft_atoi(rowstr[i]);
}

int		read_rows(t_data *pdata, int fd, int *content, int clines)
{
	char		*line;
	char		**rowstr;
	int			i;
	int			j;

	while ((*content = get_next_line(fd, &line)) == 1)
	{
		rowstr = ft_strsplit(line, ' ');
		if (create_columns(pdata, rowstr, clines))
			return (matrix_error(pdata, &line, &rowstr, clines));
		i = -1;
		while (rowstr[++i] != 0)
		{
			j = -1;
			while (rowstr[i][++j] != '\0')
				if (!isdigit(rowstr[i][j]) && !(rowstr[i][0] == '-' &&
					isdigit(rowstr[i][1])))
					return (matrix_error(pdata, &line, &rowstr, clines + 1));
		}
		store_matrix(pdata, rowstr, clines);
		free_retr(&line, &rowstr);
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
		error_msg_clean(&str, NULL);
	while ((res = read(fd, str, 1000)) > 0)
	{
		i = -1;
		while (++i < res)
			if (str[i] == '\n')
				counter++;
	}
	if (res < 0)
		error_msg_clean(&str, NULL);
	if (close(fd) < 0)
		error_msg_clean(&str, NULL);
	ft_strdel(&str);
	return (counter);
}

int		retrieve_data(char *file, t_data *pdata)
{
	int		fd;
	int		rowsn;
	int		clines;
	int		content;

	clines = 0;
	pdata->mrows = count_rows(file);
	if (!(pdata->matrix = (int **)malloc(sizeof(int *) * pdata->mrows)))
		exit(EXIT_FAILURE);
	if ((fd = open(file, O_RDONLY)) < 0)
		error_msg_clean(NULL, &pdata->matrix);
	if (read_rows(pdata, fd, &content, clines))
		return (1);
	if (content == -1)
		exit(EXIT_FAILURE);
	return (0);
}
