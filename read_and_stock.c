/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   read_and_stock.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jdarko <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/30 16:17:35 by jdarko       #+#   ##    ##    #+#       */
/*   Updated: 2018/05/02 14:38:24 by jdarko      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

int		**read_and_stock(int fd, char *line, char **argv, t_env *mlx)
{
	mlx->len = 0;
	while (get_next_line(fd, &line))
	{
		mlx->len++;
		ft_strdel(&line);
		mlx->len_y = mlx->len;
	}
	ft_strdel(&line);
	if (!(mlx->fdf = (int **)malloc(sizeof(int *) * mlx->len)))
		return (0);
	close(fd);
	if ((fd = open(argv[1], O_RDONLY)) == -1)
	{
		ft_putstr("error\n");
		return (0);
	}
	read_and_stock2(fd, line, mlx);
	if (mlx->dec != 3 && mlx->dec != 30 && mlx->dec != 9)
		*mlx = init_struct(*mlx);
	trace_column(*mlx);
	trace_line(*mlx);
	return (0);
}

int		**read_and_stock2(int fd, char *line, t_env *mlx)
{
	int		i;
	int		j;
	char	**split;

	i = 0;
	while (get_next_line(fd, &line))
	{
		j = -1;
		mlx->len_x = 0;
		split = ft_error(line);
		ft_strdel(&line);
		while (split[mlx->len_x] != '\0')
			mlx->len_x++;
		if (!(mlx->fdf[i] = (int *)malloc(sizeof(int) * mlx->len_x)))
			return (0);
		while (++j < mlx->len_x)
		{
			mlx->fdf[i][j] = ft_atoi(split[j]);
			ft_strdel(&split[j]);
		}
		free(split);
		i++;
	}
	ft_strdel(&line);
	return (0);
}

t_env	init_struct(t_env mlx)
{
	if (mlx.len_y * mlx.len_x > 20000)
	{
		mlx.basex = 50;
		mlx.basey = 800;
		mlx.dec = 2;
	}
	else if (mlx.len_y * mlx.len_x < 500)
	{
		mlx.basex = 550;
		mlx.basey = 500;
		mlx.dec = 30;
	}
	else
	{
		mlx.basex = 700;
		mlx.basey = 500;
		mlx.dec = 9;
	}
	mlx.coef_z = 1;
	mlx.x = 1;
	mlx.y = 1;
	mlx.spc = 5;
	return (mlx);
}

int		trace_column(t_env mlx)
{
	int			i;
	int			j;
	t_point		a;
	t_point		b;

	i = 0;
	while (i < mlx.len_y)
	{
		j = 0;
		while (j < mlx.len_x - 1)
		{
			a.z = mlx.fdf[i][j] * mlx.coef_z;
			a.y = (mlx.basey - (j * mlx.spc) + (i * mlx.dec) - 2 * a.z * mlx.y);
			a.x = (mlx.basex + (j * mlx.spc) + (j * mlx.dec) + (a.z * mlx.x));
			j++;
			b.z = mlx.fdf[i][j] * mlx.coef_z;
			b.y = (mlx.basey - (j * mlx.spc) + (i * mlx.dec) - 2 * b.z * mlx.y);
			b.x = (mlx.basex + (j * mlx.spc) + (j * mlx.dec) + (b.z * mlx.x));
			ft_bresen1(a, b, mlx.mlx, mlx.win);
		}
		i++;
	}
	return (0);
}

int		trace_line(t_env mlx)
{
	int			i;
	int			j;
	t_point		a;
	t_point		b;

	i = 0;
	while (i < mlx.len_y - 1)
	{
		j = -1;
		while (++j < mlx.len_x)
		{
			a.z = mlx.fdf[i][j] * mlx.coef_z;
			a.y = (mlx.basey - (j * mlx.spc) + (i * mlx.dec) - 2 * a.z * mlx.y);
			a.x = (mlx.basex + (j * mlx.spc) + (j * mlx.dec) + (a.z * mlx.x));
			i++;
			b.z = mlx.fdf[i][j] * mlx.coef_z;
			b.y = (mlx.basey - (j * mlx.spc) + (i * mlx.dec) - 2 * b.z * mlx.y);
			b.x = (mlx.basex + (j * mlx.spc) + (j * mlx.dec) + (b.z * mlx.x));
			ft_bresen1(a, b, mlx.mlx, mlx.win);
			i--;
		}
		i++;
	}
	return (0);
}
