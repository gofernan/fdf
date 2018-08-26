/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gofernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 23:13:45 by gofernan          #+#    #+#             */
/*   Updated: 2018/03/26 17:26:30 by gofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 999
# include <fcntl.h>

typedef struct		s_listfd
{
	char			*content;
	int				fdnum;
	struct s_listfd	*next;
}					t_listfd;

int					get_next_line(const int fd, char **line);
#endif
