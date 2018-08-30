#ifndef FDF_H
# define FDF_H

# include <unistd.h>
# include "../minilibx/mlx.h"
# include <math.h>
# include "../libft/include/libft.h"
# include <stdio.h> // remove after use the printf function
# include <fcntl.h>

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
int					main(int argc, char **argv);
void				error_msg_clean(char **str);
void				free_rows(int **rows, int rowsnum);
int					specific_error(char *errormsg);
int					retrieve_data(char *file, int ***matrix);
#endif
