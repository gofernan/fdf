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
#define TILE_WIDTH 30
#define TILE_HEIGHT 30

typedef struct		s_data
{
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	char			*img_data;
	int				bpp;
	int				size_line;
	int				endian;
	int				**matrix;
	int				mrows;
	int				mcols;
}					t_data;
int					main(int argc, char **argv);
void				error_msg_clean(char **str);
void				free_retr(char **line, char ***rowstr);
void				free_matrix(t_data *pdata, int createdl);
int					specific_error(char *errormsg);
int					retrieve_data(char *file, t_data *pdata);
void				fill_pixel(t_data *pdata, int x, int y, unsigned int color);
int					fill_map(t_data *pdata);
int					parallel_proj(t_data *data);
#endif
