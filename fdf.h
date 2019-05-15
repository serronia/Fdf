/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fdf.h                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jdarko <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/02 11:08:03 by jdarko       #+#   ##    ##    #+#       */
/*   Updated: 2018/05/02 15:09:30 by jdarko      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "./minilibx_macos/mlx.h"
# include "./libft/libft.h"
# include <fcntl.h>
# include <errno.h>
# include <math.h>
# include <stdio.h>

typedef struct	s_point
{
	int			x;
	int			y;
	int			z;
}				t_point;

typedef struct	s_bresen
{
	int			dx;
	int			dy;
	int			sx;
	int			sy;
	int			err;
}				t_bresen;

typedef struct	s_env
{
	int			len;
	int			**fdf;
	int			x;
	int			y;
	int			coef_z;
	void		*mlx;
	void		*win;
	int			az;
	int			bz;
	int			basex;
	int			basey;
	int			width;
	int			height;
	int			spc;
	int			len_x;
	int			len_y;
	int			dec;
}				t_env;

void			ft_bresen1(t_point a, t_point b, void *wlx, void *win);
int				**read_and_stock(int fd, char *line, char **argv, t_env *mlx);
int				**read_and_stock2(int fd, char *line, t_env *mlx);
void			ft_str_int_del(int **as);
int				free_fdf(t_env **mlx);
char			**ft_error(char *line);
int				main(int argc, char **argv);
t_env			init_struct(t_env mlx);
int				trace_column(t_env mlx);
int				trace_line(t_env mlx);
t_bresen		ft_init_bresen(t_point a, t_point b);
int				bonus_key(int key, t_env *mlx);
int				bonus_key_2(int key, t_env *mlx);

#endif
