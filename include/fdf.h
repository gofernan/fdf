#ifndef FDF_H
# define FDF_H

# include <unistd.h>
# include "../minilibx/mlx.h"
# include <math.h>
# include "../libft/include/libft.h"
# include <stdio.h> // remove after use the printf function
# include <fcntl.h>

#define W_WIDTH 1600
#define W_HEIGHT 800
#define TILE_WIDTH 500
#define TILE_HEIGHT 500
#define TILE_Z 500

typedef struct		s_data
{
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	char			*img_data;
	int				bpp;
	int				size_line;
	int				endian;
	int				pixelbytes;
	int				tlimit;
	int				rlimit;
	int				**matrix;
	int				**map_x;
	int				**map_y;
	int				mrows;
	int				mcols;
	int				degrees;
	float			radian;
}					t_data;
int					main(int argc, char **argv);
void				init_v(t_data *pdata);
void				error_msg_clean(char **str);
void				free_retr(char **line, char ***rowstr);
void				free_matrix(t_data *pdata, int createdl);
int					matrix_error(t_data *pdata, char **line, char ***rowstr, int clines);
int					specific_error(char *errormsg);
int					retrieve_data(char *file, t_data *pdata);
int					create_map(t_data *pdata);
void				put_pixel(t_data *pdata, int x, int y, unsigned int color);
int					fill_map(t_data *pdata);
int					draw_points(t_data *pdata);
int					draw_lines(t_data *pdata);
void				draw_line(t_data *pdata, int x1, int y1, int x2, int y2);
int					convert_map(t_data *pdata);
void				iso(int *x, int *y, int *z);
float				rotation(t_data *pdata, float x, float y, int axis);
int					stored_correctly(t_data *pdata); // provisional
void				scaling(int *x, int *y);
#endif
