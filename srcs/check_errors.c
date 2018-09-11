/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gofernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 09:35:24 by gofernan          #+#    #+#             */
/*   Updated: 2018/09/11 09:39:18 by gofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int			specific_error(char *errormsg)
{
	write(1, errormsg, ft_strlen(errormsg));
	return (1);
}

void		error_msg_clean(char **str)
{
	perror("Error: ");
	ft_strdel(str);
	exit(EXIT_FAILURE);
}
