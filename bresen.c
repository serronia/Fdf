/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   bresen.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jdarko <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/30 16:20:02 by jdarko       #+#   ##    ##    #+#       */
/*   Updated: 2018/05/02 11:07:15 by jdarko      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

t_bresen	ft_init_bresen(t_point a, t_point b)
{
	t_bresen	point;

	point.dx = fabs((double)(b.x - a.x));
	point.dy = fabs((double)(b.y - a.y));
	if (a.x < b.x)
		point.sx = 1;
	else
		point.sx = -1;
	if (a.y < b.y)
		point.sy = 1;
	else
		point.sy = -1;
	if (point.dx > point.dy)
		point.err = point.dx / 2;
	else
		point.err = -point.dy / 2;
	return (point);
}

void		ft_bresen1(t_point a, t_point b, void *mlx, void *win)
{
	int			e2;
	t_bresen	point;

	point = ft_init_bresen(a, b);
	while (1)
	{
		if (a.x == b.x && a.y == b.y)
			break ;
		mlx_pixel_put(mlx, win, a.x, a.y, 0xFFFFFF * (a.z + b.z) * 240
		+ 0xFFFFFF);
		e2 = point.err;
		if (e2 > -point.dx)
		{
			point.err = point.err - point.dy;
			a.x += point.sx;
		}
		if (e2 < point.dy)
		{
			point.err = point.err + point.dx;
			a.y += point.sy;
		}
	}
}
