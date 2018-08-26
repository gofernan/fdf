#ifndef FDF_H
# define FDF_H

#include <unistd.h>
//#include <mlx.h>
#include "../minilibx/mlx.h"
#include <math.h>
#include "../libft/libft.h"
#include <stdio.h> // remove after use the printf function

#define W_WIDTH 800
#define W_HEIGHT 600

typedef struct		s_data
{
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	char			*img_data;
	int				bpp;
	int				size_line;
	int				endian;
}					t_data;
#endif
