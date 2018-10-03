/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gofernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 09:35:24 by gofernan          #+#    #+#             */
/*   Updated: 2018/09/28 16:17:47 by gofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int			specific_error(char *errormsg)
{
	write(1, errormsg, ft_strlen(errormsg));
	return (1);
}

void		error_msg_clean(char **str, int ***matrix)
{
	perror("Error: ");
	if (str)
		ft_strdel(str);
	else
	{
		free(*matrix);
		*matrix = NULL;
	}
	exit(EXIT_FAILURE);
}

int			matrix_error(t_data *pdata, char **line, char ***rowstr,
		int createdl)
{
	free_retr(line, rowstr);
	free_matrix(pdata, createdl);
	return (specific_error("Matrix input malformed\n"));
}