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
#define TILE_WIDTH 20
#define TILE_HEIGHT 20
#define TILE_Z 20

typedef struct		s_draw
{
	int				x1;
	int				x2;
	int				y1;
	int				y2;
	int				dx;
	int				dy;
	int				swap;
	int				s1;
	int				s2;
}					t_draw;

typedef struct		s_data
{
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	char			*img_data;
	int				bpp;
	int				size_line;
	int				endian;

	t_draw			*draw;
	int				proj;
	int				pixelbytes;
	int				tlimit;
	int				rlimit;
	int				**matrix;
	int				**map_x;
	int				**map_y;
	int				**map_z;
	int				mrows;
	int				mcols;
	int				action;
	int				def_data;
	int				scaling;
	float			scaling_v;
	int				rot_vx;
	int				rot_vy;
	int				rot_vz;
	int				rot_x;
	int				rot_y;
	int				rot_z;
	float			rot_radx;
	float			rot_rady;
	float			rot_radz;
	int				degrees;
	float			radian;
}					t_data;

int					main(int argc, char **argv);
void				init_v(t_data *pdata);
int					matrix_error(t_data *pdata, char **line, char ***rowstr, int clines);
int					retrieve_data(char *file, t_data *pdata);
int					specific_error(char *errormsg);
void				error_msg_clean(char **str);
void				free_retr(char **line, char ***rowstr);
void				free_matrix(t_data *pdata, int createdl);
int					create_map(t_data *pdata);
int					convert_map(t_data *pdata);
int					draw_map(t_data *pdata);
int					draw_points(t_data *pdata);
int					draw_lines(t_data *pdata);
void				draw_line(t_data *pdata);
void				put_pixel(t_data *pdata, int x, int y, unsigned int color);
int					img_transform(t_data *pdata);
int					clear_img(t_data *pdata);
void				iso(int *x, int *y, int *z);
int					stored_correctly(t_data *pdata); // provisional
void				scaling(t_data *pdata, int *x, int *y);
void				rotation(t_data *pdata, int *x, int *y, int *z);
#endif
