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
