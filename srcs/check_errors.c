#include "../include/fdf.h"

int		error_msg(char *msg)
{
	write(1, msg, ft_strlen(msg));
	return (1);
}
