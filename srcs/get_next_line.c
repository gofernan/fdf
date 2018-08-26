/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gofernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 20:33:52 by gofernan          #+#    #+#             */
/*   Updated: 2018/03/26 18:20:26 by gofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"
#include "../include/get_next_line.h"

static t_listfd		*check_list(const int fd, t_listfd **list)
{
	t_listfd	*list2;

	if (!*list)
	{
		if (!(*list = (t_listfd *)malloc(sizeof(t_listfd))))
			return (NULL);
		(*list)->content = NULL;
		(*list)->fdnum = fd;
		(*list)->next = NULL;
		return (*list);
	}
	list2 = *list;
	while (list2)
	{
		if (list2->fdnum == fd)
			return (list2);
		list2 = list2->next;
	}
	if (!(list2 = (t_listfd *)malloc(sizeof(t_listfd))))
		return (NULL);
	list2->content = NULL;
	list2->fdnum = fd;
	list2->next = *list;
	*list = list2;
	return (*list);
}

int					ft_reallocation(char **line, int nb)
{
	char *newstr;

	newstr = NULL;
	if (!(newstr = ft_strnew(nb)))
		return (-1);
	ft_strcpy(newstr, *line);
	ft_strdel(line);
	*line = newstr;
	return (0);
}

int					check_endofline(char **reststr, char **line)
{
	char	*nlpos;
	char	*tmpline;
	int		lenline;

	nlpos = NULL;
	tmpline = NULL;
	if ((nlpos = ft_strchr(*line, '\n')))
	{
		if (*(nlpos + 1) != '\0')
		{
			if (!(*reststr = ft_strnew(ft_strlen(nlpos + 1))))
				return (-1);
			ft_strcpy(*reststr, (nlpos + 1));
		}
		lenline = ft_strlen(*line) - ft_strlen(nlpos);
		tmpline = ft_strnew(lenline);
		ft_strncpy(tmpline, *line, lenline);
		tmpline[lenline] = '\0';
		ft_strdel(line);
		*line = tmpline;
		return (1);
	}
	return (0);
}

int					readf(char **line, t_listfd *alist, int res, const int fd)
{
	int readed;
	int totreaded;

	if ((totreaded = ft_strlen(*line)))
		if ((ft_reallocation(line, BUFF_SIZE + totreaded)) == -1)
			return (-1);
	while ((readed = read(fd, (*line + totreaded), BUFF_SIZE)))
	{
		if (readed < 0)
			ft_strdel(line);
		if (readed < 0)
			return (-1);
		if ((res = check_endofline(&(alist->content), line)) != 0)
			return (res);
		if (readed < BUFF_SIZE)
			return (1);
		totreaded = ft_strlen(*line);
		if (readed == BUFF_SIZE)
			if ((ft_reallocation(line, totreaded + BUFF_SIZE)) == -1)
				return (-1);
	}
	if (readed == 0 && **line)
		return (1);
	ft_strdel(line);
	return (0);
}

int					get_next_line(const int fd, char **line)
{
	static t_listfd	*list = NULL;
	t_listfd		*alist;
	int				res;

	res = 0;
	alist = NULL;
	if (fd < 0 || line == NULL)
		return (-1);
	*line = NULL;
	if (!(alist = check_list(fd, &list)))
		return (-1);
	if (alist->content)
	{
		if (!(*line = ft_strnew(ft_strlen(alist->content))))
			return (-1);
		ft_strcpy(*line, alist->content);
		ft_strdel(&(alist->content));
		if ((res = check_endofline(&(alist->content), line)))
			return (res);
	}
	else if (!(*line = ft_strnew(BUFF_SIZE)))
		return (-1);
	return (readf(line, alist, res, fd));
}
