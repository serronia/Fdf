/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   bonus.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jdarko <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/30 16:24:18 by jdarko       #+#   ##    ##    #+#       */
/*   Updated: 2018/05/02 15:07:55 by jdarko      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

char	**ft_error(char *line)
{
	char	**split;
	int		i;
	int		j;

	split = ft_strsplit(line, ' ');
	i = 0;
	while (split[i] != '\0')
	{
		j = 0;
		while (split[i][j] != '\0')
		{
			if ((split[i][j] < '0' || split[i][j] > '9') && split[i][j] != ' '
					&& split[i][j] != '\0' && split[i][j] != '\n' &&
					split[i][j] != '-' && (split[i][j] == ',' &&
						(split[i][j - 1] < '0' || split[i][j] > '9')) &&
					split[i][j] != 'x' && split[i][j] != 'F')
			{
				ft_putstr("error\n");
				exit(0);
			}
			j++;
		}
		i++;
	}
	return (split);
}

void	ft_str_int_del(int **as)
{
	if (!as || !*as)
		return ;
	free(*as);
	*as = NULL;
}

int		free_fdf(t_env **mlx)
{
	int i;

	i = 0;
	while (i < (*mlx)->len)
	{
		free((*mlx)->fdf[i]);
		i++;
	}
	free((*mlx)->fdf);
	return (0);
}

int		bonus_key(int key, t_env *mlx)
{
	if (key == 53 && mlx != NULL)
	{
		free_fdf(&mlx);
		exit(0);
	}
	if (key == 24 && mlx != NULL)
		mlx->coef_z = mlx->coef_z + 1;
	if (key == 27 && mlx != NULL)
		mlx->coef_z = mlx->coef_z - 1;
	if (key == 123 && mlx != NULL)
		mlx->basex = mlx->basex - 5;
	if (key == 126 && mlx != NULL)
		mlx->basey = mlx->basey - 5;
	if (key == 124 && mlx != NULL)
		mlx->basex = mlx->basex + 5;
	if (key == 125 && mlx != NULL)
		mlx->basey = mlx->basey + 5;
	if (key == 48 && mlx != NULL)
		*mlx = init_struct(*mlx);
	bonus_key_2(key, mlx);
	mlx_clear_window(mlx->mlx, mlx->win);
	trace_column(*mlx);
	trace_line(*mlx);
	return (0);
}

int		bonus_key_2(int key, t_env *mlx)
{
	if (key == 30 && mlx != NULL)
		mlx->spc = mlx->spc - 2;
	if (key == 33 && mlx != NULL)
		mlx->spc = mlx->spc + 2;
	if (key == 13 && mlx != NULL)
		mlx->y = mlx->y + 2;
	if (key == 0 && mlx != NULL)
		mlx->x = mlx->x - 2;
	if (key == 1 && mlx != NULL)
		mlx->y = mlx->y - 2;
	if (key == 2 && mlx != NULL)
		mlx->x = mlx->x + 2;
	if (key == 6 && mlx != NULL)
		mlx->dec = mlx->dec + 2;
	if (key == 7 && mlx != NULL)
		mlx->dec = mlx->dec - 2;
	return (0);
}
